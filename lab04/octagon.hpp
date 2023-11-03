#pragma once
#include <iostream>
#include <cmath>
#include "figure.hpp"

template<Number T>
class Octagon: public Figure<T> {
    using Figure<T>::points;
public:
    Octagon() noexcept {
        points.resize(8, {0, 0});
    }
    Octagon(const T& length) {
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
    Octagon(const Octagon<T>& other) {
        points = other.points;

    }
    ~Octagon() {
        points.clear();
        points.shrink_to_fit();
    }

    std::pair<T, T> center() const override {
        std::pair<T, T> result;
        result.first = result.second = points[2].first / 2;
        return result;
    }
    explicit operator double() const override {
        return (points[2].first * points[2].first) - 2 * (points[0].first * points[0].first);
    }

    friend std::istream& operator>>(std::istream& in, Octagon<T>& other) {
        T length;
        in >> length;
        other = Octagon<T>(length);
        return in;
    }

    using Figure<T>::operator==;

    Octagon<T>& operator=(const Octagon<T>& other) noexcept {
        points = other.points;
        return *this;
    }
    Octagon<T>& operator=(Octagon<T>&& other) noexcept {
        points = std::move(other.points);
        return *this;
    }
};
