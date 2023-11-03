#pragma once
#include <iostream>
#include <vector>
#include <concepts>

template<typename T>
concept Number = (std::floating_point<T>);

template <Number T>
class Figure {
protected:
    std::vector<std::pair<T, T>> points;
public:
    Figure() noexcept = default;
    ~Figure() = default;

    virtual std::pair<T, T> center() const = 0;
    virtual explicit operator double() const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Figure<T>& other) {
        for (int i = 0; i < other.points.size(); ++i) {
            out << other.points[i].first << ' ' << other.points[i].second << '\n';
        }
        return out;
    }
    
    virtual bool operator==(const Figure<T>& other) const {
        return points == other.points;
    }
};
