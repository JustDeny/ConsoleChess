//
// Created by jimch on 02.03.2022.
//

#ifndef FIGURE_H
#define FIGURE_H

#include "Vector2D.h"
#include <iostream>
#include "Field.h"

class Figure {
public:
    Figure(std::string name, std::string pos, Color col):name{name}, position{pos}, color{col}{};
    ~Figure() = default;
    virtual void move(Vector2D, Field&) = 0;
    virtual bool move(std::string, Field&) = 0;
    virtual void init() = 0;
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual bool isPathClear(Vector2D, Vector2D, Field&) = 0;
    bool isBlack(){return color == Color::BLACK;}
    bool isWhite(){return color == Color::WHITE;}
    const std::string& getPosition() { return position; }
    const std::string& getName() { return name; }
protected:
    std::string position;
    std::string name;
    Color color;
};

#endif //FIGURE_H
