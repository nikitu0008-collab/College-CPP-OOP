#include <string>
#include <cstdint>
#include <cstdlib>
#include <print>
#include <iostream>
#include <utility>
#include <vector>

class Student{
    public:
        //clangd recomended adding std::move(name) ...
        Student(std::string name, std::string gender, uint16_t age, std::string class_room) 
            : id_(amount_of_students_++), name_(name), gender_(gender), age_(age), class_room_(class_room){}
        
        [[nodiscard]] auto getId() const -> uint16_t { return id_; }
        [[nodiscard]] auto getAge() const -> uint16_t { return age_; }
        [[nodiscard]] auto getName() const -> std::string { return name_; }
        [[nodiscard]] auto getClassRoom() const -> std::string { return class_room_; }
        [[nodiscard]] auto getGender() const -> std::string { return gender_; }
       
        constexpr auto printInfo() const noexcept -> void{
            std::println(
                    "[1]ID: {}\n"
                    "[2]Name: {}\n"
                    "[3]Age: {}\n"
                    "[4]Class-Room: {}\n"
                    "[5]Gender: {}\n",
                    id_, name_, age_, class_room_, gender_
                    );
        }
        auto redactor()->void{
            std::println("Enter new name: ");
            std::cin.ignore(1024, '\n');
            std::getline(std::cin, name_);
            std::println("Enter new age_, class_room_, gender_");
            std::cin >> age_ >> class_room_ >> gender_;
        }
        ~Student(){}  
    private:
        static uint16_t amount_of_students_; 
        uint16_t id_, age_;
        std::string name_, class_room_, gender_;
};

uint16_t Student::amount_of_students_ = 0;

auto main()->int{
    char answer = 0;
    std::string class_room, gender, name;
    uint16_t id = 0, age = 0, amount = 0, index = 0, field_sort = 0;
    std::vector<Student> student{
        Student("3","3",3,"3"),
        Student("1","1",1,"1"),
        Student("2","2",2,"2")
    };
    for(const Student& i : student){
        i.printInfo();
    }
    while(answer != '5'){
        std::print("\n"
                "1.Adding\n"
                "2.Delete\n"
                "3.Redactor\n"
                "4.Print All Students\n"
                "5.Exit\n"
                ":_>"
                );
        std::cin >> answer;
        switch(answer){
            case '1':
            std::println("Enter name: ");
            std::cin.ignore(1024, '\n');
            std::getline(std::cin, name);
            std::print(
                "Enter new (name, gender, age, class-room)\n"
                ":_>"
                );
            
            std::cin >> gender >> age >> class_room;
            student.emplace_back(name, gender, age, class_room);
            for(const Student& i : student){
                i.printInfo();
            }
            break;
            case '2':
            if(student.empty()){std::println("===EMPTY VECTOR==="); continue;}
            std::print("Enter index delete students: ");
            std::cin >> index;
            if(index >= student.size()){
                std::cerr << "Index > size vector" << std::endl;
                continue;
            }
            student.erase(student.begin() + index);
            break;
            case '3':
            if(student.empty()){std::println("===VECTOR EMPTY==="); continue;}
            std::print("Enter index redactor: ");
            std::cin >> index;
            if(index >= student.size()){
                std::cerr << "Index >= size vector" << std::endl;
                 continue;
            }
            student.at(index).redactor();
            for(const Student& i : student){
                i.printInfo();
            }
            break;
            case '4':
            if(student.empty()){std::println("===EMPTY===");continue;}
            std::print("1.print sorted\n2.print not sorted");
            std::cin >> answer;
            if(answer == '1'){
                std::print("Enter field sort: ");
                std::cin >> field_sort;
                //field_sort type uint16_t
                if(field_sort > 5){ std::cerr << "Error field" << std::endl; continue; }
                for(size_t i = 0 ; i < student.size() - 1 ; i++){
                    for(size_t j = 0 ; j < student.size() - i - 1 ; j++){
                        switch(field_sort){
                            case 1:
                            if(student.at(j).getId() > student.at(j + 1).getId()){std::swap(student.at(j), student.at(j+1));}
                            break;
                            case 2:
                            if(student.at(j).getName() > student.at(j + 1).getName()){std::swap(student.at(j), student.at(j+1));}
                            break;
                            case 3:
                            if(student.at(j).getAge() > student.at(j + 1).getAge()){std::swap(student.at(j), student.at(j+1));}
                            break;
                            case 4:
                            if(student.at(j).getClassRoom() > student.at(j + 1).getClassRoom()){std::swap(student.at(j), student.at(j+1));}
                            break;
                            case 5:
                            if(student.at(j).getGender() > student.at(j + 1).getGender()){std::swap(student.at(j), student.at(j+1));}
                            break;
                            default:
                            std::cerr << "===SORT ERROR===" << std::endl;
                            break;
                        }
                    }
                }
                for(const Student& i : student){
                    i.printInfo();
                }
            } else if(answer == '2'){
                for(const Student& i : student){
                    i.printInfo();
                }
            } else {
                std::cerr << "answer print error!" << std::endl;
                continue;
            }
            break;
            case '5':
            std::println("===EXIT===");
            break;
            default:
            std::cerr << "Error!" << std::endl;
            break;
        }
    }
    return EXIT_SUCCESS;
}
