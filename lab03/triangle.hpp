#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "figure.hpp"

class Triangle: public Figure {
    using Figure::points;
public:
    Triangle() noexcept;
    Triangle(std::initializer_list<std::pair<double, double>>&&);
    Triangle(const double&);
    ~Triangle();

    std::pair<double, double> center() const override;
    explicit operator double() const override;

    friend std::ostream& operator<<(std::ostream&, const Triangle&);
    friend std::istream& operator>>(std::istream&, Triangle&);

    using Figure::operator==;
    // using Figure::operator=;

    Triangle& operator=(const Triangle&) noexcept;
    Triangle& operator=(Triangle&&) noexcept;
};

inline std::istream& operator>>(std::istream& in, Triangle& other) {
    in >> other.points[0].first >> other.points[0].second
    >> other.points[1].first >> other.points[1].second
    >> other.points[2].first >> other.points[2].second;
    return in;
}
