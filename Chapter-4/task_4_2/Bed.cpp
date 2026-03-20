//*Bed realization
#include "Bed.hpp"
#include <string>
#include <iostream>
#include <print>
Bed::Bed() : two_tier_(false), col_places_(0), material_("unknown"), seller_(0.0) {}
Bed::Bed(bool two_tier, unsigned int col_places, std::string material, float seller){
            this->two_tier_ = two_tier;
            this->col_places_ = col_places;
            this->material_ = material;
            this-> seller_ = seller;
        }
auto Bed::printInformation() -> void{
            std::println("\nBed: ");
            std::println("    Two_tier: {}", two_tier_);
            std::println("    col places: {}",col_places_);
            std::println("    material: {}",material_);
            std::println("    seller: {}",seller_);
        }
auto Bed::redactorBed() -> void{
            std::string answer_two_tier;
            std::println("Two yars? [Y/n]\n>_:"); std::cin >> answer_two_tier; if(answer_two_tier == "y" || answer_two_tier == "Y"){two_tier_ = true;}
            std::println("col_mest: "); std::cin >> col_places_;
            std::println("material: "); std::cin >> material_;
            std::println("seller: "); std::cin >> seller_;
        }