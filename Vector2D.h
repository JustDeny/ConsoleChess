//
// Created by jimch on 02.03.2022.
//

#ifndef VECTOR2D_H
#define VECTOR2D_H


class Vector2D{
public:
    Vector2D(int x, int y);
    Vector2D();
    int x, y;
    bool operator!=(const Vector2D& rhs)const;
    Vector2D& operator+=(const Vector2D& rhs);
    bool operator==(const Vector2D& rhs)const;
};


#endif //VECTOR2D_H
