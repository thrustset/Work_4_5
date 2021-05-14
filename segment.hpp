#pragma once
#include <cmath>

#include "point.hpp"

template<typename K>
class Segment {
private:
    Point<K> point1;
    Point<K> point2;
public:
    Segment(Point<K> const &point1, Point<K> const &point2);
    Segment(Segment<K> const &segment);

    auto length() -> double;
    auto midPoint() -> Point<K>;
};

#include "segment.inl"