#pragma once

template<typename K>
class Point {
private:
    K x;
    K y;
public:
    Point();
    Point(K x, K y);
    Point(Point<K> const &source);

    template<typename L>
    auto friend operator<<(std::ostream &os, Point<L> const &point) -> std::ostream &;

    auto operator=(Point<K> const &point) -> Point<K> &;

    auto getX() -> K;
    auto getY() -> K;

    auto setX(K newX) -> void;
    auto setY(K newY) -> void;
};

#include "point.inl"