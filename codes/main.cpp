#include <iostream>
#include <string>

#include "Mazes/Maze.h"
#include "Mazes/MazeFactory.h"
#include "MazeGame.hpp"

using namespace BaseMazeFactories;
using namespace MazeGames;

int main(){
    BaseMazeComponents::Room room(0);

    MazeGame* game = new MazeGame();

    BaseMazeFactory BaseFactory;

    game->CreateMaze(BaseFactory);

    std::cout << "Hello World!" << std::endl;

    return 0;
}
