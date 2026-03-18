#include <iostream>
#include <string>
#include <vector>
#include <print>
class Bed{
    private:
    bool two_tier_;
    unsigned int col_places_;
    std::string material_, two_tier_anwer_;
    float seller_;
    public:
        Bed() : two_tier_(false), col_places_(0), material_("unknown"), seller_(0.0), two_tier_anwer_("unknown") {}
        Bed(bool two_tier, unsigned int col_places, std::string material, float seller, std::string two_tier_anwer){
            this->two_tier_ = two_tier;
            this->col_places_ = col_places;
            this->material_ = material;
            this->seller_ = seller;
            this->two_tier_anwer_ = two_tier_anwer;
        }
        auto printInformation() -> void{
            std::println("\nBed:");
            std::println("      two yars: {}",two_tier_);
            std::println("      col places: {}",col_places_);
            std::println("      material: {}",material_);
            std::println("      seller: {}",seller_);
        }
        auto redactorBed() -> void{
            std::println("Two yars? [Y/n] >_:"); std::cin >> two_tier_anwer_; if(two_tier_anwer_ == "y" || two_tier_anwer_ == "Y"){two_tier_=true;}
            std::println("col_places: "); std::cin >> col_places_;
            std::println("material: "); std::cin >> material_;
            std::println("seller: "); std::cin >> seller_;
        }
};
auto main() -> int{
    unsigned int col_bad, answer;
    std::println("col bad: ");
    std::cin >> col_bad;
    std::vector<Bed> bed(col_bad);
    std::println("[1]Bed customing [2]Bed default\n>_:");
    std::cin >> answer;
    switch(answer){
        case 1:
        for(int i = 0 ; i < bed.size() ; i++){
            bed.at(i).redactorBed();
        }
        for(int i = 0 ; i < bed.size() ; i++){
            bed[i].printInformation();
        }
        break;
        case 2:
        for(int i = 0 ; i < bed.size() ; i++){
            bed.at(i).printInformation();
        }
        break;
        default: 
        throw std::invalid_argument("Invalid signal value"); //*Exception
        break;
    }
    return EXIT_SUCCESS;
}