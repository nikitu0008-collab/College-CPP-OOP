#include <print>
class Old {
    public:
    virtual constexpr auto print() const noexcept -> void { std::println("Old"); }
    private:
};

class Nouveau : public Old {
public:
    constexpr auto print() const noexcept -> void { 
        std::println("Nouveau"); 
    }
};

auto main() -> int {
    const Old oldObj;
    Nouveau const nouveauObj;

    oldObj.print();
    nouveauObj.print();

    const Old* arrOld = new Old();
    
    oldObj.print();
    delete arrOld;

    Old* arrNouveau = new Nouveau();
    
    oldObj.print(); 
    
    delete arrNouveau;

    return 0;
}
