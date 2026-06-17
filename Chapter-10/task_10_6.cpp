#include <cstdint>
#include <cstdlib>
#include <print>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <memory>

class Body {
public:
    Body(float mass, float jumping, uint16_t x, uint16_t y, uint16_t z)
        : mass_(mass), jumping_(jumping), x_(x), y_(y), z_(z), id_(amount_++) {}

    constexpr auto printInfo() const noexcept -> void {
        std::println(
                "ID: {}, mass: {}, jumping: {}, coords: ({}, {}, {})",
                id_, mass_, jumping_, x_, y_, z_);
    }

    virtual auto dropIt(uint16_t force) -> uint16_t = 0;

    ~Body(){}
protected:
    float mass_, jumping_;
    uint16_t x_, y_, z_;
private:
    uint16_t id_;
    static uint16_t amount_;
};

uint16_t Body::amount_ = 0;

class Dice : public Body {
public:
    Dice(float mass, uint16_t x, uint16_t y, uint16_t z, float jumping)
        : Body(mass, jumping, x, y, z), num_(1 + rand() % 6) {}

    auto dropIt(uint16_t force) -> uint16_t{
        num_ = 1 + (rand() % 6);
        x_ = rand() % 100;
        y_ = 0;
        z_ = rand() % 100;
        return num_;
    }


    constexpr auto printInfo() const noexcept -> void{
        std::println("  Current number: {}", num_);
    }
private:
    uint16_t num_;
};

class Ball : public Body {
public:
    Ball(float mass, uint16_t x, uint16_t y, uint16_t z, float jumping)
        : Body(mass, jumping, x, y, z), jump_height_(0) {}

    auto dropIt(uint16_t force) -> uint16_t{
        jump_height_ = force * jumping_;
        y_ = 0;
        return jump_height_;
    }

    constexpr auto printInfo() const noexcept -> void{
        std::println("  Last jump height: {}", jump_height_);
    }
private:
    uint16_t jump_height_;
};

static std::vector<std::unique_ptr<Body>> bodies;

auto main() -> int {
    uint16_t answer = 0, result = 0, idx = 0, x = 0, y = 0, z = 0;
    while (answer != 1) {
        std::print(
            "1. Exit\n"
            "2. Show all\n"
            "3. Add Dice\n"
            "4. Add Ball\n"
            "5. Info by index\n"
            "6. Drop it by index\n"
            ":_> "
        );
        std::cin >> answer;

        switch (answer) {
            case 1:
                std::println("Bye...");
                break;
            case 2: {
                if (bodies.empty()) {
                    std::println("Bodies empty()");
                } else if(!bodies.empty()){
                    for (size_t i = 0; i < bodies.size(); i++) {
                        std::print("[{}] ", i);
                        bodies.at(i)->printInfo();
                    }
                } else {
                    throw std::invalid_argument("===ERROR CASE 2===");
                }
                break;
            }
            case 3: {
                float mass = 0, jumping = 0;
                std::print("Enter mass, jumping (0..1), x, y, z: ");
                std::cin >> mass >> jumping >> x >> y >> z;
                if(mass < 0 or jumping < 0) { throw std::invalid_argument("===MASS < 0===");}
                bodies.push_back(std::make_unique<Dice>(mass, x, y, z, jumping));
                std::println("Dice added");
                break;
            }
            case 4: {
                float mass, jumping;
                std::print("Enter mass, jumping (0..1), x, y, z: ");
                std::cin >> mass >> jumping >> x >> y >> z;
                bodies.push_back(std::make_unique<Ball>(mass, x, y, z, jumping));
                std::println("Ball added.");
                break;
            }
            case 5: {
                std::print("Enter index: ");
                std::cin >> idx;
                if (idx < bodies.size()) {
                    bodies.at(idx)->printInfo();
                } else {
                    std::cerr << "Invalid index. Or empty\n";
                }
                break;
            }
            case 6: {
                uint16_t force = 0;
                std::print("Enter index and force: ");
                std::cin >> idx >> force;
                if (idx < bodies.size()) {
                    result = bodies.at(idx)->dropIt(force);
                    std::println("Result: {}", result);
                } else {
                    std::cerr << "Invalid index.\n";
                }
                break;
            }
            default:
                std::cerr << "===ERROR SWITCH===" << std::endl;
        }
    }
    return EXIT_SUCCESS;
}
