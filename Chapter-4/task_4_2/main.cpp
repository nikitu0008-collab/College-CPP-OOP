//*main.cpp request col bad, work multitude bad.
#include <iostream>
#include <print>
#include <vector>
#include <cstdlib> //* return EXIT_...
#include "Bed.hpp"
auto main() -> int{
    unsigned int col_bad, answer;
    std::println("col pad: ");
    std::cin >> col_bad;
    std::vector<Bed> bed(col_bad);
    std::println("[1]Bed customing [2]Bed default\n>_:");
    std::cin >> answer;
    switch(answer){
        case 1:
        for(size_t i = 0 ; i < bed.size() ; i++){
            bed.at(i).redactorBed();
        }
        for(size_t i = 0 ; i < bed.size() ; i++){
            bed.at(i).printInformation();
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
