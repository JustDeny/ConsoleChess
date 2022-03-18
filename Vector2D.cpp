//
// Created by jimch on 02.03.2022.
//

#include "Vector2D.h"

Vector2D::Vector2D(): x{0}, y{0} {}
Vector2D::Vector2D(int x, int y): x{x}, y{y} {}

bool Vector2D::operator!=(const Vector2D &rhs) const {
    if(x != rhs.x || y != rhs.y)
        return true;
    return false;
}

Vector2D& Vector2D::operator+=(const Vector2D& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}

bool Vector2D::operator==(const Vector2D &rhs) const {
    if(x == rhs.x && y == rhs.y)
        return true;
    return false;
}
