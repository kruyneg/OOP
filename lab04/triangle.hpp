#pragma once
#include <iostream>
#include <cmath>
#include <stdexcept>
#include "figure.hpp"

template<Number T>
class Triangle: public Figure<T> {
    using Figure<T>::points;
public:
    Triangle() noexcept {
        points.resize(3, {0, 0});
    }
    Triangle(std::initializer_list<std::pair<T, T>>&& list) {
        if (list.size() > 3)
            throw std::invalid_argument("Too many points\n");
        else if (list.size() < 3)
            throw std::invalid_argument("Too few points\n");

        points.resize(3);
        int i = 0;
        for (std::pair<T, T> elem : list) {
            points[i].first = elem.first;
            points[i].second = elem.second;
            ++i;
        }

    }
    Triangle(const T& length) {
        points.resize(3);
        points[0] = {0, 0};
        points[1] = {length, 0};
        points[2] = {length / 2, length * std::sin(M_PI / 3)};
    }
    Triangle(const Triangle<T>& other) {
        points = other.points;
    }
    ~Triangle() {
        points.clear();
        points.shrink_to_fit();
    }

    std::pair<T, T> center() const override {
        std::pair<T, T> result;
        result.first = (points[0].first + points[1].first + points[2].first) / 3;
        result.second = (points[0].second + points[1].second + points[2].second) / 3;
        return result;
    }
    explicit operator double() const override {
        return 0.5 * (
            points[0].first * (points[1].second - points[2].second)
            + points[1].first * (points[2].second - points[0].second)
            + points[0].first * (points[0].second - points[1].second)
            );
    }

    friend std::istream& operator>>(std::istream& in, Triangle<T>& other) {
        in >> other.points[0].first >> other.points[0].second
        >> other.points[1].first >> other.points[1].second
        >> other.points[2].first >> other.points[2].second;
        return in;
    }

    using Figure<T>::operator==;

    Triangle& operator=(const Triangle<T>& other) noexcept {
        points = other.points;
        return *this;
    }
    Triangle& operator=(Triangle<T>&& other) noexcept {
        points = std::move(other.points);
        return *this;
    }
};
