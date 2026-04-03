#include <iostream>
#include <stdexcept> //* std::invalid_argument
#include <string>
#include <vector>
#include <print>
#include <cstdlib>
#include <cstdint> //int8..16.._t
class Bed{
    //*Inisialization
    public:
    Bed();
    auto printInformation() noexcept -> void;
    auto redactorBed() -> void;
    protected:
    bool two_tier_;
    unsigned int col_places_;
    std::string material_, two_tier_anwer_;
    float seller_;
};

Bed::Bed() : two_tier_(false), col_places_(0), material_("unknown"), seller_(0.0){}

auto Bed::printInformation() noexcept -> void{
    std::println("\nBed:");
    std::println("      two yars: {}",two_tier_);
    std::println("      col places: {}",col_places_);
    std::println("      material: {}",material_);
    std::println("      seller: {}",seller_);
}
auto Bed::redactorBed() -> void{
    std::println("Two yars? [Y/n] >_:"); std::cin >> two_tier_anwer_; (two_tier_anwer_ == "Y" || two_tier_anwer_ == "y") ? two_tier_ = true : false;
    std::println("col_places: "); std::cin >> col_places_;
    std::println("material: "); std::cin >> material_;
    std::println("seller: "); std::cin >> seller_;
}
auto main() -> int{
    unsigned int col_bad = 0; 
    int8_t answer = 0;
    std::println("col bad: ");
    std::cin >> col_bad;
    std::vector<Bed> bed(col_bad);
    std::println("[1]Bed customing [2]Bed default\n>_:");
    std::cin >> answer;
    switch(answer){
        //*The compiler recommends that I use for(int i = ... ; ... ; ...) instead of for(auto& ... : ...)
        case 1:
        for(Bed& i : bed){
            i.redactorBed();
        }
        for(Bed& i : bed){
            i.printInformation();
        }
        break;
        case 2:
        for(Bed& i : bed){
            i.printInformation();
        }
        break;
        default:
        throw std::invalid_argument("Invalid signal value");
        break;
    }
    return EXIT_SUCCESS;
}
