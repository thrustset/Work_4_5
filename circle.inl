template<typename K, typename L>
Circle<K, L>::Circle() = default;

template<typename K, typename L>
[[maybe_unused]] Circle<K, L>::Circle(K x, K y, L radius) :
    center{Point(x, y)},
    radius{radius}
{}

template<typename K, typename L>
Circle<K, L>::Circle(Point<K> const &source, L radius) :
    center{Point(source)},
    radius{radius}
{}

template<typename K, typename L>
[[maybe_unused]] Circle<K, L>::Circle(Circle<K, L> const &source) :
    center{Point(source.center)},
    radius{source.radius}
{}

template<typename K, typename L>
auto operator<<(std::ostream &os, Circle<K, L> const &circle) -> std::ostream & {
    os << "Circle:\t";
    os << circle.center;
    os << "\t\tRadius = " << circle.radius << "\n";
    return os;
}

template<typename K, typename L>
auto Circle<K, L>::getCenter() -> Point<K> {
    return center;
}

template<typename K, typename L>
auto Circle<K, L>::getRadius() -> L {
    return radius;
}

template<typename K, typename L>
auto Circle<K, L>::setCenter(Point<K> const &newCenter) -> void {
    center = newCenter;
}

template<typename K, typename L>
auto Circle<K, L>::setRadius(L newRadius) -> void {
    radius = newRadius;
}

template<typename K, typename L>
auto Circle<K, L>::square() -> double {
    return acos(-1) * radius * radius;
}