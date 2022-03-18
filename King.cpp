//
// Created by jimch on 02.03.2022.
//

#include "King.h"

King::King(std::string name, std::string init_pos, Color color) : Figure(name, init_pos, color) {}

bool King::move(std::string dest, Field& field) {
    return true;
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

