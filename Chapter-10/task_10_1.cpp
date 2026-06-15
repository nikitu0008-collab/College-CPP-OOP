#include <cstdint>
#include <cstdlib>
#include <print>
class Body {
public:
    uint16_t length_, width_, height_, mass_;
    Body(double l, double w, double h, double m) : length_(l), width_(w), height_(h), mass_(m) {}
    constexpr auto print() const noexcept -> void { 
        std::println("Size: {} {} {}, mass: {}", length_, width_, height_, mass_);
    }
};

class AreaBody : public Body {
public:
    uint16_t x_, y_, z_;
    AreaBody(double l, double w, double h, double m, double x, double y, double z) 
        : Body(l, w, h, m), x_(x), y_(y), z_(z) {}
};

auto main() -> int {
    Body b(2,1,1,10);
    b.print();
    const AreaBody ab(2,1,1,10,3,5,-2);
    ab.print();
    return EXIT_SUCCESS;
}
