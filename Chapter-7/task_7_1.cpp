#include <print>
#include <cstdlib>
#include <vector>
#include <cstdint>
#include <iostream>

class Test{
    public:
    explicit Test() : number_(0){
        std::cout << this << std::endl;
        //std::println("this: {}",(void*)this);
    }
    Test(uint16_t number) : number_(number){
        std::cout << this << std::endl;
        //std::println("this: {}",(void*)this);
    }
    Test(const Test& obj) : number_(obj.number_){
        std::cout << "object: " << &obj << " this: " << this << std::endl;
        //std::println("object: {}, this: {}",(void*)&obj, (void*)this);
    }
    auto info()->void{
        std::cout << "this: " << this << " number: " << number_ << std::endl;
        //std::println("this: {}, number: {}", (void*)this, number_);
    }
    private:
    uint16_t number_;
};

auto main()->int{
    std::println("Object integer");
    Test t1(1);
    std::println("==================="); 
    std::println("Creating object standart");
    Test t2;
    std::println("===================");
    std::println("Creating t3(t1)");
    
    Test t3(t1);
    
    std::vector<Test> test;
    
    std::println("=====VECTOR=====");
    
    std::println("emplace 67");
    test.emplace_back(67);
    for(Test& i : test){
        i.info();
    }
   
    std::println("==================");
    
    std::println("add 11 pushback");
    test.push_back(t1);
    for(Test& i : test){
        i.info();
    }
    std::println("==================");
    
    std::println("erase");
    test.erase(test.begin() + 0);
    for(Test& i : test){
        i.info();
    }
    std::println("==Emplace 3 numbers==");
    
    test.emplace_back(100);
    test.emplace_back(69);
    test.emplace_back(3);
    for(Test& i : test){
        i.info();
    }
    std::println("3 emplace_Back");
    
    std::println("=================");
    
    std::println("erase 1");
    test.erase(test.begin() + 0);
    
    if(test.empty()){
        std::println("Vector empty");
    }
    for(Test& i : test){
        i.info();
    }
    std::println("=================");

    return EXIT_SUCCESS;
}
