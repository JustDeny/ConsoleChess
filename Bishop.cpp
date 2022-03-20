//
// Created by jimch on 03.03.2022.
//

#include "Bishop.h"

Bishop::Bishop(std::string name, std::string init_pos, Color color) : Figure(name, init_pos, color) {

}

bool Bishop::move(std::string destination, Field &field) {
    bool isKilled = false;
    Vector2D startPos = field.getCell(this->getPosition());
    Vector2D dest = field.getCell(destination);
    Vector2D diff;
    diff.y = abs(startPos.y - dest.y);
    diff.x = abs(startPos.x - dest.x);
    if(field.getStateOfCell(dest) == this->color)
        return false;
    if(diff.x/7 == diff.y/2 && field.isPathClear(startPos, dest))
    {
        if(field.getStateOfCell(dest) != Color::UNKNOWN && field.getStateOfCell(dest) != this->color)
        {
            isKilled = true;
        }
        field.clearCell(startPos);
        field.place(dest, name);
        position = destination;
    }
    return isKilled;
}

void Bishop::move(Vector2D dest, Field &field) {

}

void Bishop::draw() {

}

void Bishop::update() {

}

void Bishop::init() {
}

bool Bishop::isPathClear(Vector2D startPos, Vector2D dest, Field &field) {
    return false;
}
