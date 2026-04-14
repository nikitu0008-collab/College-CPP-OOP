#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <print>
#include <stdexcept> //* std::invalid_argument
#include <utility> //* std::unreachable
#include <vector>
#include <string>
class Planet {
public:
    Planet(std::string name_planet, unsigned int mass, unsigned int col_sputnik, std::string structure_atmosfer, float pressure_surface) : mass_(mass), col_sputnik_(col_sputnik), structure_atmosfer_(structure_atmosfer), name_planet_(name_planet), pressure_surface_(pressure_surface) {}
    //*Сеттеры
    auto setFn(std::string name_planet) -> void { name_planet_ = name_planet; }
    auto setFn2(unsigned int mass) -> void { mass_ = mass; }
    auto setFn3(unsigned int col_sputnik) -> void { col_sputnik_ = col_sputnik; }
    auto setFn4(std::string structure_atmosfer) -> void { structure_atmosfer_ = structure_atmosfer; }
    auto setFn5(float pressure_surface) -> void { pressure_surface_ = pressure_surface; }
    
    //*Геттеры
    /*nodiscard - означает что функция не предназначена для удаления*/
    [[nodiscard]] auto getFName() const -> std::string { return name_planet_; }
    [[nodiscard]] auto getFMass() const -> unsigned int { return mass_; }
    [[nodiscard]] auto getFColS() const -> unsigned int { return col_sputnik_; }
    [[nodiscard]] auto getFSA() const -> std::string { return structure_atmosfer_; }
    [[nodiscard]] auto getFPS() const -> float { return pressure_surface_; }
    
    auto printInfo() const noexcept -> void {
      std::println("[1]{}", name_planet_);
      std::println("      [2]Mass: {}", mass_);
      std::println("      [3]Structure atmosfer: {}", structure_atmosfer_);
      std::println("      [4]Pressure surface: {}", pressure_surface_);
      std::println("      [5]Col sputnik: {}", col_sputnik_);
    }

private:
    unsigned int mass_, col_sputnik_;
    std::string structure_atmosfer_, name_planet_;
    float pressure_surface_;
};
auto main() -> int {
    unsigned int field = 0;
    std::vector<Planet> p = {
        Planet("Earth", 0, 1, "A", 2.22),
        Planet("Neptun", 30, 5, "Amogus", 1.23),
        Planet("MyPensil", 3, 5, "SUS", 1000),
        Planet("Lyna", 10, 5, "L", 1),
    };
    for (const Planet &i : p) {
      i.printInfo();
    }

    std::print("Enter field to sort by: ");
    std::cin >> field;
    if (field < 1 or field > 5) {
      throw std::invalid_argument("Error's field");
    }
    switch (field) {
    //*std::ranges::less stable_sort
    case 1:
    std::ranges::stable_sort(p, std::ranges::less{}, &Planet::getFName);
    for(const Planet& i : p){
      i.printInfo();
    }
    break;
    case 2:
    std::ranges::stable_sort(p, std::ranges::less{}, &Planet::getFMass);
    for(const Planet& i : p){
      i.printInfo();
    }
    break;
    case 3:
    std::ranges::stable_sort(p, std::ranges::less{}, &Planet::getFSA);
      for(const Planet& i : p){
        i.printInfo();
      }
    break;
    case 4:
      std::ranges::stable_sort(p, std::ranges::less{}, &Planet::getFPS);
      for(const Planet& i : p){
        i.printInfo();
      }
      break;
    case 5:
      std::ranges::stable_sort(p, std::ranges::less{}, &Planet::getFColS);
      for(const Planet& i : p){
        i.printInfo();
      }
    break;
      default:
      std::unreachable(); //*saying compiler that we definitely won't get here.
    }
    return EXIT_SUCCESS;
}
