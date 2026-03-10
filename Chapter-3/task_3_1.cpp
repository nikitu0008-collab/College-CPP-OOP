#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
/*
*I'm using vector for add some cars
*Using algorithm for std::sort
*/
class Cars{
    public:
    unsigned int year_, mileage_, power_;
    std::string mark_, country_of_origin_;
    //*It's a constuctor (NO STANDART CONSTRUCTOR)
    Cars(unsigned int year, unsigned int mileage, unsigned int power, std::string mark, std::string country_of_origin){
        year_ = year; mileage_ = mileage; power_ = power;
        mark_ = mark; country_of_origin_ = country_of_origin;
    }
        void print_information(){
            std::cout << "  Car: " << std::endl;
            std::cout << "      " << mark_ << std::endl;
            std::cout << "      manufacture: " << country_of_origin_ << std::endl;
            std::cout << "      power_: " << power_ << std::endl;
            std::cout << "      " << year_ << " data create" << std::endl;
            std::cout << "      mileage_: " << mileage_ << "." << std::endl;
        }
};
int main(){
    unsigned int col_car;
    
    std::cout << "Enter col cars: ";
    std::cin >> col_car;

    std::vector<Cars> cars;

    for(int i = 0 ; i < col_car ; i++){        
        unsigned int year_, mileage_, power_;
        std::string mark_, country_of_origin_;

        std::cout << "\nEnter year_: "; std::cin >> year_;
        std::cout << "Enter mark_: "; std::cin >> mark_;
        std::cout << "Enter mileage_: "; std::cin >> mileage_;
        std::cout << "Enter country: "; std::cin >> country_of_origin_;
        std::cout << "Enter power_: "; std::cin >> power_;

        //*this is the use of the constructor
        cars.push_back(Cars(year_, mileage_, power_, mark_, country_of_origin_));
    }
    //*I'm using bubble sort.
    for (int i = 0; i < col_car - 1; i++) {
        for (int j = 0; j < col_car - i - 1; j++) {
            if (cars[j].year_ > cars[j + 1].year_) {
                std::swap(cars[j], cars[j + 1]);
            }
        }
    }
    for(int i = 0 ; i < cars.size() ; i++){
        cars[i].print_information();
    }
    return EXIT_SUCCESS;
}