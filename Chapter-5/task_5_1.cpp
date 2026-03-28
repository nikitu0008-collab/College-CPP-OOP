#include <stdexcept> 
#include <iostream>
#include <print>
#include <cstdlib>
#include <vector>
#include <string>
class Plate{
    public:
    //*It's a constructor by default
    Plate() : hight_(0.0), width_(0.0), cost_(0.0), weidth_(0.0), seller_(0.0), material_("unknown"), manufacturer_("unknown"){} 
    
    //*It's constructor full parametrs
    Plate(float hight, float width, float cost, float weidth, float seller, std::string material, std::string manufacturer) : hight_(hight), width_(width), cost_(cost), weidth_(weidth), seller_(seller), material_(material), manufacturer_(manufacturer){}
    
    auto printInformation() const -> void {
        std::println("Plate is a {}, size(w, h, c): {}, {}, {}; weidth: {}, seller: {}, manufacturer: {}", material_,  width_, hight_, cost_, weidth_, seller_, manufacturer_);
    }
    protected:
    float hight_, width_, cost_, weidth_, seller_;
    std::string material_, manufacturer_;
};
auto main() -> int {
    unsigned int index = 0, answer = 0;

    //*Parametrs new add Plate
    float hight_new, width_new, cost_new, seller_new, weidth_new;
    std::string material_new, manufacturer_new;

    std::vector<Plate> plate;
    plate.emplace_back(1, 2, 3, 4, 5, "A", "B");
    plate.emplace_back(100, 50, 1000, 12, 33, "SUS", "SUGOMA");
    for(const auto& i : plate){
        i.printInformation();
    }
    while(answer != 3){ //*clangd recomended don't using do-while. That's why i'm using cycles while

        //*using const to avoid changing the given class of the object
        std::println("\n\t1.add plate\n\t2.delete plate\n\t3.exit\n:_>");
        std::cin >> answer;
        system("clear");
        switch(answer){
            case 1:
            std::println("Enter full parametrs.");
            std::cin >>  hight_new >> width_new >> cost_new >> weidth_new >> seller_new >> material_new >> manufacturer_new;
            //*clangd recomended using emplace_back instead of push_back.
            plate.emplace_back(hight_new,width_new,cost_new,weidth_new,seller_new,material_new,manufacturer_new);
            for(auto& i : plate){
                i.printInformation();
            }
            break;
            case 2:
            std::println("enter index: ");
            std::cin >> index;
            //*checking user don't enter index > plate.size()
            if(index > plate.size()){
                throw std::invalid_argument("index > size vector");
            }
            //*plate он пуст а plate1 plate2 заполнены и др тоже
            plate.erase(plate.begin() + index);
            for(const auto& i: plate){
                i.printInformation();
            }
            break;
            default:
            throw std::invalid_argument("Errors choice");
            break;
        }
    }
    return EXIT_SUCCESS;
}