#include <print>
#include <cstdlib>
#include <iostream>
#include <utility> //* std::unreachable()
#include <vector>
#include <stdexcept>
#include <string>
#include <cstdint>
class Worker{
    public:
    //*constructor standart
    Worker() : id_(0), age_(0), name_("unknown-name"), gender_("unknown-gen"), position_("unknown-pos"), department_("unknown-dep") {}
    
    //*delegating constructor
    Worker(unsigned int id) : Worker() {id_ = id;}
    Worker(unsigned int id, unsigned int age) : Worker(id) {age_ = age;}
    Worker(unsigned int id, unsigned int age, std::string gender) : Worker(id, age) {gender_ = gender;}
    Worker(unsigned int id, unsigned int age, std::string gender, std::string department) : Worker(id, age, gender) {department_ = department;}
    
    auto constexpr printWorker() const noexcept ->  void {
        std::println("Name: {}\nID:{}\nAge:{}\nGender:{}\nPosition:{}\nDepartment:{}", name_, id_, age_, gender_, position_, department_);
    }
    auto redactorWorker() -> void{
        uint16_t id_redactor;
        std::println("Enter ID redactor: ");
        std::cin >> id_redactor;
        std::println("Enter redactor new: ID, Age, Name, Gender, Position, Department");
        std::cin >> id_ >> age_ >> name_ >> gender_ >> position_ >> department_;
    }
    auto addWorker() noexcept -> void{
        std::println("Enter New(ID, Age, Name, Gender, Position, Department)");
        std::cin >> id_ >> age_ >> name_ >> gender_ >> position_ >> department_;
    }
    private:
    uint16_t id_, age_;
    std::string name_, gender_, position_, department_;
};
//*Static function
auto emptyVector(std::vector<Worker>& worker) noexcept -> void {
    if(worker.empty()){
        std::println("vector worker empty");
        return;
    }
}
auto main() -> int {
    std::vector<Worker> worker;
    uint16_t answer = 0, id_delete = 0;
    bool answer_num = false;
    while(answer != 5){
        std::print("Worker:\n\t1.print\n\t2.redactor\n\t3.add\n\t4.delete\n\t5.exit\n:_>");
        std::cin >> answer;
        if(answer > 0 && answer < 6){ answer_num = true; }
        
        if(!answer_num){
            throw std::invalid_argument("Error answer");
        } 
        switch(answer){
            case 1: 
            emptyVector(worker);
            for(const Worker& i : worker){i.printWorker();} 
            break;
            case 2: 
            emptyVector(worker);for(Worker& i : worker){i.redactorWorker();} 
            break;
            case 3:{
            Worker newWorker;
            newWorker.addWorker();
            worker.push_back(std::move(newWorker));
            break;
            }
            case 4: 
            emptyVector(worker); 
            std::println("Enter index: "); std::cin >> id_delete; 
            if(id_delete >= worker.size()){ 
                throw std::invalid_argument("Index error");
            }
            worker.erase(worker.begin() + id_delete); 
            break;
            case 5: std::println("Bye.."); break;
            default: std::unreachable(); //*saying compiler that we definitely won't get here.
        }
    }
    return EXIT_SUCCESS;
}
