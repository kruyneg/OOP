#include "octagon.hpp"

Octagon::Octagon() noexcept {
    points.resize(8);
}

Octagon::Octagon(const double& length) {
    points.resize(8);
    points[0] = {length * std::sin(M_PI / 4), 0};
    points[1] = {length + length * std::sin(M_PI / 4), 0};
    points[2] = {
        length + 2 * length * std::sin(M_PI / 4),
        length * std::sin(M_PI / 4)};
    points[3] = {
        length + 2 * length * std::sin(M_PI / 4),
        length + length * std::sin(M_PI / 4)};
    points[4] = {
        length + length * std::sin(M_PI / 4),
        length + 2 * length * std::sin(M_PI / 4)};
    points[5] = {
        length * std::sin(M_PI / 4),
        length + 2 * length * std::sin(M_PI / 4)};
    points[6] = {0, length + length * std::sin(M_PI / 4)};
    points[7] = {0, length * std::sin(M_PI / 4)};
}

std::pair<double, double> Octagon::center() const {
    std::pair<double, double> result;
    result.first = result.second = points[2].first / 2;
    return result;
}

inline Octagon::operator double() const {
    return (points[2].first * points[2].first) - 2 * (points[0].first * points[0].first);
}


Octagon& Octagon::operator=(const Octagon& other) noexcept {
    points = other.points;
    return *this;
}
Octagon& Octagon::operator=(Octagon&& other) noexcept {
    points = other.points;
    other.points.clear();
    other.points.shrink_to_fit();
    return *this;
}
Octagon::~Octagon() {
    points.clear();
    points.shrink_to_fit();
}