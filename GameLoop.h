//
// Created by jimch on 02.03.2022.
//

#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "Field.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
#include "FiguresFactory.h"

class GameLoop {
private:
    Field m_field;
    int capturedWhite;
    int capturedBlack;
    std::vector<std::unique_ptr<Figure>> figures;
    bool currentMove;
public:
    void Init();
    void Run();
    void Update();
    void Draw();
};

#endif //GAMELOOP_H
