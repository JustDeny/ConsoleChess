//
// Created by jimch on 02.03.2022.
//

#include "GameLoop.h"

static const std::vector<std::pair<std::string, std::string>> figureParams
{
        {"WK", "e1"}, {"BK", "e8"},{"WQ", "d1"},{"BQ", "d8"},{"WN", "c1"},{"WN", "f1"},
        {"WB", "c1"},{"WB", "f1"},{"BB", "c8"},{"BB", "f8"},{"WN", "b1"},{"WN", "g1"},{"BN", "b8"},{"BN", "g8"},
        {"WR", "a1"},{"WR", "h1"},{"BR", "a8"},{"BR", "h8"}, {"WP", "a2"},{"WP", "b2"},
        {"WP", "c2"},{"WP", "d2"},{"WP", "e2"},{"WP", "f2"},{"WP", "g2"},{"WP", "h2"},
        {"BP", "a7"},{"BP", "b7"},{"BP", "c7"},{"BP", "d7"},{"BP", "e7"},{"BP", "f7"},
        {"BP", "g7"},{"BP", "h7"}
};

void GameLoop::Init() {
    m_field.Init();
    for (auto& param: figureParams) {
        figures.push_back(createFigure(param.first, param.second));
    }
    for(auto& figure: figures)
    {
        m_field.place(figure->getPosition(), figure->getName());
    }
    currentMove = false;
}

void GameLoop::Run() {
    this->Init();
    while(true)
    {
        Draw();
        Update();
    }
}
void GameLoop::Update() {
    std::string figurePos;
    currentMove? std::cout << "It's move of black figures" << std::endl:
    std::cout << "It's move of white figures" << std::endl;
    bool validFigure;
    do
    {
        std::cout << "Position of figure to move: ";
        std::getline(std::cin,figurePos);
        if(!currentMove)
        {
            validFigure = m_field.getStateOfCell(m_field.getCell(figurePos)) == Color::WHITE;
        }
        else
        {
            validFigure = m_field.getStateOfCell(m_field.getCell(figurePos)) == Color::BLACK;
        }
    }while(!validFigure || (figurePos.find(' ') != std::string::npos));
    currentMove = !currentMove;
    std::string movement;
    do
    {
        std::cout << "Cell to move to: ";
        std::getline(std::cin,movement);
    }while(movement.find(' ') != std::string::npos);
    for (auto& figure: figures) {
        if(figure->getPosition() == figurePos)
        {
            figure->move(movement, m_field);
        }
    }
}

void GameLoop::Draw() {
    system("cls");
    m_field.draw();
}
