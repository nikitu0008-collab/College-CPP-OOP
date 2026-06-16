//Задание с умными указателями
#include <cstdint>
#include <print>
#include <cstdlib>
#include <string>
#include <vector>
#include <memory> // Здесь умные указатели(TODO записать в тетрадь)

//unique - уникальный
//shared - общий
//weak - умный слабый 

class Vehicle{
    public:
        Vehicle(std::string mark, uint16_t mileage)
            : mark_(mark), mileage_(mileage) {}
        virtual constexpr auto printInfo() const noexcept ->void{
            std::println(
                   "Mark: {}\n"
                   "Mileage: {}\n",
                   mark_, mileage_
                    );
        }
        ~Vehicle(){}
    protected:
    std::string mark_;
    uint16_t mileage_;
};

class Car : public Vehicle{
    public:
        Car(std::string mark, uint16_t mileage, bool active)
            : active_(active), Vehicle(mark, mileage){}
        auto constexpr printInfo() const noexcept -> void{
            std::println(
                    "Mark: {}\n"
                    "Mileage: {}\n"
                    "Active: {}\n",
                    mark_, mileage_, (active_ ? 't' : 'f')
                    );
        }
        ~Car(){}
    private:
    bool active_;
};
class Bus : public Vehicle{
    public:
        Bus(std::string mark, uint16_t mileage, uint16_t capacity)
            : capacity_(capacity), Vehicle(mark, mileage){}
        auto constexpr printInfo() const noexcept -> void{
            std::println(
                    "Mark: {}\n"
                    "Mileage: {}\n"
                    "Capacity: {}\n",
                    mark_, mileage_, capacity_
                    );
        }
        ~Bus(){}
    private:
    uint16_t capacity_;
};

auto main()->int{
    std::vector<std::unique_ptr<Vehicle>> garage;

    garage.emplace_back(std::make_unique<Bus>("Lada", 1000, 100));
    garage.emplace_back(std::make_unique<Vehicle>("Gaz",1));
    garage.emplace_back(std::make_unique<Car>("Ferrary", 50,100));

    for(std::unique_ptr<Vehicle>& i : garage){
        i->printInfo();
    }

    return EXIT_SUCCESS;
}
