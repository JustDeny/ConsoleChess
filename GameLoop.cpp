//
// Created by jimch on 02.03.2022.
//

#include <algorithm>
#include "GameLoop.h"

static const std::vector<std::pair<std::string, std::string>> PositionsOfFigures
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
    for (auto& param: PositionsOfFigures) {
        figures.push_back(createFigure(param.first, param.second));
    }
    for(auto& figure: figures)
    {
        m_field.place(figure->getPosition(), figure->getName());
    }
    currentMove = false;
    play = true;
    capturedBlack = 0;
    capturedWhite = 0;
}

void GameLoop::Run() {
    this->Init();
    while(play)
    {
        Draw();
        Update();
    }
    if(capturedWhite == 16)
    {
        std::cout << "White side has won" << std::endl;
    }
    else if(capturedBlack == 16)
    {
        std::cout << "Black side has won" << std::endl;
    }
    else
        std::cout << "Unfinished game" << std::endl;
}
void GameLoop::Update() {
    std::string figurePos;
    bool validFigure;
    //the loop will be preforming until player chooses his figure
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
    //currentMove = !currentMove;
    std::string movement;
    //until user inputs any characters (further verification will be in class of figure)
    do
    {
        std::cout << "Cell to move to: ";
        std::getline(std::cin,movement);
    }while(movement.find(' ') != std::string::npos);
    bool captured = false;
    for (auto& figure: figures) {
        if(figure->getPosition() == figurePos)
        {
            captured = figure->move(movement, m_field);
            break;
        }
    }
    if(captured)
    {
        auto cmpPos = [&movement](const std::unique_ptr<Figure>& figure){return figure->getPosition() == movement;};
        figures.erase(std::find_if(figures.begin(), figures.end(), cmpPos));
        if(currentMove)
        {
            capturedWhite++;
        }
        else
        {
            capturedBlack++;
        }
        if(capturedWhite == 16 || capturedBlack == 16)
            play = false;
    }
}

void GameLoop::Draw() {
    system("cls");
    m_field.draw();
    std::cout << "Captured white pieces: " << capturedWhite << std::endl;
    std::cout << "Captured black pieces: " << capturedBlack << std::endl;
    currentMove? std::cout << "It's move of black figures" << std::endl:
    std::cout << "It's move of white figures" << std::endl;
}
