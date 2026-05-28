#include <cstdlib>
#include <cstdint>
#include <print>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
class Robot{
    public:
    Robot() : x(0), y(0)  {
        const std::vector<char> ListCoordinate = { 'x', 'y' };
        const std::vector<std::string> ListMoving = { "Up", "Down", "Left", "Right" };
        const std::vector<std::string> MovingObjects = { "Biba", "SUS", "Bal", "Baby", "Billi" };
        
        answer_objects = ListCoordinate[rand() % 2];
        answer_movings = ListMoving[rand() % 4];
    }
    constexpr auto printInfo() noexcept -> void{
        std::cout << "I'm: " << this << ", my coordinates: " << x << ", " << y << std::endl;
    }
    auto move(int cord_1) -> Robot&{
        std::println(
                "I'm moving {}, don't saying where, i choise my self\n",
                "choise coordinate.. {}, Choise moving.. {}",
                cord_1, answer_objects, answer_movings
                );
        x = cord_1;
        return *this;
    }
    auto move(int cord_1, int cord_2) -> Robot&{
        std::cout << "Saying moving this coordinate: " << cord_1 << ", " << cord_2 << std::endl; 
        x = cord_1; 
        y = cord_2;
        return *this;
    }
    auto move(std::string objects) -> Robot&{
        uint16_t objects_int = 0;
        if(objects == "Biba"){ objects_int = 1; }
            else if(objects == "SUS"){ objects_int = 2; }
                else { objects_int = 0; }
        switch(objects_int){
        case 1:
        std::println("I was tald to move {}. I can do it", objects);
        break;
        case 2:
        std::println("I was tald to move {}. I can do it. Warning: he might eat you", objects);
        break;
        case 3:
        std::println("I don't know how to move {}",objects);
        break;
        default:
        std::unreachable();
        }
        return *this;
    }
    private:
    int16_t x, y;
    std::string answer_movings, answer_objects;
};

auto main()->int{
    Robot r;
    r.printInfo();
    r.move(2, 4);
    r.printInfo();
    r.move(69, 105);
    r.printInfo();
    r.move("SUS");
    return EXIT_SUCCESS;
}
