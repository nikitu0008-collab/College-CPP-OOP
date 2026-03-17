#include <string>
#include <print>
class Planet{
    private:
    unsigned int mass_, col_sputnik_;
    std::string structure_atmosfer_, name_planet_;
    float pressure_surface_;
    public:
    //*It's a construction and parametrs
    Planet(std::string name_planet, unsigned int mass, unsigned int col_sputnik, std::string structure_atmosfer, float pressure_surface){
        this->name_planet_ = name_planet;
        this->mass_ = mass;
        this->col_sputnik_ = col_sputnik;
        this->structure_atmosfer_ = structure_atmosfer;
        this->pressure_surface_ = pressure_surface;
    }
    void printInfo(){
        std::println("{}",name_planet_);
        std::println("      Mass: {}", mass_);
        std::println("      Structure atmosfer: {}", structure_atmosfer_);
        std::println("      Pressure surface: {}", pressure_surface_);
        std::println("      Col sputnik: {}", col_sputnik_);
    }
};
auto main() -> int{
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