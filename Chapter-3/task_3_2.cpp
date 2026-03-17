#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <print>
class Student{
    private:
    //*Initialization
    unsigned int age_, indetificator_;
    std::string classing_, name_;
    public:
    //*Constructor standart
    Student() : age_(0), indetificator_(0), classing_("null"), name_("unknown") {}
    //*Constructor
    Student(unsigned int age, unsigned int indetificator, std::string classing, std::string name){
        age_ = age, indetificator_ = indetificator;
        classing_ = classing, name_ = name;
    }
    auto redactorStudents() -> void{
        std::println("indetificator: ");std::cin >> indetificator_;
        std::println("name: ");std::cin >> name_;
        std::println("age: ");std::cin >> age_;
        std::println("class: ");std::cin >> classing_;
    }
    auto printInformation() -> void{
            std::println("\n.Student #-{}",indetificator_);
            std::println("      {}",name_);
            std::println("      {}",age_);
            std::println("      {}",classing_);
        }
    //*Destruction.
    ~Student(){
        std::println("Student {} ({}) deleted", name_, indetificator_);
    }
};
auto main() -> int{
    unsigned int col_students = 0, answer = 0, serial_number = 0;
    std::println("Enter col students: ");
    std::cin >> col_students;
    std::vector<Student> students(col_students);
    while(answer != 2){
        for(int i = 0 ; i < students.size() ; i++){
            students[i].printInformation();
        }
        std::println("1. Redactor Student's\n2. Exit\n_>");
        std::cin >> answer;
        switch(answer){
            case 1:
            std::println("writing serial number list up(NOT ID)\n:_>");
            std::cin >> serial_number;
            students[serial_number].redactorStudents();
            break;
            case 2:
            std::println("Good bye!");
            //*The vector will delete the students automatically upon destruction.
            break;
            default:
            throw std::invalid_argument("Invalid signal value"); //*Exception
            break;
        }
    }
    return EXIT_SUCCESS;
}