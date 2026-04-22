#include <print>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <cstdint>
class Worker{
    public:
    //*delegating constructor
    explicit Worker(uint16_t id) : Worker() {id_ = id;}
    Worker(uint16_t id, uint16_t age) : Worker(id) {age_ = age;}
    Worker(uint16_t id, uint16_t age, const std::string& gender) : Worker(id, age) {gender_ = gender;}
    Worker(uint16_t id, uint16_t age, const std::string& gender, const std::string& department) : Worker(id, age, gender) {department_ = department;}
    Worker(uint16_t id, uint16_t age, const std::string& gender, const std::string& department, const std::string& position) : Worker(id,age,gender,department) { position_ = position;}
    Worker(uint16_t id, uint16_t age, const std::string& gender, const std::string& department, const std::string& position, const std::string& name) : Worker(id, age,gender,department, position) { name_ = name;}
    
    auto constexpr printWorker() const noexcept ->  void {
        std::println("\n\nName: {}\nID:{}\nAge:{}\nGender:{}\nPosition:{}\nDepartment:{}", name_, id_, age_, gender_, position_, department_);
    }
    auto redactorWorker() -> void{
        std::println("Enter redactor new: Age, Name, Gender, Position, Department");
        std::cin >> age_ >> name_ >> gender_ >> position_ >> department_;
    }
    auto addWorker() -> void{
        std::println("Enter New(Id, Age, Name, Gender, Position, Department)\n:_>");
        std::cin >> id_ >> age_ >> name_ >> gender_ >> position_ >> department_;
    }
    ~Worker() = default;
    private:
    //Private default constructor
    Worker() : id_(0), age_(0), name_("unknown-name"), gender_("unknown-gen"), position_("unknown-pos"), department_("unknown-dep") {}
    
    uint16_t id_, age_;
    std::string name_, gender_, position_, department_;
};
static auto emptyVector(const std::vector<Worker>& w) -> bool{
    if(!w.empty()){
        return w.empty();
    }
    return true;
}
auto main() -> int {
    std::vector<Worker> worker;
    worker.emplace_back(69,18,"Amogusik","I-Dont-Know","BIG","Deputation");
    worker.emplace_back(67,10,"MINI","MEN","MIN-and-BIG-POS","President");
    worker.emplace_back(300,16,"Billi-Haryngton","BOY","Gachi-Position","Big-Department");
    uint16_t answer = 0, id_delete = 0, index = 0;
    while(answer != 5){
        std::print("Worker:\n\t1.print\n\t2.redactor\n\t3.add\n\t4.delete\n\t5.exit\n:_>");
        std::cin >> answer;
        switch(answer){
            case 1:
            if(emptyVector(worker)) {std::println("Vector empty"); continue;} 
            for(const Worker& i : worker){i.printWorker();} 
            break;
            case 2:
            if(emptyVector(worker)) {std::println("Vector empty"); continue; }
            std::print("Enter index redactor worker: ");
            std::cin >> index;
            if(index >= worker.size()){
                throw std::invalid_argument("Error index redactor worker");
            }
            worker.at(index).redactorWorker();
            break;
            case 3:{
            uint16_t id = 0, age = 0;
            std::string name, gender, position, department;
            std::println("Enter New (ID Age Name Gender Position Department):");
            std::cin >> id >> age >> name >> gender >> position >> department;
            worker.emplace_back(id, age, name, gender, department, position);
            break;}
            case 4: 
            if(emptyVector(worker)){std::println("Vector empty"); continue; } 
            std::println("Enter index: "); std::cin >> id_delete; 
            if(id_delete >= worker.size()){ 
                throw std::invalid_argument("Index error");
            }
            worker.erase(worker.begin() + id_delete); 
            break;
            case 5: std::println("Bye.."); break;
            default: 
            throw std::invalid_argument("Enter Error");
        }
    }
    return EXIT_SUCCESS;
}
