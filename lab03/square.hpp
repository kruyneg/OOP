#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "figure.hpp"

class Square: public Figure {
    using Figure::points;
public:
    Square() noexcept;
    Square(const double&);
    ~Square();

    std::pair<double, double> center() const override;
    explicit operator double() const override;

    friend std::istream& operator>>(std::istream&, Square&);

    using Figure::operator==;

    Square& operator=(const Square&) noexcept;
    Square& operator=(Square&&) noexcept;
};

inline std::istream& operator>>(std::istream& in, Square& other) {
    double length;
    in >> length;
    other = Square(length);
    return in;
}
