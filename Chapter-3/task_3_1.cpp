#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
/*
*I'm using vector for add some cars
*Using algorithm for std::sort
*/
class Car{
    public:
    unsigned int year_, mileage_, power_;
    std::string mark_, country_of_origin_;
    //*It's a constuctor (NO STANDART CONSTRUCTOR)
    Car(unsigned int year, unsigned int mileage, unsigned int power, std::string mark, std::string country_of_origin){
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

    std::vector<Car> car;

    for(int i = 0 ; i < col_car ; i++){        
        unsigned int year_, mileage_, power_;
        std::string mark_, country_of_origin_;

        std::cout << "\nEnter year_: "; std::cin >> year_;
        std::cout << "Enter mark_: "; std::cin >> mark_;
        std::cout << "Enter mileage_: "; std::cin >> mileage_;
        std::cout << "Enter country: "; std::cin >> country_of_origin_;
        std::cout << "Enter power_: "; std::cin >> power_;

        //*this is the use of the constructor
        car.push_back(Car(year_, mileage_, power_, mark_, country_of_origin_));
    }
    //*I'm using bubble sort. sort in ascending order
    for (int i = 0; i < car.size() - 1; i++) {
        for (int j = 0; j < car.size() - i - 1; j++) {
            if (car.at(j).year_ > car.at(j + 1).year_) {
                std::swap(car.at(j), car.at(j + 1));
            }
        }
    }
    for(int i = 0 ; i < car.size() ; i++){
        car.at(i).print_information();
    }
    return EXIT_SUCCESS;
}