#include "square.hpp"

Square::Square() noexcept {
    points.resize(4, {0, 0});
}

Square::Square(const double& length) {
    points.resize(4, {0, 0});
    points[0] = std::make_pair(0, 0);
    points[1] = std::make_pair(length, 0);
    points[2] = std::make_pair(length, length);
    points[3] = std::make_pair(0, length);
}

std::pair<double, double> Square::center() const {
    std::pair<double, double> result;
    result.first = result.second = points[2].first / 2;
    return result;
}

inline Square::operator double() const {
    return points[2].first * points[2].second;
}

Square& Square::operator=(const Square& other) noexcept {
    points = other.points;
    return *this;
}
Square& Square::operator=(Square&& other) noexcept {
    points = std::move(other.points);
    return *this;
}

Square::~Square() {
    points.clear();
    points.shrink_to_fit();
}