template<typename K, typename L>
Couple<K, L>::Couple(Circle<K, L> const &sourceCircle1, Circle<K, L> const &sourceCircle2) :
    circle1{sourceCircle1},
    circle2{sourceCircle2}
{}

template<typename K, typename L>
[[maybe_unused]] Couple<K, L>::Couple(const Couple<K, L> &sourceCouple) :
    circle1{sourceCouple.circle1},
    circle2{sourceCouple.circle2}
{}

template<typename K, typename L>
auto operator<<(std::ostream &os, Couple<K, L> const &couple) -> std::ostream & {
    os << "Couple:\t";
    os << couple.circle1;
    os << "\t\t" << couple.circle2;
    return os;
}

template<typename K, typename L>
auto Couple<K, L>::spaceBetween() -> double {
    auto centerLine = Segment(circle1.getCenter(), circle2.getCenter());
    return centerLine.length();
}

template<typename K, typename L>
auto Couple<K, L>::tangentCircles() -> Circle<K, L> * {
    auto *x = new K[2];
    x[0] = circle1.getCenter().getX();
    x[1] = circle2.getCenter().getX();

    auto *y = new K[2];
    y[0] = circle1.getCenter().getY();
    y[1] = circle2.getCenter().getY();

    auto *R = new L[2];
    R[0] = circle1.getRadius();
    R[1] = circle2.getRadius();

    double r = spaceBetween();

    auto *tanCircs = new Circle<K, L>[4];
    auto **tangencyPoint = new Point<K>*[2];

    for(int i = 0; i < 2; i++) {
        tangencyPoint[i] = new Point<K>[2];
        for(int j = 0; j < 2; j++) {
            tangencyPoint[i][j].setX(x[i] + pow(-1, j) * R[i] / r * (x[1] - x[0]));
            tangencyPoint[i][j].setY(y[i] + pow(-1, j) * R[i] / r * (y[1] - y[0]));
        }
    }

    for(int i = 0; i < 4; i++) {
        auto tmpSegment = Segment<K>(tangencyPoint[0][i / 2], tangencyPoint[1][i % 2]);
        tanCircs[i].setCenter(tmpSegment.midPoint());
        tanCircs[i].setRadius(0.5 * tmpSegment.length());
    }

    delete [] x;
    delete [] y;
    delete [] R;
    for(int i = 0; i < 2; i++)
        delete [] tangencyPoint[i];
    delete [] tangencyPoint;

    return tanCircs;
}