//
// Created by jimch on 02.03.2022.
//

#include "Field.h"
#include <algorithm>
#include <string>

Field::Field() {
    Init();
}

void Field::Init() {
    m_field[0] = " +------+------+------+------+------+------+------+------+\n";
    for (int i = 0, even = 2, odd = 1, num = 0; i < 16; ++i) {
        if(i % 2 == 0)
        {
            m_field[even] = " +------+------+------+------+------+------+------+------+\n";
            even+= 2;
        }
        else
        {
            m_field[odd] = std::to_string(num+1) + "|      |      |      |      |      |      |      |      |"
                    + std::to_string(num+1) + "\n";
            odd += 2;
            num++;
        }
    }
}

void Field::draw() {
    std::cout << "     A      B      C      D      E      F      G      H   \n";
    for (int i = 16; i >= 0; --i) {
        std::cout << m_field[i];
    };
    std::cout << "     A      B      C      D      E      F      G      H   \n";
}

void Field::update() {

}

bool Field::isKilled() {
    return false;
}

Vector2D Field::getCell(const std::string &pos) {
    int x = 4; //don't pay attention,cuz it's kind of mess in my implementation of the chess board
    int y;
    switch(toupper(pos[0]))
    {
        case 'A':
            //coord is specified initially in x
            break;
        case 'B':
            x += 7;
            break;
        case 'C':
            x += 14;
            break;
        case 'D':
            x += 21;
            break;
        case 'E':
            x += 28;
            break;
        case 'F':
            x += 35;
            break;
        case 'G':
            x += 42;
            break;
        case 'H':
            x += 49;
            break;
        default:
            return Vector2D{-1,-1};
    }
    if(atoi(&pos[1]) > 8 || atoi(&pos[1]) < 1 )
        return Vector2D{-1,-1};
    //cells placed only in odd rows
    y = (atoi(&pos[1])*2)-1;
    return Vector2D{x,y};
}

bool Field::isPathClear(Vector2D startPos, Vector2D dest) {
    Vector2D dist;
    dist.x = dest.x - startPos.x;
    dist.y = dest.y - startPos.y;
    if(dist.x != 0 && dist.y != 0 && abs(dist.x)/7 != abs(dist.y)/2)
        return false;
    Vector2D counter = startPos;
    Vector2D step;
    if(dist.x > 0)  step.x = 7;
    else if(dist.x < 0) step.x = -7;
    else    step.x = 0;

    if(dist.y > 0)  step.y = 2;
    else if(dist.y < 0) step.y = -2;
    else    step.y = 0;\

    counter+=step;
    while(counter != dest)
    {
        if(getStateOfCell(counter) != Color::UNKNOWN)
        {
            return false;
        }
        counter+= step;
    }
    return true;
}

bool Field::place(std::string position, std:: string name) {
    Vector2D pos = this->getCell(position);
    m_field[pos.y].replace(pos.x, 2, name, 0, 2);
    return true;
}

bool Field::place(Vector2D position, std::string name) {
    m_field[position.y].replace(position.x, 2, name, 0, 2);
    return true;
}

void Field::clearCell(Vector2D& cell) {
    m_field[cell.y].replace(cell.x, 2, "  ", 0, 2);
}

Color Field::getStateOfCell(Vector2D cell) {
    if(m_field[cell.y][cell.x] == 'W')
        return Color::WHITE;
    else if(m_field[cell.y][cell.x] == 'B')
        return Color::BLACK;
    return Color::UNKNOWN;
}
