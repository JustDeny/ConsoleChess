//
// Created by jimch on 03.03.2022.
//

#include "Pawn.h"


Pawn::Pawn(std::string name, std::string init_pos, Color color) : Figure(name, init_pos, color) {

}

bool Pawn::move(std::string destination, Field &field) {
    bool isKilled = false;
    Vector2D startPos = field.getCell(this->getPosition());
    Vector2D dest = field.getCell(destination);
    if(startPos == Vector2D{25,9} && dest == Vector2D{32, 7})
    {
        bool stop;
    }
    int direction;
    if(isWhite())
    {
        direction = dest.y - startPos.y;

    }
    else if(isBlack())
    {
        direction = startPos.y - dest.y;
    }
    if(direction == 4 && !firstMove)
    {
        return false;
    }
    Vector2D diff;
    diff.y = abs(startPos.y - dest.y);
    diff.x = abs(startPos.x - dest.x);
    int limit = diff.y+diff.x;

    if(diff.x == 0 && field.getStateOfCell(dest) != Color::UNKNOWN)
    {
        return false;
    }
    if(diff.y <= 4 && diff.x >= 0 && limit<11 && field.isPathClear(startPos, dest)
        && direction > 0)
    {
        if(field.getStateOfCell(dest) != Color::UNKNOWN && field.getStateOfCell(dest) != this->color)
        {
            isKilled = true;
        }
        field.clearCell(startPos);
        field.place(dest, name);
        position = destination;
    }
    if(firstMove)
        firstMove = false;
    return isKilled;
}

void Pawn::move(Vector2D dest, Field &field) {

}

void Pawn::draw() {

}

void Pawn::update() {

}

void Pawn::init() {

}

bool Pawn::isFirstMove() const {
    return firstMove;
}

bool Pawn::isPathClear(Vector2D startPos, Vector2D dest, Field &field) {
    return false;
}
