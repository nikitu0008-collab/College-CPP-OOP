#include <iostream>
#include <string>
#include <vector>
class Planet{
    unsigned int mass_, col_sputnik_;
    std::string structure_atmosfer_, name_planet_;
    float pressure_surface_;
    public:
    //*It's a construction and parametrs
    Planet(std::string name_planet_, unsigned int mass_, unsigned int col_sputnik_, std::string structure_atmosfer_, float pressure_surface_){
        this->name_planet_ = name_planet_;
        this->mass_ = mass_;
        this->col_sputnik_ = col_sputnik_;
        this->structure_atmosfer_ = structure_atmosfer_;
        this->pressure_surface_ = pressure_surface_;
    }
    void printInfo(){
        std::cout << name_planet_ << ":" << std::endl;
        std::cout << "      Mass: " << mass_ << std::endl;
        std::cout << "      Structure atmosfer: " << structure_atmosfer_ << std::endl;
        std::cout << "      Pressure surface: " << pressure_surface_ << std::endl;
        std::cout << "      Col sputnik: " << col_sputnik_ << std::endl;
    }
};
int main(){
    Planet p1("Earth", 0, 1, "A, A", 2.22);
    Planet p2("Neptun", 10, 5, "Azot, Amogus", 1.23);
    Planet p3("MyPensil", 9999, 5, "Diamond, Beef, SUS", 1000);
    Planet p4("Lyna", 1023, 5, "Lyni", 1);
    p1.printInfo();
    p2.printInfo();
    p3.printInfo();
    p4.printInfo();
    return EXIT_SUCCESS;
}