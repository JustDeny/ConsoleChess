//
// Created by jimch on 02.03.2022.
//

#include "King.h"

King::King(std::string name, std::string init_pos, Color color) : Figure(name, init_pos, color) {}

bool King::move(std::string destination, Field& field) {
    bool isKilled = false;
    Vector2D startPos = field.getCell(this->getPosition());
    Vector2D dest = field.getCell(destination);
    Vector2D diff;
    diff.y = abs(startPos.y - dest.y);
    diff.x = abs(startPos.x - dest.x);
    if(field.getStateOfCell(dest) == this->color)
        return false;
    if((diff.x <= 7 && diff.y <= 2) && field.isPathClear(startPos, dest))
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

void King::move(Vector2D dest, Field& field) {

}

void King::draw() {
}

void King::update() {

}

void King::init() {
    position = "e1";
}

bool King::isPathClear(Vector2D startPos, Vector2D dest, Field &field) {
    return false;
}

