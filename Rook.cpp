//
// Created by jimch on 03.03.2022.
//

#include "Rook.h"

Rook::Rook(std::string name, std::string init_pos, Color color) : Figure(name, init_pos, color) {

}

bool Rook::move(std::string destination, Field &field) {
    bool isKilled = false;
    Vector2D startPos = field.getCell(this->getPosition());
    Vector2D dest = field.getCell(destination);
    Vector2D diff;
    diff.y = abs(startPos.y - dest.y);
    diff.x = abs(startPos.x - dest.x);
    if((diff.x && !diff.y || !diff.x && diff.y) && field.isPathClear(startPos, dest))
    {
        if(field.getStateOfCell(dest) != Color::UNKNOWN && field.getStateOfCell(dest) != this->color)
        {
            isKilled = true;
        }
        field.clearCell(startPos);
        field.place(dest,name);
        position = destination;
    }
    return isKilled;
}

void Rook::move(Vector2D dest, Field &field) {

}

void Rook::draw() {

}

void Rook::update() {

}

void Rook::init() {
}

bool Rook::isPathClear(Vector2D startPos, Vector2D dest, Field &field){
    return true;
}
