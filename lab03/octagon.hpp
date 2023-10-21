#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "figure.hpp"

class Octagon: public Figure {
    using Figure::points;
public:
    Octagon() noexcept;
    Octagon(const double&);
    ~Octagon();

    std::pair<double, double> center() const override;
    explicit operator double() const override;

    friend std::istream& operator>>(std::istream&, Octagon&);

    using Figure::operator==;

    Octagon& operator=(const Octagon&) noexcept;
    Octagon& operator=(Octagon&&) noexcept;
};

inline std::istream& operator>>(std::istream& in, Octagon& other) {
    double length;
    in >> length;
    other = Octagon(length);
    return in;
}
