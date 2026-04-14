//*main.cpp request col bad, work multitude bad.
#include <iostream>
#include <print>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include "Bed.hpp"
auto main() -> int{
    unsigned int col_bad, answer;
    std::print("col bad: ");
    std::cin >> col_bad;
    std::vector<Bed> bed(col_bad);
    std::print("[1]Bed customing [2]Bed default\n>_:");
    std::cin >> answer;
    switch(answer){
        case 1:
        for(Bed& i : bed){
            i.redactorBed();
        }
        for(const Bed& i : bed){
            i.printInformation();
        }
        break;
        case 2:
        for(const Bed& i : bed){
            i.printInformation();
        }
        break;
        default:
        throw std::invalid_argument("Invalid signal value"); //*Exception
        break;
    }
    return EXIT_SUCCESS;
}
