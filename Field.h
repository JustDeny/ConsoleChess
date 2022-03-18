//
// Created by jimch on 02.03.2022.
//

#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <vector>
#include "Vector2D.h"

enum class Color: uint8_t
{
    WHITE,
    BLACK,
    UNKNOWN,
};
class Field {
private:
    std::string m_field[17];
public:
    Field();
    void Init();
    void update();
    void draw();
    bool isPathClear(Vector2D startPos, Vector2D dest);
    bool isKilled();
    Vector2D getCell(const std::string& pos);
    Color getStateOfCell(Vector2D cell);
    bool place(std::string position, std:: string name);
    bool place(Vector2D position, std:: string name);
    void clearCell(Vector2D& cell);
};


#endif //FIELD_H
