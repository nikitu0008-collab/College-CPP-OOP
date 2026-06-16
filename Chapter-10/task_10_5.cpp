#include <cstdint>
#include <cstdlib>
#include <memory>
#include <print>
#include <string>
#include <vector>

//Abstract class 
class Vehicle {
public:
    Vehicle(std::string brand, uint16_t mileage)
        : brand_(brand), mileage_(mileage) {}
    virtual auto printInfo() const noexcept -> void{}
protected:
    std::string brand_;
    uint16_t mileage_;
};

class Car : public Vehicle {
public:
    Car(std::string brand, uint16_t mileage, bool active)
        : is_active_(active), Vehicle(brand, mileage) {}
    virtual auto printInfo() const noexcept -> void{
        std::println(
                "Mark: {}\n"
                "active: {}\n"
                "mileage: {}\n",
                brand_, is_active_ ? 'y' : 'n', mileage_
                );
    }
private:
    bool is_active_;
};

class Bus : public Vehicle {
public:
    Bus(const std::string b, uint16_t m, uint16_t cap)
        : Vehicle(b, m), capacity_(cap) {}

    virtual auto printInfo() const noexcept -> void{
        std::println(
                "Mark: {}\n"
                "Mileage: {}\n"
                "capacity: {} persons\n", 
                brand_, mileage_, capacity_
                );
    }
private:
    uint16_t capacity_;
};

auto main() -> int {
    std::vector<std::unique_ptr<Vehicle>> garage;

    garage.emplace_back(new Car("Cumry", 15000, true));
    garage.emplace_back(new Car("WWW", 32000, false));
    garage.emplace_back(new Bus("SUSogus", 45000, 20));
    garage.emplace_back(new Bus("Bulba", 120000, 45));

    for (std::unique_ptr<Vehicle>& vehicle : garage) {
        vehicle->printInfo();
    }

  return EXIT_SUCCESS;
}
