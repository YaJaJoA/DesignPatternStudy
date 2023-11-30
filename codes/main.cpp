#include <iostream>
#include <string>

#include "Mazes/Maze.h"
#include "Mazes/MazeFactory.h"
#include "MazeGame.hpp"
#include "Mazes/Prototype/MazePrototypeFactory.h"
#include "MazeView.hpp"

using namespace BaseMazeFactories;
using namespace MazeGames;

int main(){
    // setting for printing unicode characters
    std::locale::global(std::locale("en_US.utf8")); 
    std::wcout.imbue(std::locale());

    // game
    MazeView mazeView;
    MazeGame* game = new MazeGame();

    BaseMazeFactory BaseFactory;

    Maze* maze1 = game->CreateMaze(BaseFactory);

    std::wcout << "<<< Maze 1 >>>" << std::endl;
    mazeView.SetMaze(maze1);
    mazeView.Draw();


    //Prototype Pattern
    BasePrototypeFactory::MazePrototypeFactory PrototypeFactory(new Maze(), new Wall(), new Room(0), new Door());
    Maze* maze2 = game->CreateMaze(PrototypeFactory);

    std::wcout << "<<< Maze 2 >>>" << std::endl;
    mazeView.SetMaze(maze2);
    mazeView.Draw();

    std::cout << "Hello World!" << std::endl;

    return 0;
}
