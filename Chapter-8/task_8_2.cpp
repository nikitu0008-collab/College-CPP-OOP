#include <print>
#include <cstdlib>
#include <cstdint>
#include <string>
#include <vector>
#include <random>

class Enemy{
    public:
    //Constructor default
    Enemy() 
        : name_("unknown-name"), surname_("unknown-surname"), health_(0), damage_(0) {}
    
    //Constructor the parametrs
    Enemy(std::string name, std::string surname, uint16_t health, uint16_t damage)
        : name_(name), surname_(surname), health_(health), damage_(damage) {}

    //Method
    constexpr auto printInfo() const noexcept -> void {
        std::println(
            "Modificator: {}\n",
            "{} {}    Health: {}    Damage: {}",
            multiplier_, name_, surname_, health_, damage_
        );
    }

    static auto getMultiplier() -> uint16_t { return multiplier_; }

    static auto increaseMultiplier(uint16_t number) -> void{
        multiplier_ =+ number;
    }
    private:
    std::string name_, surname_;
    uint16_t health_, damage_;
    static uint16_t multiplier_;
};
uint16_t Enemy::multiplier_ = 0;
auto main()->int{
    const std::vector<std::string> name = {"Nikita", "ZIP", "GIT"};
    const std::vector<std::string> surname = {"PABLO", "HUB", "KA"};

    std::vector<Enemy> enemy(4);
    srand(time(0));
    enemy.emplace_back(
        name.at(rand() % name.size()), 
        surname.at(rand() % surname.size()), 
        2 + rand() % 10 * Enemy::getMultiplier(),
        1 + rand() % 5 * Enemy::getMultiplier()
    );

    std::println("Modificator: {}", Enemy::getMultiplier());
    for(const Enemy& i : enemy){
        i.printInfo();
    }

    enemy.clear();
    
    Enemy::increaseMultiplier(10);
    enemy.resize(5);
    std::println("Modificator: {}", Enemy::getMultiplier()); 

    for(const Enemy& i : enemy){
        i.printInfo();
    }

    return EXIT_SUCCESS;
}