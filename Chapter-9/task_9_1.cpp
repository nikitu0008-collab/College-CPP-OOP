#include <string>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <print>
class Robot{
    public:
    Robot() : x(0), y(0) {}
    constexpr auto printInformation() const noexcept -> void {
        //...
    }

    ~Robot(){}
    private:
    int16_t x, y; // int16_t так-как может быть (-)
};

auto main()->int{

    return EXIT_SUCCESS;
}
