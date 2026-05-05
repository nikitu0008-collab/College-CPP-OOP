#include <cstdlib>
#include <string>
#include <print>
#include <iostream>
#include <vector>
#include <cstdint>
#include <exception>
class Company{
    public:
    //*Construction
    Company(std::string answer_state, std::string name,unsigned int income,unsigned int expenses) : answer_state_(answer_state), name_(name), income_(income), expenses_(expenses) {}
    Company() : answer_state_("unknown-state"), name_{"unknown-name"}, income_(0), expenses_(0) {}

    //*Get
    [[nodiscard]] auto getState() const -> const std::string& { return answer_state_; }
    [[nodiscard]] auto getName() const -> const std::string& { return name_; }
    [[nodiscard]] auto getIncom() const -> unsigned int { return income_; }
    [[nodiscard]] auto getExpenses() const -> unsigned int { return expenses_; }
    
    //*Set. I'm creating optimal setter, recomended from teacher
    auto setState(std::string& answer_state) -> Company& { answer_state_ = answer_state; return *this;}
    auto setName(std::string& name) -> Company& { name_ = name; return *this;}
    auto setIncome(unsigned int income) -> Company& { income_ = income; return *this;}
    auto setExpenses(unsigned int expenses) -> Company& { expenses_ = expenses; return *this;}

    auto redactorCompany() -> void {
        std::print("Enter new name, income and expenses: ");
        std::cin >> name_ >> income_ >> expenses_;
        try{
        if(income_ <= 0 or expenses_ <= 0) { throw "Income or expenses <= 0"; }
        }catch(const std::exception& e){
            std::println("{}", e.what());
        }
    }

    private:
        std::string answer_state_, name_;
        unsigned int income_, expenses_;
};

auto main() -> int {
    uint16_t answer = 0, index = 0;
    int result = 0;
    std::string answer_state, name; 
    unsigned int income = 0, expenses = 0;
    std::vector<Company> company = {
        Company("private", "Shnele", 499999, 1000875),
        Company("state", "AGY-AGY", 1000, 190002),
        Company("private", "NVIM", 11, 11),
        Company("state","A",5000001,5000010)
    };
    while(answer != 6){
        std::print("\n\t1.Print   2.RedactorCompany\n\t3.AddCompany    4.Delete Company\n\t5.Calculation   6.Exit\n:_<");
        std::cin >> answer;
        switch(answer){
            case 1:
            if(company.empty()){ std::println("vector empty"); continue; }
            for(const Company& i : company){
                if(i.getState() == "private" and i.getIncom() < 5000000){
                    std::println("\nStatus: {}\nName-hidden\nIncome: {}\nExpeses: {}", i.getState(), i.getIncom(), i.getExpenses());
                } else if(i.getState() == "private" and i.getIncom() > 499999){
                    std::println("\nStatus: {}\nName: {}\nIncome: {}\nExpeses: {}", i.getState(), i.getName(), i.getIncom(), i.getExpenses());
                } else if(i.getState() == "state"){
                    if(i.getIncom() < 5000000){
                        std::println("\nStatus: {}\nName company: {}\n Income: hidden\nExpeses: hiddden", i.getState(),i.getName());        
                    } else if(i.getIncom() >= 5000000){
                            std::println("\nStatus: {}\nName company: {}\nIncome: {}\nExpenses: {}", i.getState(), i.getName(), i.getIncom(), i.getExpenses());
                        }
                } else if(i.getState() == "unknown-state"){
                        std::cerr << "unknown-state" << std::endl;
                        continue;
                    } else {
                        std::cerr << "Error state" << std::endl;
                        continue;
                    }
            }
            break;
            case 2:
            if(company.empty()){std::println("vector empty"); continue; }
            std::print("Enter index redactor: ");
            std::cin >> index;
            if(index >= company.size()){
                std::cerr << "Error index" << std::endl;
                continue;
            }
            company.at(index).redactorCompany();
            break;
            case 3:
            try {
            std::println("state or private company?");
            std::cin >> answer_state;
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                break;
            }
            if (answer_state == "State" or answer_state == "state") {
                answer_state = "state";
            } else if (answer_state == "Private" or answer_state == "private") {
                answer_state = "private";
            } else {
                answer_state = "unknown-state";
            }

            std::println("Enter name, income, expenses:");
            std::cin >> name >> income >> expenses;

            company.emplace_back(answer_state, name, income, expenses);
            break;
            case 4:
            if(company.empty()){std::println("vector empty"); continue; }
            std::print("Enter index: ");
            std::cin >> index;
            if(index >= company.size()){
                std::cerr << "Error index" << std::endl;
                continue; 
            }
            company.erase(company.begin() + index);
            break;
            case 5:
            if(company.empty()){std::println("vector empty"); continue; }
            for(const Company& i : company){
                if(i.getState() == "state"){
                    //forbidden -- запрещено(перевод)
                    std::println("Calculation forbidden");
                    continue;
                }
                //clangd recomendent const int result. Но я не хочу, потому что результат всё равно будет менятся при новых знач.
                result = i.getIncom() - i.getExpenses(); 
                std::println("Company: {}, calculation: {}", i.getName(), result);       
            }
            break;
            case 6:
            break;
            default:
                std::cerr << "Error answer" << std::endl;
            }
        }
    return EXIT_SUCCESS;
}
/*
*У меня вместо unsigned я поставил int т.к рассходов может быть больше чем доходы
*и мы заметим разницу. т.к если бы unsigned то всегда было бы 0 и не < 0
*Но если надо, то будет unsigned тоесть(uint16_t)
*/
