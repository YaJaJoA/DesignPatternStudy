#ifndef AC3ED5B3_0134_4E19_B66E_31076AA9F149
#define AC3ED5B3_0134_4E19_B66E_31076AA9F149

#include "MazeView.hpp"
#include "Mazes/Maze.h"
#include "Mazes/MazeFactory.h"
#include "Character/PlayerCharacter.h"
using namespace BaseMazeComponents;
using namespace BaseMazeFactories;

namespace MazeGames{
    class MazeGameBuilder{
        public:
            Maze* CreateMaze(BaseMazeFactories::BaseMazeFactory& mf); //추상팩토리 예제코드에 맞춰 매개변수 설정
    };    

    // MazeFactory를 매개변수로 받도록 하여, 클래스 이름을 하드코딩하여 생긴 문제를 해결한 함수
    Maze* MazeGameBuilder::CreateMaze (BaseMazeFactories::BaseMazeFactory& factory) {
        Maze* aMaze = factory.MakeMaze();
        Room* r1 = factory.MakeRoom(1);
        Room* r2 = factory.MakeRoom(2);
        Door* aDoor = factory.MakeDoor(r1,r2);

        aMaze->AddRoom(r1);
        aMaze->AddRoom(r2);

        r1->SetSide(North, factory.MakeWall());
        r1->SetSide(East, aDoor);
        r1->SetSide(South, factory.MakeWall());
        r1->SetSide(West, factory.MakeWall());

        r2->SetSide(North, factory.MakeWall());
        r2->SetSide(East, factory.MakeWall());
        r2->SetSide(South, factory.MakeWall());
        r2->SetSide(West, aDoor);

        return aMaze;
    }

    class MazeGame{
        public:
            MazeGame();
            ~MazeGame();

            void Start();
            void End();
            void SetMaze(Maze* Maze);
            void ClearMaze();
            void SetPlayer(Player::PlayerCharacter* player);
            bool TryMovePlayer(Direction direction);
            // void PrintCurrentRoom();
            void UpdateDraw();

        private:
            MazeView* mazeView;
            Maze* currentMaze;
            Player::PlayerCharacter* player;
    };

    MazeGame::MazeGame(){
        mazeView = new MazeView();
        currentMaze = nullptr;
        player = nullptr;

    }

    MazeGame::~MazeGame(){
        if(mazeView != nullptr)
            delete mazeView;
        if(currentMaze != nullptr)
            delete currentMaze;
        if(player != nullptr)
            delete player;
    }

    void MazeGame::Start(){
        mazeView->SetMaze(currentMaze);
        mazeView->Draw(player->GetCurrentRoomNumber());
    }

    void MazeGame::End(){

    }

    void MazeGame::SetMaze(Maze* Maze){
        currentMaze = Maze;
    }

    void MazeGame::ClearMaze(){
        delete currentMaze;
        currentMaze = nullptr;
    }

    void MazeGame::SetPlayer(Player::PlayerCharacter* _player){
        player = _player;
        player->SetCurrentRoomNumber(1); // TEMP CODE
    }

    bool MazeGame::TryMovePlayer(Direction direction){
        // current room is not null
        if (player == nullptr)
            return false;
        if (currentMaze == nullptr)
            return false;

        int currentRoomNumber = player->GetCurrentRoomNumber();
        
        auto currentRoom = currentMaze->RoomNo(currentRoomNumber);

        int nextRoomNumber = currentRoom->GetSide(direction)->Enter(player);


        if (nextRoomNumber == -1 || nextRoomNumber == currentRoomNumber)
            return false;
        else{
            player->SetCurrentRoomNumber(nextRoomNumber);
            return true;
        }
    }

    // void MazeGame::PrintCurrentRoom(){ return; }

    void MazeGame::UpdateDraw(){
        mazeView->Draw(player->GetCurrentRoomNumber());
    }
}


#endif /* AC3ED5B3_0134_4E19_B66E_31076AA9F149 */
