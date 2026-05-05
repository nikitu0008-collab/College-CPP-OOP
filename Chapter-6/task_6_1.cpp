#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <print>
#include <vector>
#include <string>
class Planet {
public:
    Planet(){};
    Planet(unsigned int mass, unsigned int col_sputnik, std::string structure_atmosfer, std::string name_planet, double pressure_surface) : mass_(mass), col_sputnik_(col_sputnik), structure_atmosfer_(structure_atmosfer), name_planet_(name_planet), pressure_surface_(pressure_surface) {}
    
    auto setNamePlanet(const std::string& name_planet)->Planet&{ name_planet_ = name_planet; return *this;}
    auto setMass(unsigned int mass)->Planet& { mass_ = mass; return *this;}
    auto setColSputnik(unsigned int col_sputnik)->Planet&{ col_sputnik_ = col_sputnik; return *this;}
    auto setStructureAtmosfer(const std::string& structure_atmosfer)->Planet&{ structure_atmosfer_ = structure_atmosfer; return *this;}
    auto setPressureSurface(double pressure_surface)->Planet&{ pressure_surface_ = pressure_surface; return *this; }

    [[nodiscard]] auto getName() const -> const std::string& { return name_planet_; }
    [[nodiscard]] auto getMass() const -> unsigned int { return mass_; }
    [[nodiscard]] auto getColSputnik() const -> unsigned int { return col_sputnik_; }
    [[nodiscard]] auto getStructureAtmosfer() const -> const std::string& { return structure_atmosfer_; }
    [[nodiscard]] auto getPressureSurface() const -> double { return pressure_surface_; }
    
    auto constexpr printInfo() const noexcept -> void {
      std::println("1.{}", name_planet_);
      std::println("      2.Mass: {}", mass_);
      std::println("      3.Structure atmosfer: {}", structure_atmosfer_);
      std::println("      4.Pressure surface: {}", pressure_surface_);
      std::println("      5.Col sputnik: {}", col_sputnik_);
    }

private:
    unsigned int mass_, col_sputnik_;
    std::string structure_atmosfer_, name_planet_;
    double pressure_surface_;
};
auto main() -> int {
    unsigned int field = 0;
    std::vector<Planet> p = {
       Planet(350000,50,"Apple","NplDig",25.66),
       Planet(150900,1000, "Pensil", "AAME",211.12),
       Planet(200200, 20, "Gagaga", "Pepa", 100.24),
       Planet(600800, 100, "PEPE", "Shnene", 10.23),
    };
    for (const Planet& i : p) {
      i.printInfo();
    }
    std::print("Enter field to sort by: ");
    std::cin >> field;
    for(size_t i = 0 ; i < p.size() - 1 ; i++){
        for(size_t j = 0 ; j < p.size() - i - 1 ; j++){
            switch(field){
                case 1:
                if(p.at(j).getName() > p.at(j+1).getName()){std::swap(p.at(j), p.at(j+1));}
                break;
                case 2:
                if(p.at(j).getMass() > p.at(j+1).getMass()){std::swap(p.at(j), p.at(j+1));}
                break;
                case 3:
                if(p.at(j).getColSputnik() > p.at(j+1).getColSputnik()){std::swap(p.at(j), p.at(j+1));}
                break;
                case 4:
                if(p.at(j).getPressureSurface() > p.at(j+1).getPressureSurface()){std::swap(p.at(j), p.at(j+1));}
                break;
                case 5:
                if(p.at(j).getColSputnik() > p.at(j+1).getColSputnik()){std::swap(p.at(j), p.at(j+1));}
                break;
                default:
                std::cerr << "Error answer" << std::endl;
        }
    }
    for(const Planet& i : p){
        i.printInfo();
    }
    return EXIT_SUCCESS;
    }
}
