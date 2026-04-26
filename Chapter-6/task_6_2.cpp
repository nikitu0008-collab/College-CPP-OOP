#include <cstdlib>
#include <stdexcept>
#include <string>
#include <print>
#include <iostream>
#include <vector>
#include <cstdint>

class Company{
    public:
    //*Construction
    Company(std::string& answer_state, std::string& name,unsigned int income,unsigned int expenses) : answer_state_(answer_state), name_(name), income_(income), expenses_(expenses) {}
    Company() : answer_state_("unknown-state"), name_{"unknown-name"}, income_(0), expenses_(0) {}

    //*Get
    [[nodiscard]] auto getFState() const -> std::string { return answer_state_; }
    [[nodiscard]] auto getFName() const -> std::string { return name_; }
    [[nodiscard]] auto getFIncom() const -> unsigned int { return income_; }
    [[nodiscard]] auto getFExpenses() const -> unsigned int { return expenses_; }
    
    //*Set. I'm creating optimal setter, recomended from teacher
    auto setFs(std::string& answer_state) -> Company& { answer_state_ = answer_state; return *this;}
    auto setFn(std::string& name) -> Company& { name_ = name; return *this;}
    auto setFi(unsigned int income) -> Company& { income_ = income; return *this;}
    auto setFe(unsigned int expenses) -> Company& { expenses_ = expenses; return *this;}

    auto redactorCompany() -> void {
        std::print("Enter new name, income and expenses: ");
        std::cin >> name_ >> income_ >> expenses_;
    }

    private:
        std::string answer_state_, name_;
        unsigned int income_, expenses_;
};
static auto emptyVector(const std::vector<Company>& c) -> bool{
    return c.empty();
}
auto main() -> int {
    uint16_t answer = 0, index = 0;
    int result = 0;
    std::string answer_state, name; 
    unsigned int income = 0, expenses = 0;
    std::vector<Company> company = {
        //Если надо добавить какие-то значение изначально то ок.
        //Пока что незнаю.
    };
    while(answer != 6){
        std::print("\n\t1.Print   2.RedactorCompany\n\t3.AddCompany    4.Delete Company\n\t5.Calculation   6.Exit\n:_<");
        std::cin >> answer;
        switch(answer){
            case 1:
            if(emptyVector(company)){ std::println("vector empty"); continue; }
            for(const Company& i : company){
                if(i.getFState() == "private" and i.getFIncom() < 5000000){
                    std::println("\nStatus: {}\nName-hidden\nIncome: {}\nExpeses: {}", i.getFState(), i.getFIncom(), i.getFExpenses());
                } else if(i.getFState() == "state"){
                    if(i.getFIncom() < 5000000){
                        std::println("\nName company: {}\n Income: hidden\nExpeses: hiddden",i.getFName());        
                    } else if(i.getFIncom() >= 5000000){
                            std::println("\nName company: {}\nIncome: {}\nExpenses: {}", i.getFName(), i.getFIncom(), i.getFExpenses());
                        }
                } else if(i.getFState() == "unknown-state"){
                    throw std::invalid_argument("Error state unknown");
                    } else {
                        throw std::invalid_argument("Error state");
                    }
            }
            break;
            case 2:
            if(emptyVector(company)){std::println("vector empty"); continue; }
            std::print("Enter index redactor: ");
            std::cin >> index;
            if(index >= company.size()){
                throw std::invalid_argument("Error index");
            }
            company.at(index).redactorCompany();
            break;
            case 3:
            std::println("state or private company?\n:_>");
            std::cin >> answer_state;
            if(answer_state == "State" or answer_state == "state"){
                answer_state = "state";
            } else if(answer_state == "Private" or answer_state == "private"){
                    answer_state = "private";    
                } else {
                        answer_state = "unknown-state";
                    }
            std::println("Enter adding(name, income, expenses)");
            std::cin >> name >> income >> expenses;
            company.emplace_back(answer_state, name, income, expenses);
            break;
            case 4:
            if(emptyVector(company)){std::println("vector empty"); continue; }
            std::print("Enter index: ");
            std::cin >> index;
            if(index >= company.size()){
                throw std::invalid_argument("Error index");
            }
            company.erase(company.begin() + index);
            break;
            case 5:
            if(emptyVector(company)){std::println("vector empty"); continue; }
            for(const Company& i : company){
                if(i.getFState() == "state"){
                    //forbidden -- запрещено(перевод)
                    std::println("Calculation forbidden");
                    continue;
                }
                //clangd recomendent const int result. Но я не хочу, потому что результат всё равно будет менятся при новых знач.
                result = i.getFIncom() - i.getFExpenses(); 
                std::println("Company: {}, calculation: {}", i.getFName(), result);       
            }
            break;
            case 6:
            break;
            default:
            throw std::invalid_argument("Error default");
            }
        }
    return EXIT_SUCCESS;
}
/*
*У меня вместо unsigned я поставил int т.к рассходов может быть больше чем доходы
*и мы заметим разницу. т.к если бы unsigned то всегда было бы 0 и не < 0
*Но если надо, то будет unsigned тоесть(uint16_t)
*/
