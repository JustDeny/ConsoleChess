//
// Created by jimch on 03.03.2022.
//

#include "Knight.h"

Knight::Knight(std::string name, std::string init_pos, Color color) : Figure(name, init_pos, color) {

}

bool Knight::move(std::string dest, Field &field) {
    return true;
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
