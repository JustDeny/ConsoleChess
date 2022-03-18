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

     /*
    else if(isWhite() && diff.y == 2 && !diff.x
            && (field.getStateOfCell(dest) == Color::WHITE||field.getStateOfCell(dest) == Color::BLACK))
    {
        return false;
    }
    else if(isBlack() && diff.y == 2 && !diff.x
            && (field.getStateOfCell(dest) == Color::WHITE || field.getStateOfCell(dest) == Color::BLACK))
    {
        return false;
    }*/
    if(diff.x == 0 && field.getStateOfCell(dest) != Color::UNKNOWN)
    {
        return false;
    }
    if(diff.y <= 4 && diff.x >= 0 && limit<11 && field.isPathClear(startPos, dest)
        && direction > 0)
    {
        field.clearCell(startPos);
        if(field.getStateOfCell(dest) == Color::WHITE || field.getStateOfCell(dest) == Color::BLACK)
            isKilled = true;
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

bool Pawn::isPathClear(Vector2D startPos, Vector2D dest, Field& field) {
    if(abs(dest.y - startPos.y) && !abs(dest.x - startPos.x) && field.getStateOfCell(dest) != Color::UNKNOWN)
    {
        return false;
    }
    else if(abs(dest.x - startPos.x) != 0 && (field.getStateOfCell(dest) == Color::UNKNOWN ||
        field.getStateOfCell(dest) == color))
    {
        return false;
    }
    else if(isWhite() && abs(dest.y - startPos.y) == 2 && abs(dest.x - startPos.x) == 0
        && (field.getStateOfCell(dest) == Color::WHITE||field.getStateOfCell(dest) == Color::BLACK))
    {
        return false;
    }
    else if(isBlack() && abs(dest.y - startPos.y) == 2 && abs(dest.x - startPos.x) == 0
        && (field.getStateOfCell(dest) == Color::WHITE || field.getStateOfCell(dest) == Color::BLACK))
    {
        return false;
    }
    return true;
}

bool Pawn::isFirstMove() const {
    return firstMove;
}
