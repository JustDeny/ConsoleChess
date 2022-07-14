//
// Created by jimch on 03.03.2022.
//

#ifndef FIGURESFACTORY_H
#define FIGURESFACTORY_H

#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include <memory>

std::unique_ptr<Figure> createFigure(std::string name, std::string pos);
#endif //FIGURESFACTORY_H
