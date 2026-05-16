#include <print>
#include <iostream>
#include <cstdlib>
#include <cstdint>
class TestFunc{
    public:
        TestFunc(){
            std::println("===CONSTRUCTOR COMPLETED");
            std::cout << "this: " << this << std::endl;
            for(size_t i = 0 ; i < 2 ; i++){
                arr_[i] = i;
            }
        }

        TestFunc(const TestFunc& arr) : arr_(new uint16_t[2]){
            std::println("===CONSTRUCTOR COPY COMPLETED===");
            for(size_t i = 0 ; i < 2 ; i++){
                arr_[i] = arr.arr_[i];
            }
            std::cout 
                << "Arr: " << &arr << std::endl 
                << " This: " << this << 
            std::endl;
        }
        auto constexpr printInfo() const noexcept ->void{
            std::println("===METHOD CLASS===");
            std::cout << "this: " << this << std::endl;
        }

        ~TestFunc(){
            delete[] arr_;
            std::println("===DESTRUCTOR COMPLETED===");
        }
    private:
    uint16_t* arr_ = new uint16_t[2];
};
 static auto Info(TestFunc testFunc)-> void{
    std::println("===FUNC INFO==="); 
    testFunc.printInfo();
}
auto main()->int{
    TestFunc testFunc;
    testFunc.printInfo();
    Info(testFunc);
    return EXIT_SUCCESS;
}
//Constructor started 1, destructor started 2. 
