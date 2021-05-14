#pragma once
#include <cmath>

#include "point.hpp"
#include "circle.hpp"
#include "segment.hpp"

template<typename K, typename L>
class Couple {
private:
    Circle<K, L> circle1;
    Circle<K, L> circle2;
public:
    Couple(Circle<K, L> const &sourceCircle1, Circle<K, L> const &sourceCircle2);
    Couple(Couple<K, L> const &sourceCouple);

    template<typename P, typename R>
    auto friend operator<<(std::ostream &os, Couple<P, R> const &couple) -> std::ostream &;

    auto spaceBetween() -> double;
    auto tangentCircles() -> Circle<K, L> * ;
};

#include "couple.inl"