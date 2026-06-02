#include <iostream>
#include <print>
#include <cstdlib>
#include <stdexcept>
#include <utility>

class MyArray{
    public:
    MyArray() : size_(0), arr_(nullptr){}

    //Constructor int number
    explicit MyArray(int number) : size_(number), arr_(new int[size_]){}
    MyArray(const MyArray& obj) : size_(obj.size_), arr_(new int[size_]){}
    MyArray(MyArray&& obj) noexcept : size_(obj.size_), arr_(obj.arr_){obj.size_ = 0, obj.arr_ = nullptr; };
    //Only annouse(annouse -- обьявление)
    friend auto operator<<(std::ostream& /*out*/, const MyArray& /*obj*/) -> std::ostream&;
    friend auto operator>>(std::istream& /*in*/, MyArray& /*obj*/) -> std::istream&;
    friend auto operator+(MyArray& /*left*/, MyArray& /*right*/) -> MyArray;

    auto operator[]() -> MyArray&{
        return *this;
    }  
    
    //Increment, (Increment == ++)
    auto operator++(int) -> MyArray&{
        const int new_size_ = size_ + 1;
        int* new_arr_ = new int[new_size_];
        for(size_t i = 0 ; std::cmp_less(i , size_) ; i++){
            new_arr_[i] = arr_[i];
        }
        new_arr_[size_] = 0;
        delete[] arr_;
        arr_ = new_arr_;
        size_ = new_size_;
        return *this;
    }
        
    //Dicrement, (Dicrement == --)
    auto operator--(int) -> MyArray&{
        if(size_ == 0){
            throw std::invalid_argument("===SIZE 0===");
        }
        MyArray old = *this;
        const int new_size_ = size_ - 1;
        int* new_arr_ = new int[new_size_];
        for(size_t i = 0 ; std::cmp_less(i , new_size_) ; i++){
            new_arr_[i] = arr_[i];
        }
        delete[] arr_;
        arr_ = new_arr_;
        size_ = new_size_;
        return *this;
    }
    
    //Unary, (Unary == -)
    auto operator-() const -> MyArray{
        MyArray result(size_);
        for(size_t i = 0 ; std::cmp_less(i , size_) ; i++){
            result.arr_[i] = -arr_[i];
        }
        return result;
    }
    explicit operator int() const{
        const MyArray copy;
        return copy.size_;
    }
   
    ~MyArray(){
        delete[] arr_;
        arr_ = nullptr;
        size_ = 0;
    }
    private:
    int size_;
    int* arr_ = new int [size_];
};

auto operator<<(
        std::ostream& out,
        const MyArray& obj
        ) -> std::ostream&
{
    for(size_t i = 0 ; std::cmp_less(i , obj.size_) ; i++){
        out << obj.arr_[i];
        if(i + 1 < obj.size_) { out << ' ';}
    }
    return out;
}
auto operator>>(std::istream& in, MyArray& obj) -> std::istream&{
    for(size_t i = 0 ; std::cmp_less(i , obj.size_) ; i++){
        in >> obj.arr_[i]; // added *obj
    }
    return in;
}

auto operator+(MyArray& left, MyArray& right) -> MyArray{
    MyArray result(left.size_ + right.size_);
    for(size_t i = 0 ; std::cmp_less(i , left.size_) ; i++){
        result.arr_[i] = left.arr_[i];
        result.arr_[left.size_ + i] = right.arr_[i];
    }
    return result;
}

auto main()->int{
    std::println("SUS");
    MyArray arr(3);
    std::println("=====CIN========");
    for(size_t i = 0 ; i < 3 ; i++){
        std::cin >> arr;
    }
    std::println("================");
    for(size_t i = 0 ; i < 3 ; i++){
        std::cout << arr << '\n';
    }
    std::println("======++=========");
    arr++;
    std::println("=================");

    std::println("Size arr: {}",(int)arr);
    
    std::println("==================");
    for(size_t i = 0 ; i < 3 ; i++){
        std::cout << arr << '\n';
    }
    
    std::println("========--========");
    
    arr--;
    
    std::println("===================");
    for(size_t i = 0 ; i < 3 ; i++){
        std::cout << arr << '\n';
    }
    std::println("=======ARR-========");
    for(size_t i = 0 ; i < 3 ; i++){
        std::cout << -arr << '\n';
    }
    std::println("====================");
    std::println("Size arr: {}", (int)arr);
    
    std::println("=========ARR========");
    for(size_t i = 0 ; i < 3 ; i++){
        std::cout << arr << '\n';
    }

    std::println("========ARR+ARR======");
    
    for(size_t i = 0 ; i < 3 ; i++){
        std::cout << arr + arr << '\n';
    }
    std::println("=========END==========");
    return EXIT_SUCCESS;
}
