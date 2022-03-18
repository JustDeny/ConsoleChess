//
// Created by jimch on 03.03.2022.
//
#include "FiguresFactory.h"
#include <iostream>

std::unique_ptr<Figure> createFigure(std::string name, std::string pos)
{
    Color color;
    if(std::toupper(name[0] == 'W'))
    {
        color = Color::WHITE;
    }
    else if(std::toupper(name[0] == 'B'))
    {
        color = Color::BLACK;
    }

    switch(std::toupper(name[1]))
    {
        case 'P': return std::make_unique<Pawn>(Pawn{name, pos, color});
        case 'R': return std::make_unique<Rook>(Rook{name, pos, color});
        case 'N': return std::make_unique<Knight>(Knight{name, pos, color});
        case 'B': return std::make_unique<Bishop>(Bishop{name, pos, color});
        case 'Q': return std::make_unique<Queen>(Queen{name, pos, color});
        case 'K': return std::make_unique<King>(King{name, pos, color});
    }
    return nullptr;
}


