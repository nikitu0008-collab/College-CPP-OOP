#include <print>
#include <cstdlib>
#include <vector>
#include <cstdint>
class Test{
    public:
    explicit Test() : number_(0){
        std::println("this: {}",(void*)this);
    }
    Test(uint16_t number) : number_(number){
        std::println("this: {}",(void*)this);
    }
    Test(const Test& obj) : number_(obj.number_){
        std::println("object: {}, this: {}",(void*)&obj, (void*)this);
    }
    auto info()->void{
        std::println("this: {}, number: {}", (void*)this, number_);
    }
    private:
    uint16_t number_;
};

auto main()->int{
    std::vector<Test> test;
    test.emplace_back(67);
    test.emplace_back();
    test.at(0).info();
    test.at(1).info();

    return EXIT_SUCCESS;
}
