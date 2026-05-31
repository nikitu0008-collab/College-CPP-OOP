#include <cstdint>
#include <print>
#include <cstdlib>

class MyArray{
    public:
    MyArray() : size_(0), arr_(nullptr){}

    //Constructor int number
    explicit MyArray(uint16_t number) : size_(number), arr_(new uint16_t[size_]){
        std::println("===FILLING ARR===");
        for(size_t i = 0 ; i < size_ ; i++){ arr_[i] = 0; }
    }
    auto operator[]() -> MyArray&{
        return *this;
    }  
    
    //Increment, (Increment == ++)
    auto operator++(int) -> MyArray&{
        const uint16_t new_size_ = size_ + 1;
        uint16_t* new_arr_ = new uint16_t[new_size_];
        for(size_t i = 0 ; i < size_ ; i++){
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
        const uint16_t new_size_ = size_ - 1;
        uint16_t* new_arr_ = new uint16_t[new_size_];
        for(size_t i = 0 ; i < size_ ; i++){
            new_arr_[i] = arr_[i];
        }
        new_arr_[size_] = 0;
        delete[] arr_;
        arr_ = new_arr_;
        size_ = new_size_;
        return *this;
    }
    
    //Unary, (Unary == -)
    auto operator-() -> MyArray&{
        const uint16_t new_size_ = size_ - (size_ * size_);
        uint16_t* new_arr_ = new uint16_t[new_size_];
        for(size_t i = 0 ; i < size_ ; i++){
            new_arr_[i] = arr_[i];
        }
        new_arr_[size_] = 0;
        delete[] arr_;
        arr_ = new_arr_;
        size_ = new_size_;
        return *this;
    }

    //operator(+ ? - ? -- ? ++ ?)
    explicit operator uint16_t() const{
        return size_; //return size vector copy
    }
    ~MyArray(){
        delete[] arr_;
        arr_ = nullptr;
        size_ = 0;
    }
    private:
    uint16_t size_;
    uint16_t* arr_ = new uint16_t [size_];
};

auto main()->int{
    std::println("SUS");
    return EXIT_SUCCESS;
}
