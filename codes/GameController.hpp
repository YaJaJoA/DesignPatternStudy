#ifndef A14E5A39_4020_44AB_BDAE_213407EF7492
#define A14E5A39_4020_44AB_BDAE_213407EF7492
#include "InputController.h"
#include "MazeGame.hpp"
#include "Mazes/Maze.h"

using BaseMazeComponents::Direction;

class MainGameController{
    public:
    MainGameController();
    ~MainGameController();

    void InitializeGame();
    void StartLoop();
    void ClearGame();

    private:
    InputController* inputController;
    MazeGames::MazeGame* mazeGame;
};

MainGameController::MainGameController(){
    // setting for printing unicode characters
    std::locale::global(std::locale("en_US.utf8")); 
    std::wcout.imbue(std::locale());
    system("clear");

    inputController = InputController::GetInstance(); // get singletone object
    mazeGame = new MazeGames::MazeGame();
}

MainGameController::~MainGameController(){
    ClearGame();
}

void MainGameController::ClearGame(){
    delete mazeGame;
}

void MainGameController::InitializeGame(){
    MazeGames::MazeGameBuilder* game = new MazeGames::MazeGameBuilder();

    BaseMazeFactory BaseFactory;

    mazeGame->SetMaze(game->CreateMaze(BaseFactory));
    mazeGame->SetPlayer(new Player::PlayerCharacter());
    
    mazeGame->Start();
}

void MainGameController::StartLoop(){

    auto input = inputController->MainKeyboardLoop();

    while(input != 'q'){

        switch(input){
            case 'w':
                //Move Up
                if (mazeGame->TryMovePlayer(Direction::North))
                    mazeGame->UpdateDraw();
                break;
            case 'a':
                //Move Left
                if (mazeGame->TryMovePlayer(Direction::West))
                    mazeGame->UpdateDraw();
                break;
            case 's':
                //Move Down
                if (mazeGame->TryMovePlayer(Direction::South))
                    mazeGame->UpdateDraw();
                break;
            case 'd':
                //Move Right
                if (mazeGame->TryMovePlayer(Direction::East))
                    mazeGame->UpdateDraw();
                break;
            default:
                break;
        }
        input = inputController->MainKeyboardLoop();
    }
}

#endif /* A14E5A39_4020_44AB_BDAE_213407EF7492 */
