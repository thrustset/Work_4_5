#pragma once
#include <cmath>

#include "point.hpp"

template<typename K, typename L>
class Circle {
private:
    Point<K> center;
    L radius;
public:
    Circle();
    [[maybe_unused]] Circle(K x, K y, L radius);
    Circle(Point<K> const &source, L radius);
    [[maybe_unused]] Circle(Circle<K, L> const &source);

    template<typename S, typename T>
    auto friend operator<<(std::ostream &os, Circle<S, T> const &circle) -> std::ostream &;

    auto getCenter() -> Point<K>;
    auto getRadius() -> L;

    auto setCenter(Point<K> const &newCenter) -> void;
    auto setRadius(L newRadius) -> void;

    auto square() -> double;
};

#include "circle.inl"