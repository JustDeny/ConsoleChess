//
// Created by jimch on 03.03.2022.
//

#ifndef QUEEN_H
#define QUEEN_H

#include "Figure.h"


class Queen: public Figure {
public:
    explicit Queen(std::string name, std::string init_pos, Color color);
    bool move(std::string destination, Field& field) override;
    void move(Vector2D dest, Field& field) override;
    bool isPathClear(Vector2D startPos, Vector2D dest, Field& field) override;
    void init() override;
    void draw() override;
    void update() override;
};


#endif //QUEEN_H
