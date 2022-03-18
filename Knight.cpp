//
// Created by jimch on 03.03.2022.
//

#include "Knight.h"

Knight::Knight(std::string name, std::string init_pos, Color color) : Figure(name, init_pos, color) {

}

bool Knight::move(std::string destination, Field &field) {
    bool isKilled = false;
    Vector2D startPos = field.getCell(this->getPosition());
    Vector2D dest = field.getCell(destination);
    Vector2D diff;
    diff.y = abs(startPos.y - dest.y);
    diff.x = abs(startPos.x - dest.x);
    if(field.getStateOfCell(dest) == this->color)
        return false;
    if((diff.x == 7 && diff.y == 4) || (diff.x == 14 && diff.y == 2))
    {
        field.clearCell(startPos);
        field.place(dest,name);
        position = destination;
        if(field.getStateOfCell(dest) == Color::WHITE || field.getStateOfCell(dest) == Color::BLACK)
        {
            isKilled = true;
        }
    }
    return isKilled;
}

void Knight::move(Vector2D dest, Field &field) {

}

void Knight::draw() {

}

void Knight::update() {

}

void Knight::init() {

}

bool Knight::isPathClear(Vector2D startPos, Vector2D dest, Field &field) {
    return false;
}
