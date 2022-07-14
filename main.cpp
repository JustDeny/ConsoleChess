#include <iostream>
#include "GameLoop.h"
int main() {
    GameLoop game;
    game.Run();
/*    Field field;
    field.Init();
    std::string place = "h4";
    char* ptr = field.getCell(place);
    ptr[0] = 'W';
    ptr[1] = 'K';
    field.draw();*/
    return 0;
}
