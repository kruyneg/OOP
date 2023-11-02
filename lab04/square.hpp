#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "figure.hpp"

template<Number T>
class Square: public Figure<T> {
    using Figure<T>::points;
public:
    Square() noexcept {
        points.resize(4, {0, 0});
    }
    Square(const T& length) {
        points.resize(4, {0, 0});
        points[0] = std::make_pair(0, 0);
        points[1] = std::make_pair(length, 0);
        points[2] = std::make_pair(length, length);
        points[3] = std::make_pair(0, length);
    }
    Square(const Square<T>& other) {
        points = other.points;
    }
    ~Square() {
        points.clear();
        points.shrink_to_fit();
    }

    std::pair<T, T> center() const override {
        std::pair<T, T> result;
        result.first = result.second = points[2].first / 2;
        return result;
    }
    explicit operator double() const override {
        return points[2].first * points[2].second;
    }

    friend std::istream& operator>>(std::istream& in, Square<T>& other) {
        T length;
        in >> length;
        other = Square<T>(length);
        return in;
    }

    using Figure<T>::operator==;

    Square<T>& operator=(const Square<T>& other) noexcept {
        points = other.points;
        return *this;
    }
    Square<T>& operator=(Square<T>&&other) noexcept {
        points = std::move(other.points);
        return *this;
    }
};
