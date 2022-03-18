//
// Created by jimch on 03.03.2022.
//

#include "Bishop.h"

Bishop::Bishop(std::string name, std::string init_pos, Color color) : Figure(name, init_pos, color) {

}

bool Bishop::move(std::string destination, Field &field) {
    return true;
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
