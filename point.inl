template<typename K>
Point<K>::Point() = default;

template<typename K>
Point<K>::Point(K x, K y) : x{x}, y{y} {}

template<typename K>
Point<K>::Point(Point<K> const &source) : x{source.x}, y{source.y} {}

template<typename K>
auto operator<<(std::ostream &os, Point<K> const &point) -> std::ostream & {
    os << "Point: (" << point.x << "; " << point.y << ")\n";
    return os;
}

template<typename K>
auto Point<K>::operator=(Point<K> const &point) -> Point<K> & {
    x = point.x;
    y = point.y;
}

template<typename K>
auto Point<K>::getX() -> K {
    return x;
}

template<typename K>
auto Point<K>::getY() -> K {
    return y;
}

template<typename K>
auto Point<K>::setX(K newX) -> void {
    x = newX;
}

template<typename K>
auto Point<K>::setY(K newY) -> void {
    y = newY;
}