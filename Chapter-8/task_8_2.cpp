#include <print>
#include <cstdlib>
#include <cstdint>
#include <string>
#include <vector>

class Enemy{
    public:
      Enemy() : health_((2 + (rand() % 10)) * multiplier_), damage_((1 + (rand() % 5)) * multiplier_) {
        static const std::vector<std::string> nameVector_ = {
            "Nikita", "Zip", "Git", "C"
        };
        static const std::vector<std::string> surnameVector_ = {
            "Pablo", "Hub", "Ka", "pp"
        };
        name_ = nameVector_[rand() % 4];
        surname_ = surnameVector_[rand() % 4];
      }
    constexpr auto printInfo() const noexcept -> void {
        std::println(
            "{} {}    Health: {}    Damage: {}\n",
            name_, surname_, health_, damage_
        );
    }

    static auto getMultiplier() -> float { return multiplier_; }

    static auto increaseMultiplier(float number) -> void{
        multiplier_ += number;
    }
    private:
    std::string name_, surname_;
    uint16_t health_, damage_;
    static float multiplier_;
};

float Enemy::multiplier_ = 1;

auto main()->int{
    std::vector<Enemy> enemy(4);

    std::println("===ADDING 4 ELEMENTS===");
    
    std::println("Modificator: {}", Enemy::getMultiplier());
    for(const Enemy& i : enemy){
        i.printInfo();
    }
    
    enemy.clear();
    std::println("===CLEAR===");

    Enemy::increaseMultiplier(10);
    std::println("===ADDING===");

    enemy.resize(5);
    std::println("===RESIZE===");

    std::println("Modificator: {}", Enemy::getMultiplier()); 
    for(const Enemy& i : enemy){
        i.printInfo();
    }

    return EXIT_SUCCESS;
}
