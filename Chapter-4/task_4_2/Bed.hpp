//*description bed
#pragma once

#ifndef BED_HPP //task_4_3
#define BED_HPP //task_4_3

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
        auto printInformation() const noexcept -> void;
        auto redactorBed() -> void;
};
#endif //* end BED_HPP(task_4_3)