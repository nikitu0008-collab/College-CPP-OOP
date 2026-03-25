//*description bed
#pragma once

#ifndef BED_HPP
#define BED_HPP

#include <string>
class Bed{
    private:
        bool two_tier_;
        unsigned int col_places_;
        std::string material_;
        float seller_;
    public:
        Bed();
        Bed(bool two_tier, unsigned int col_places, std::string material, float seller);
        auto printInformation() -> void;
        auto redactorBed() -> void;
};
#endif //* end BED_HPP