#ifndef AC3ED5B3_0134_4E19_B66E_31076AA9F149
#define AC3ED5B3_0134_4E19_B66E_31076AA9F149

#include "Mazes/Maze.h"
#include "Mazes/MazeFactory.h"

using namespace BaseMazeComponents;
using namespace BaseMazeFactories;

namespace MazeGames{
    class MazeGame {
        public:
            Maze* CreateMaze(BaseMazeFactories::BaseMazeFactory& mf); //추상팩토리 예제코드에 맞춰 매개변수 설정
    };    

    // MazeFactory를 매개변수로 받도록 하여, 클래스 이름을 하드코딩하여 생긴 문제를 해결한 함수
    Maze* MazeGame::CreateMaze (BaseMazeFactories::BaseMazeFactory& factory) {
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
}


#endif /* AC3ED5B3_0134_4E19_B66E_31076AA9F149 */
