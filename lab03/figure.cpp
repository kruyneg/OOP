#include "figure.hpp"

Figure::Figure() noexcept : points(0) {}

bool Figure::operator==(const Figure& other) const  {
    return points == other.points;
}
Figure::~Figure() {
    points.clear();
    points.shrink_to_fit();
}