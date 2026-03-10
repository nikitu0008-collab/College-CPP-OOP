#include <iostream>
#include <string>
#include <vector>
class Student{
    unsigned int age_, indetificator_;
    std::string classing_ = "null", name_ = "unknown";
    public:
    void redactorStudents(){
        std::cout << "indetificator: " << std::endl; std::cin >> indetificator_;
        std::cout << "name: " << std::endl; std::cin >> name_;
        std::cout << "age: " << std::endl; std::cin >> age_;
        std::cout << "class: " << std::endl; std::cin >> classing_;
    }
    void printInformation(){
            std::cout << "\n.Student #-" << indetificator_ << std::endl;
            std::cout << "      " << name_ << std::endl;
            std::cout << "      " << age_ << std::endl;
            std::cout << "      " << classing_ << std::endl;
        }
    //*Destruction.
    ~Student(){
        std::cout << "Student " << name_ << "(" << indetificator_ << ") deleted" << std::endl;
    }
};
int main(){
    unsigned int col_students = 0, answer = 0, serial_number = 0;
    std::cout << "Enter col students: ";
    std::cin >> col_students;
    std::vector<Student> students(col_students);
    while(answer != 2){
        for(int i = 0 ; i < students.size() ; i++){
            students[i].printInformation(col_students);
        }
        std::cout << "1. Redactor Student's\n2. Exit\n_>";
        std::cin >> answer;
        switch(answer){
            case 1:
            std::cout << "writing serial number list up(NOT ID)\n:_>";
            std::cin >> serial_number;
            students[serial_number].redactorStudents();
            break;
            case 2:
            std::cout << "Good bye!" << std::endl;
            for(int i = 0 ; i < students.size() ; i++){
                students;
            }
            break;
            default:
            std::cerr << "Error's writing" << std::endl;
            break;
        }
    }
    return EXIT_SUCCESS;
}