//
// Created by jimch on 02.03.2022.
//

#ifndef KING_H
#define KING_H
#include "Figure.h"

class King: public Figure
{
public:
    explicit King(std::string name, std::string init_pos, Color color);
    bool move(std::string dest, Field& field) override;
    void move(Vector2D dest, Field& field) override;
    bool isPathClear(Vector2D startPos, Vector2D dest, Field& field) override;
    void init() override;
    void draw() override;
    void update() override;
};


#endif //KING_H
