#pragma once
#include <iostream>
#include <vector>

class Figure {
protected:
    std::vector<std::pair<double, double>> points;
public:
    Figure() noexcept;
    ~Figure();

    virtual std::pair<double, double> center() const = 0;
    virtual explicit operator double() const = 0;

    friend std::ostream& operator<<(std::ostream&, const Figure&);
    friend std::istream& operator>>(std::istream&, Figure&);

    virtual bool operator==(const Figure&) const;
};

inline std::ostream& operator<<(std::ostream& out, const Figure& other) {
    for (int i = 0; i < other.points.size(); ++i) {
        out << other.points[i].first << ' ' << other.points[i].second << '\n';
    }
    return out;
}