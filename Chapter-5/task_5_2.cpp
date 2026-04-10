#include <print>
#include <cstdlib>
#include <iostream>
#include <utility> //* std::unreachable()
#include <vector>
#include <string>
class Worker{
    public:
    //*constructor standart
    Worker() :id_{0}, age_{0}, name_{"unknown-name"}, gender_{"unknown-gen"}, position_{"unknown-pos"}, department_{"unknown-dep"} {}
    
    //*delegating constructor
    Worker(unsigned int id) : Worker() {id_ = id;}
    Worker(unsigned int id, unsigned int age) : Worker(id) {age_ = age;}
    Worker(unsigned int id, unsigned int age, std::string gender) : Worker(id, age) {gender_ = gender;}
    Worker(unsigned int id, unsigned int age, std::string gender, std::string department) : Worker(id, age, gender) {department_ = department;}
    
    auto  printWorker() noexcept ->  void {
        std::println("Name: {}\nID:{}\nAge:{}\nGender:{}\nPosition:{}\nDepartment:{}", name_, id_, age_, gender_, position_, department_);
    }
    auto redactorWorker() -> void{
        unsigned int id_redactor;
        std::println("Enter ID redactor: ");
        std::cin >> id_redactor;
        std::println("Enter redactor new: ID, Age, Name, Gender, Position, Department");
        //? What Error's.
        std::cin >> id_ >> age_ >> name_ >> gender_ >> position_ >> department_;
    }
    auto addWorker() noexcept -> void{
        std::println("Enter New(ID, Age, Name, Gender, Position, Department)");
        std::cin >> id_ >> age_ >> name_ >> gender_ >> position_ >> department_;
    }
    ~Worker(){
        std::println("Worker [{}]{} deleted..",id_,  name_);
    }
    //*Thanks to protected, you can access them in inheritance
    protected:
    unsigned int id_, age_;
    std::string name_, gender_, position_, department_;
};
//*Static function
auto emptyVector(std::vector<Worker>& worker) -> void {
    if(worker.empty()){
        std::println("vector worker empty");
        return;
    }
}
auto main() -> int {
    std::vector<Worker> worker;
    unsigned int answer = 0;
    int id_delete;
    bool answer_num = false;
    while(answer != 5){
        std::print("Worker:\n\t1.print\n\t2.redactor\n\t3.add\n\t4.delete\n\t5.exit\n:_>");
        std::cin >> answer;
        (answer > 0 && answer < 6) ? answer_num = true : false;
        if(!answer_num){
            std::cerr << "Error answer" << std::endl;
        } 
        switch(answer){
            case 1: 
            emptyVector(worker);
            for(Worker& i : worker){i.printWorker();} 
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
            if(id_delete < 0 || id_delete > worker.size()){ 
                std::println("index error!");
                continue;
            }
            worker.erase(worker.begin() + id_delete); 
            break;
            case 5: /*Destruction*/ break;
            default: std::unreachable(); //*saying compiler that we definitely won't get here.
        }
    }
    return EXIT_SUCCESS;
}