#include <cstdint>
#include <cstdlib>
#include <print>
#include <iostream>
#include <vector>
#include <string>
#include <memory>

/*===INTERFACE===*/
class IUse{
    public:
    virtual constexpr auto use() const noexcept -> void = 0;
};
class Sword : public IUse{
    public:
        Sword(){}
        constexpr auto use() const noexcept -> void{
            std::println("Your damage sword air");
        }
        ~Sword(){}
    private:
};
class Bow : public IUse{
    public:
        Bow(){}
        constexpr auto use() const noexcept -> void {
            std::println("Your shot Bow");
        }
        ~Bow(){}
    private:
};
class Potion : public IUse{
    public:
        Potion(){}
        constexpr auto use() const noexcept -> void {
            std::println("Your use potion");
        }
        ~Potion(){}
    private:
};
class Human{
    public:
        Human(std::string name, uint16_t age)
            : name_(name), age_(age), potion_(Potion()), bow_(Bow()), sword_(Sword()) {}
        constexpr auto use(uint16_t& answer)  noexcept -> void {
            switch(answer){
                case 1: sword_.use(); break;
                case 2: bow_.use(); break;
                case 3: potion_.use(); break;
                default: std::cerr << "===ERROR SWITCH CLASS===" << '\n'; break;
            }
        }
        ~Human(){}
    private:
        std::string name_;
        uint16_t age_, answer_;
        Potion potion_;
        Bow bow_;
        Sword sword_;
};

auto main() -> int {
    uint16_t answer;
    std::print(
        "What do you use?\n"
        "1.Sword\n"
        "2.Bow\n"
        "3.Potion\n"
        ":_> "
    );
    std::cin >> answer;
    Human human = Human("SOUNT HUB", 67);
    human.use(answer);
    return EXIT_SUCCESS;
}
