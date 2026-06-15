#include <cstdint>
#include <cstdlib>
#include <print>
#include <string>
#include <vector>

class Vehicle {
public:
    Vehicle(const std::string& brand, uint16_t mileage)
        : brand_(brand), mileage_(mileage) {}
    
    virtual auto printInfo() const noexcept -> void{
        std::println("{}, mileage: {}", brand_, mileage_);
    }
    //Virtual Destructor
    ~Vehicle(){};

protected:
    std::string brand_;
    uint16_t mileage_;
};

class Car : public Vehicle {
public:
    Car(const std::string& b, uint16_t m, bool active)
        : Vehicle(b, m), is_active_(active) {}

    auto printInfo() const noexcept -> void{
        std::println(
                "Mark: {}"
                "active: {}", brand_, is_active_ ? 'y' : 'n'
                );
    }
private:
    bool is_active_;
};

class Bus : public Vehicle {
public:
    Bus(const std::string& b, uint16_t m, uint16_t cap)
        : Vehicle(b, m), capacity_(cap) {}

    auto printInfo() const noexcept -> void{
        std::println(
                "Mark: {}"
                "Mileage: {}"
                "capacity: {} persons", brand_, mileage_, capacity_
                );
    }
private:
    uint16_t capacity_;
};

auto main() -> int {
    std::vector<Vehicle*> garage;

    garage.push_back(new Car("Cumry", 15000, true));
    garage.push_back(new Car("WWW", 32000, false));
    garage.push_back(new Bus("SUSogus", 45000, 20));
    garage.push_back(new Bus("Bulba", 120000, 45));

    for (const Vehicle* vehicle : garage) {
        vehicle->printInfo();
    }
    //This for очищает память
    for (const Vehicle* vehicle : garage) {
        delete vehicle;
    }

  return EXIT_SUCCESS;
}
