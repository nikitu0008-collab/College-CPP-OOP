#include <vector>
#include <print>
#include <cstdlib>
#include <cstdint>
class DynamicClass{
    public:
        explicit DynamicClass() : arr_(nullptr), size_(nullptr){ std::println("===CONSTRUCTOR STANDARD===");}
        DynamicClass(int size, const std::vector<int16_t>& numbers) : arr_(new int16_t[size]), size_(new int16_t(size)){
            std::println("===CONSTRUCTOR PARAMETRS===");
            for(size_t i = 0 ; i < numbers.size() ; i++){
                arr_[i] = numbers.at(i);
            }
        }
        DynamicClass(const DynamicClass& src){
            if(&src != this){
                std::println("===COPY===");
                arr_ = new int16_t[*src.size_];
                size_ = new int16_t[*src.size_];
            
                for(size_t i = 0 ; i < *size_ ; i++){
                    arr_[i] = src.arr_[i];
                }
            }
        }
        DynamicClass(DynamicClass&& src) noexcept {
            std::println("===RVAL===");
            arr_ = src.arr_;
            size_ = src.size_;
            src.arr_ = nullptr; 
            src.size_ = nullptr;
        }
        ~DynamicClass(){
            delete[] arr_;
            arr_ = nullptr;
            delete size_;
            size_ = nullptr;
            std::println("===DESTRUCTOR COMPLETED===");
        }
    private:
        int16_t* arr_, *size_;
};
auto main()->int{
    std::vector<DynamicClass> dynamicClass(2); //(2)
    dynamicClass.emplace_back(DynamicClass(2,{1,2,3,4}));
    dynamicClass.push_back(DynamicClass(3,{5,6,7,8}));
    return EXIT_SUCCESS;
}
