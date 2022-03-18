//
// Created by jimch on 03.03.2022.
//

#include "Queen.h"

Queen::Queen(std::string name, std::string init_pos, Color color) : Figure(name, init_pos, color) {

}

bool Queen::move(std::string destination, Field &field) {
    bool isKilled = false;
    Vector2D startPos = field.getCell(this->getPosition());
    Vector2D dest = field.getCell(destination);
    Vector2D diff;
    diff.y = abs(startPos.y - dest.y);
    diff.x = abs(startPos.x - dest.x);
    if(field.getStateOfCell(dest) == this->color)
        return false;
    if(field.isPathClear(startPos, dest))
    {
        field.clearCell(startPos);
        field.place(dest, name);
        position = destination;
        if(field.getStateOfCell(dest) == Color::WHITE || field.getStateOfCell(dest) == Color::BLACK)
        {
            isKilled = true;
        }
    }
    return isKilled;
}

void Queen::move(Vector2D dest, Field &field) {

}

void Queen::draw() {

}

void Queen::update() {

}

void Queen::init() {

}

bool Queen::isPathClear(Vector2D startPos, Vector2D dest, Field &field) {
    return false;
}
