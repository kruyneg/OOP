#include "triangle.hpp"

Triangle::Triangle() noexcept {
    points.resize(3, {0, 0});
}
Triangle::Triangle(std::initializer_list<std::pair<double, double>>&& list) {
    if (list.size() > 3)
        throw std::invalid_argument("Too many points\n");
    else if (list.size() < 3)
        throw std::invalid_argument("Too few points\n");

    points.resize(3);
    int i = 0;
    for (std::pair<double, double> elem : list) {
        points[i].first = elem.first;
        points[i].second = elem.second;
        ++i;
    }
}
Triangle::Triangle(const double& length) {
    points.resize(3);
    points[0] = {0, 0};
    points[1] = {length, 0};
    points[2] = {length / 2, length * std::sin(M_PI / 3)};
}

std::pair<double, double> Triangle::center() const {
    std::pair<double, double> result;
    result.first = (points[0].first + points[1].first + points[2].first) / 3;
    result.second = (points[0].second + points[1].second + points[2].second) / 3;
    return result;
}

inline Triangle::operator double() const {
    return 0.5 * (
        points[0].first * (points[1].second - points[2].second)
        + points[1].first * (points[2].second - points[0].second)
        + points[0].first * (points[0].second - points[1].second)
        );
}


Triangle& Triangle::operator=(const Triangle& other) noexcept {
    points = other.points;
    return *this;
}
Triangle& Triangle::operator=(Triangle&& other) noexcept {
    points = other.points;
    other.points.clear();
    other.points.shrink_to_fit();
    return *this;
}

Triangle::~Triangle() {
    points.clear();
    points.shrink_to_fit();
}