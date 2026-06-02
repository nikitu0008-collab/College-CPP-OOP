#include <cstdint>
#include <print>
#include <cstdlib>

class MyArray{
    public:
    MyArray() : size_(0), arr_(nullptr){}

    //Constructor int number
    explicit MyArray(int number) : size_(number), arr_(new int[size_]){
        std::println("===FILLING ARR===");
        for(size_t i = 0 ; i < size_ ; i++){ arr_[i] = 0; }
    }
    auto operator[]() -> MyArray&{
        return *this;
    }  
    
    //Increment, (Increment == ++)
    auto operator++(int) -> MyArray&{
        const int new_size_ = size_ + 1;
        int* new_arr_ = new int[new_size_];
        for(size_t i = 0 ; i < size_ ; i++){
            new_arr_[i] = arr_[i];
        }
        delete[] arr_;
        arr_ = new_arr_;
        size_ = new_size_;
        return *this;
    }
        
    //Dicrement, (Dicrement == --)
    auto operator--(int) -> MyArray&{
        const int new_size_ = size_ - 1;
        int* new_arr_ = new int[new_size_];
        for(size_t i = 0 ; i < size_ ; i++){
            new_arr_[i] = arr_[i];
        }
        delete[] arr_;
        arr_ = new_arr_;
        size_ = new_size_;
        return *this;
    }
    
    //Unary, (Unary == -)
    auto operator-() const -> MyArray {
        MyArray result(size_);
        for (size_t i = 0; i < size_; i++) {
            result.arr_[i] = -arr_[i];
        }
        return result;
    }

    //operator(+ ? - ? -- ? ++ ?)
    explicit operator int() const{
        return size_; //return size vector copy
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

auto main()->int{
    std::println("SUS");
    return EXIT_SUCCESS;
}
//uint16_t это short, надо переделать
//вернуть копию это надо создать обьект класса записать туда с противоположным значением.
