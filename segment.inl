template<typename K>
Segment<K>::Segment(Point<K> const &point1, Point<K> const &point2) :
    point1{point1},
    point2{point2}
{}

template<typename K>
Segment<K>::Segment(Segment<K> const &segment) :
    point1{segment.point1},
    point2{segment.point2}
{}

template<typename K>
auto Segment<K>::length() -> double {
    return sqrt(pow(point1.getX() - point2.getX(), 2) + pow(point1.getY() - point2.getY(), 2));
}

template<typename K>
auto Segment<K>::midPoint() -> Point<K> {
    return Point<K>((point1.getX() + point2.getX()) / 2, (point1.getY() + point2.getY()) / 2);
}