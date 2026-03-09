#include <iostream>
#include <string>
#include <vector>
class Planet{
    std::string name_planet;
    unsigned int age_planet; 
    int temperature;
    public:
    //*It's a construction and parametrs
    Planet(std::string name_planet, unsigned int age_planet, int temperature){
        this->name_planet = name_planet;
        this->age_planet = age_planet;
        this->temperature = temperature;
    }
    void printInfo(){
        std::cout << "Planet: " <<name_planet << std::endl;
        std::cout << "Age: " << age_planet << std::endl;
        std::cout << "Temperature: " << temperature << std::endl;
    }
};
int main(){
    Planet p1("Earth",2500,25);
    Planet p2("Neptun",12345,-50);
    Planet p3("Mars", 54321, -500);
    p1.printInfo();
    p2.printInfo();
    p3.printInfo();
    return EXIT_SUCCESS;
}