#include <cstdint>
#include <cstdlib>
#include <print>
#include <iostream>
#include <stdexcept>

class Squad{
    public:
        Squad() : archers_(0), spearman_(0), horseman_(0) {}
        
        Squad(uint16_t archers, uint16_t spearman, uint16_t horseman) 
            : archers_(archers), spearman_(spearman), horseman_(horseman) {}
       
        explicit Squad(uint16_t archers) 
            : archers_(archers), spearman_(0), horseman_(0) {}
        
        friend auto operator+(Squad& left, Squad& right) -> Squad;
        friend auto operator-(Squad& left, Squad& right) -> Squad;
        friend auto operator>(const Squad& left, const Squad& right) -> bool;
        friend auto operator<(const Squad& left, const Squad& right) -> bool;
        friend auto operator==(const Squad& left, const Squad& right) -> bool;
        friend auto operator>>(std::istream& in, Squad& obj) -> std::istream&;
        friend auto operator<<(std::ostream& out, const Squad& obj) -> std::ostream&;
    
        private:
        uint16_t archers_, spearman_, horseman_;
};
auto operator<<(std::ostream& out, const Squad& obj) -> std::ostream&{
    out << "Archers: " << obj.archers_ << '\n'
        << "Horsmena: " << obj.horseman_ << '\n'
        << "Spearman: " << obj.spearman_;

    return out;
}
auto operator>>(std::istream& in, Squad& obj) -> std::istream&{
    std::print(
            "Enter: archers, spearman, horseman :_>"
            );
    in >> obj.archers_ >> obj.spearman_ >> obj.horseman_;
    
    return in;
}

auto operator+(Squad& left, Squad& right) -> Squad{
    Squad result(
            left.archers_ + right.archers_,
            left.horseman_ + right.horseman_,
            left.spearman_ + right.spearman_
            );

    //This is zero
    left = Squad();
    right = Squad();
    return result;
}

auto operator<(const Squad& left, const Squad& right) -> bool {
    if(left < right){
        return true;
    } else {
        return false;
    }
}

auto operator>(const Squad& left, const Squad& right) -> bool {
    if(left > right){
        return true;
    } else {
        return false;
    }
}

auto operator==(const Squad& left, const Squad& right) -> bool{
    return (
            left.archers_ == right.archers_ and 
            left.spearman_ == right.spearman_ and
            left.horseman_ == right.horseman_
           );
}
auto operator-(Squad& left, Squad& right) -> Squad {
    uint16_t total_left = left.archers_ + left.spearman_ + left.horseman_;
    uint16_t total_right = right.archers_ + right.spearman_ + right.horseman_;
    uint16_t archers = 0, spearman = 0, horseman = 0;

    if (total_left >= total_right) {
        if (left.archers_ > right.archers_) {
            archers = left.archers_ - right.archers_;
        } else {
            archers = 0;
        }

        if (left.spearman_ > right.spearman_) {
            spearman = left.spearman_ - right.spearman_;
        } else {
            spearman = 0;
        }

        if (left.horseman_ > right.horseman_) {
            horseman = left.horseman_ - right.horseman_;
        } else {
            horseman = 0;
        }

        right = Squad();
    } else if(total_right > total_left){
        if (right.archers_ > left.archers_) {
            archers = right.archers_ - left.archers_;
        } else {
            archers = 0;
        }

        if (right.spearman_ > left.spearman_) {
            spearman = right.spearman_ - left.spearman_;
        } else {
            spearman = 0;
        }

        if (right.horseman_ > left.horseman_) {
            horseman = right.horseman_ - left.horseman_;
        } else {
            horseman = 0;
        }
        left = Squad();
    } else {
        throw std::invalid_argument("Error operator -");
    }

    return Squad(archers, spearman, horseman);
}
auto main() -> int {
    Squad squad_1;
    Squad squad_2;

    std::println("======== SQUAD ONE ========");
    std::cout << squad_1 << '\n';
    std::cin >> squad_1;

    std::println("======== SQUAD TWO ========");
    std::cout << squad_2 << '\n';
    std::cin >> squad_2;
    std::cout << squad_2 << '\n';

    std::println("======== OPERATIONS ========");
    
    std::println("========      -     ========");
    std::cout << squad_1 - squad_2 << '\n';

    std::println("========      +     =========");
    std::cout << squad_1 + squad_2 << '\n';

    std::println("======== COMPARISONS ========");
        
    if(squad_1 > squad_2){
        std::println("Squad_1 > Squad_2");
    } else if(squad_1 < squad_2){
        std::println("Squad_1 < Squad_2");
    } else if(squad_1 == squad_2){
        std::println("Squad_1 == Squad_2");
    } else {
        throw std::invalid_argument("Error comparisions");
    }
    return EXIT_SUCCESS;
}
