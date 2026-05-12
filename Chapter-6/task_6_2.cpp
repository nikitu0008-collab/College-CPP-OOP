#include <cstdlib>
#include <string>
#include <print>
#include <iostream>
#include <vector>
#include <cstdint>
#include <exception>
#include <stdexcept>
class Company{
    public:
    Company(std::string answer_state, std::string name,unsigned int income,unsigned int expenses) : answer_state_(answer_state), name_(name), income_(income), expenses_(expenses) {}
    Company() : answer_state_("unknown-state"), name_{"unknown-name"}, income_(0), expenses_(0) {}

    [[nodiscard]] auto getName() const -> std::string{
        return name_;
    }
    [[nodiscard]] auto getState() const -> std::string{
        if(answer_state_ == "state"){
            return "state";
        } else if(answer_state_ == "private"){
            return "private";
        } else { 
            throw std::runtime_error("state error");
            }
    }

    [[nodiscard]] auto getIncome() const -> std::string {
        if(answer_state_ == "state"){
            return "hidden";
        } else if(answer_state_ == "private" and income_ < 5000000){
            return "hidden";
            } else {
                return std::to_string(income_);
            }
    }
    [[nodiscard]] auto getExpenses() const -> std::string{
        if(answer_state_ == "state"){
            return "hidden";
        } else if(answer_state_ == "private" and income_ < 5000000){
            return "hidden";
        } else {
            return std::to_string(expenses_);
        }
    }
    //чистая прибыль
    [[nodiscard]] auto getNetProfit() const -> std::string{
        if(answer_state_ == "state"){
            return "hidden";
        } else {
            return std::to_string(income_ - expenses_); 
            }
    }
    //оборот
    [[nodiscard]] auto getTurnover() const -> long double{
        return income_ + expenses_; 
    } 
    auto setName(std::string name) -> Company& { name_ = name; return *this;}
    auto setIncome(unsigned int income) -> Company& { income_ = income; return *this;}
    auto setExpenses(unsigned int expenses) -> Company& { expenses_ = expenses; return *this;}

    auto redactorCompany() -> void {
        std::print("Enter new name: ");
        std::cin.ignore(1024, '\n');
        std::getline(std::cin, name_);
        std::print("Enter new income and expenses: ");
        std::cin >> income_ >> expenses_;
        try{
        if(income_ < 0 or expenses_ < 0) { throw std::runtime_error("Income or expenses <= 0"); }
        }catch(const std::exception& e){
            std::println("{}", e.what());
        }
    }

    private:
        std::string answer_state_, name_;
        unsigned int income_, expenses_;
};
static auto checkState(std::vector<Company>& company)->bool{
    for(const Company& i : company){
        if(i.getState() == "state"){
            return true;
        } else if(i.getState() == "private"){
            return false;
        } else {
            throw std::runtime_error("Error check state");
        }
    }
}
auto main() -> int {
    uint16_t answer = 0, index = 0;
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
            if(company.empty()){ std::println("vector company empty"); continue; }
            for(const Company& i : company){
                if(checkState(company)){
                    std::println("State: {}\n\tName:{}\n\tIncome: hidden\n\tExpenses: hidden", i.getState(), i.getName());
                } else {
                    std::println("State: {}\n\tName:{}\n\tIncome:{}\n\tExpenses:{}",
                        i.getState(), i.getName(), i.getIncome(), i.getExpenses()
                    );
                }
            }
            break;
            case 2:
            if(company.empty()){std::println("vector company empty"); continue; }
            std::print("Enter index redactor: ");
            std::cin >> index;
            if(index >= company.size()){
                std::cerr << "Error index" << std::endl;
                continue;
            }
            company.at(index).redactorCompany();
            break;
            case 3:
            std::println("state or private company?");
            std::cin >> answer_state;
            if (answer_state == "State" or answer_state == "state") {
                answer_state = "state";
            } else if (answer_state == "Private" or answer_state == "private") {
                answer_state = "private";
            } else {
                throw std::runtime_error("unknown state");
            }

            std::println("Enter name: ");
            std::cin.ignore(1024, '\n');
            std::getline(std::cin, name);
            
            std::println("Enter income and expenses: ");
            std::cin >> income >> expenses;

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
                if(checkState(company)){
                    //forbidden -- запрещено(перевод)
                    std::println("Calculation forbidden");
                    continue;
                } else if(!checkState(company)){
                    std::println("Company: {}, calculation: {}",i.getName(), i.getNetProfit());
                } else {
                    throw std::runtime_error("Invalid state");
                }
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
/*ИСПРАВИТЬ:
 *  1.Убрать выделение целой строки исправить под bool
 *  2.исправить runtime_error
 *  3.long double на std::string
 */
