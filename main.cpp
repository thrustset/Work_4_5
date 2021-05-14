#include <iostream>
#include <cmath>

#include "point.hpp"
#include "circle.hpp"
#include "couple.hpp"

auto main() -> int {
    auto p1 = Point<char>(-1, 1);
    auto p2 = Point<char>(2, 5);

    char R1 = 3;
    char R2 = 2;

    auto circ1 = Circle<char, char>(p1, R1);
    auto circ2 = Circle<char, char>(p2, R2);

    auto couple = Couple(circ1, circ2);
    std::cout << couple;

    std::cout << "\nTANGENT CIRCLES:\n";
    for(int i = 0; i < 4; i++)
        std::cout << couple.tangentCircles()[i];

    double min_sq = pow(10, 12), max_sq = 0;
    for(int i = 0; i < 4; i++) {
        if(couple.tangentCircles()[i].square() > max_sq)
            max_sq = couple.tangentCircles()[i].square();
        if(couple.tangentCircles()[i].square() < min_sq)
            min_sq = couple.tangentCircles()[i].square();
    }

    std::cout << "\nMIN SQUARE = " << min_sq << "\n";
    std::cout << "MAX SQUARE = " << max_sq << "\n";
    std::cout << "DIFFERENCE = " << max_sq - min_sq << "\n";
    return 0;
}