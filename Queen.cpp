//
// Created by jimch on 03.03.2022.
//

#include "Queen.h"

Queen::Queen(std::string name, std::string init_pos, Color color) : Figure(name, init_pos, color) {

}

bool Queen::move(std::string destination, Field &field) {
    return true;
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
