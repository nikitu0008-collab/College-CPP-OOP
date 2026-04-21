#include <cstdlib>
#include <iostream>
#include <print>
#include <stdexcept>
#include <string>
#include <vector>
#include <cstdint>
class Plate {
public:
  //*It's a constructor by default
  Plate() : hight_(0.0), width_(0.0), cost_(0.0), weidth_(0.0), seller_(0.0), material_("unknown"), manufacturer_("unknown") {}
  Plate(float hight, float width, float cost, float weidth, float seller, std::string material, std::string manufacturer) : hight_(hight), width_(width), cost_(cost), weidth_(weidth), seller_(seller), material_(material), manufacturer_(manufacturer) {}

  constexpr auto printInformation() const noexcept -> void {
    std::println("Plate is a {}, size(w, h, c): {}, {}, {}; weidth: {}, seller: {}, manufacturer: {}",material_, width_, hight_, cost_, weidth_, seller_,manufacturer_);
  }
private:
  float hight_, width_, cost_, weidth_, seller_;
  std::string material_, manufacturer_;
};
auto main() -> int {
  uint16_t index = 0, answer = 0;

  //*Parametrs new add Plate
  //*It's constructor full parametrs
  float hight_new = 0, width_new = 0, cost_new = 0, seller_new = 0, weidth_new = 0;
  std::string material_new, manufacturer_new;

 std::vector<Plate> plate;
  plate.emplace_back(10, 25, 30, 45, 15, "A", "K");
  plate.emplace_back(100, 50, 1000, 12, 33, "SUS", "SUGOMA");
  plate.emplace_back(50, 5, 50, 100, 30, "plitO4ka", "O4ken");
  for (const Plate& i : plate) {
    i.printInformation();
  }
  while (answer != 3) {
    //*using const to avoid changing the given class of the object
    std::println("\n\t1.add plate\n\t2.delete plate\n\t3.exit\n:_>");
    std::cin >> answer;
    switch (answer) {
    case 1:
      system("clear");
      std::println("Enter name and full parametrs. (height, width, cost, weidth, seller, material)");
      std::cin >> hight_new >> width_new >> cost_new >> weidth_new >> seller_new >> material_new >> manufacturer_new;
      //*clangd recomended using emplace_back instead of push_back.
      plate.emplace_back(hight_new, width_new, cost_new, weidth_new, seller_new, material_new, manufacturer_new);
      for (const Plate& i : plate) {
          i.printInformation();
      }
      break;
    case 2:
      std::println("enter index: ");
      std::cin >> index;
      //*checking user don't enter index >= plate.size()
      if (index >= plate.size()) {
        throw std::invalid_argument("index > size vector");
      }
      plate.erase(plate.begin() + index);
      system("clear");
      for (const Plate& i : plate) {
        i.printInformation();
      }
      break;
    case 3:
      //*call destructor
      break;
    default:
      throw std::invalid_argument("Errors choice");
      break;
    }
  }
  return EXIT_SUCCESS;
}
