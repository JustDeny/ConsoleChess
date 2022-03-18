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
    if(diff.x == 7 && diff.y == 4 && field.isPathClear(startPos, dest))
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
