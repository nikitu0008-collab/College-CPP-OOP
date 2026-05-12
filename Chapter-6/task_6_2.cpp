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

    [[nodiscard]] auto getName() const -> std::string {
        if (name_.empty()) {
            throw std::runtime_error("Name empty");
        }
        return name_;
    }

    [[nodiscard]] auto getState() const -> std::string {
        if (answer_state_ == "state") {
            return "state";
        } else if (answer_state_ == "private") {
            return "private";
        } else {
            throw std::runtime_error("Error state");
        }
    }

    [[nodiscard]] auto getIncome() const -> long double {
        if (answer_state_ == "state"){
            throw std::runtime_error("hidden");
        }
        if (answer_state_ == "private" and income_ < 5000000){
            throw std::runtime_error("hidden");
        }
        return income_;
    }

    [[nodiscard]] auto getExpenses() const -> long double {
        if (answer_state_ == "state"){ 
            throw std::runtime_error("hidden"); 
        }
        else if (answer_state_ == "private" and income_ < 5000000){ 
            throw std::runtime_error("hidden"); 
        } else {
            throw std::invalid_argument("Error");
        }
        return expenses_;
    }

    [[nodiscard]] auto getNetProfit() const -> long double {
        if (answer_state_ == "state"){ throw std::runtime_error("hidden"); }
        if (answer_state_ == "private" and income_ < 5000000){ throw std::runtime_error("hidden"); }
        return income_ - expenses_;
    }

    [[nodiscard]] auto getTurnover() const -> long double {
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
auto main() -> int {
    uint16_t answer = 0, index = 0;
    std::string answer_state, name; 
    unsigned int income = 0, expenses = 0;
    std::vector<Company> company = {
        Company("private", "A", 499999, 1000555),
        Company("state", "B", 1000, 1000000),
        Company("private", "C", 10, 15),
        Company("state","A",5000001,5000010)
    };
    while(answer != 6){
        std::print("\n\t1.Print   2.RedactorCompany\n\t3.AddCompany    4.Delete Company\n\t5.Calculation   6.Exit\n:_<");
        std::cin >> answer;
        switch(answer){
            case 1:
            if(company.empty()){ std::println("vector company empty"); continue; }
            for (const Company& i : company) {
                std::string state, name;
                try {
                    state = i.getState();
                    name = i.getName();
                } catch (const std::exception& e) {
                    std::println("Error: {}", e.what());
                    continue;
                }

                std::string income_str;
                try {
                    long double inc = i.getIncome();
                    income_str = std::to_string(inc);
                } catch (const std::runtime_error& e) {
                    income_str = (std::string(e.what()) == "hidden") ? "hidden" : "error";
                }

                std::string expenses_str;
                try {
                    long double exp = i.getExpenses();
                    expenses_str = std::to_string(exp);
                } catch (const std::runtime_error& e) {
                    expenses_str = (std::string(e.what()) == "hidden") ? "hidden" : "error";
                }
                std::println("State: {}\n\tName: {}\n\tIncome: {}\n\tExpenses: {}",
                         state, name, income_str, expenses_str);
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
            for (const Company& i : company) {
                try {
                    long double calculate = i.getNetProfit();
                    std::println("{}", calculate);
                } catch (const std::runtime_error& e) {
                    std::println("{}", e.what());
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
