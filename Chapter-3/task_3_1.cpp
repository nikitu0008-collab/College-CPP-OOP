#include <iostream>
#include <string>
#include <vector>
/*
*I'm using vector for add some cars
*/
class Cars{
    unsigned int year, mileage, power;
    std::string mark, country_of_origin;
public:
    //*It's a constuctor (NO STANDART CONSTRUCTOR)
    Cars(unsigned int year_, unsigned int mileage_, unsigned int power_, std::string mark_, std::string country_of_origin_){
        year = year_; mileage = mileage_; power = power_;
        mark = mark_; country_of_origin = country_of_origin_;
    }
        void print_information(){
            std::cout << "  Car: " << std::endl;
            std::cout << "      " << mark << std::endl;
            std::cout << "      manufacture: " << country_of_origin << std::endl;
            std::cout << "      power: " << power << std::endl;
            std::cout << "      " << year << " data create" << std::endl;
            std::cout << "      mileage: " << mileage << "." << std::endl;
        }
};
int main(){
    unsigned int col_car;
    
    std::cout << "Enter col cars: ";
    std::cin >> col_car;

    std::vector<Cars> cars;

    for(int i = 0 ; i < col_car ; i++){        
        unsigned int year, mileage, power;
        std::string mark, country_of_origin;

        std::cout << "\nEnter year: "; std::cin >> year;
        std::cout << "Enter mark: "; std::cin >> mark;
        std::cout << "Enter mileage: "; std::cin >> mileage;
        std::cout << "Enter country: "; std::cin >> country_of_origin;
        std::cout << "Enter power: "; std::cin >> power;

        //*this is the use of the constructor
        cars.push_back(Cars(year, mileage, power, mark, country_of_origin));
    }
    for(int i = 0 ; i < cars.size() ; i++){
        cars[i].print_information();
    }
    return EXIT_SUCCESS;
}