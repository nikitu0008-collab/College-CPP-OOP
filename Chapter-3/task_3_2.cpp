#include <iostream>
#include <string>
#include <vector>
class Student{
    unsigned int age, indetificator;
    std::string classing = "null", name = "unknown";
    public:
    void redactorStudents(){
        std::cin >> indetificator;
        std::cin >> name;
        std::cin >> age;
        std::cin >> classing;
    }
    void printInformation(){
            std::cout << "\n.Student #-" << indetificator << std::endl;
            std::cout << "      " << name << std::endl;
            std::cout << "      " << age << std::endl;
            std::cout << "      " << classing << std::endl;
    }
    ~Student(){
        std::cout << "Student " << name << "(" << indetificator << ") deleted" << std::endl;
    }
};
int main(){
    unsigned int col_students = 0, answer = 0, serial_number = 0;
    std::cout << "Enter col students: ";
    std::cin >> col_students;
    std::vector<Student> students(col_students);
    while(answer != 2){
        for(int i = 0 ; i < col_students ; i++){
            students[i].printInformation();
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
            for(int i = 0 ; i < col_students ; i++){
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