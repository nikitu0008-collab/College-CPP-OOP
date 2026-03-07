#include <iostream>
#include <string>
#include <vector>

class Student{
    std::string name, class_studies;
    unsigned int age; 
    int* unique_number_students; //*it's a destruction.
    public:
        Student(){
            unique_number_students = new int(0);
            std::cout << "student's created"
        }
    //*Constructor from default.
    Student(){
        age = 0; unique_number_students = 0;
    }

    void redactor_students(){

    }
    void print_information(){
        
    }
};

int main(){
    unsigned int col_students = 0;
    std::vector<Student> student;
    std::cout << "Enter col students\n:_>";
    std::cin >> col_students;
    
    return EXIT_SUCCESS;
}