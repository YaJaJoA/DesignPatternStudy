#ifndef B60E47A3_A640_4263_ABA1_067197236E1B
#define B60E47A3_A640_4263_ABA1_067197236E1B
#include "../MazeFactory.h"

using namespace BaseMazeComponents;

namespace BasePrototypeFactory{
    // code from the book "Design Patterns: Elements of Reusable Object-Oriented Software"
    class MazePrototypeFactory : public BaseMazeFactories::BaseMazeFactory {
        public:
            MazePrototypeFactory();
            MazePrototypeFactory(BaseMazeComponents::Maze* m, BaseMazeComponents::Wall* w, BaseMazeComponents::Room* r, BaseMazeComponents::Door* d);

            virtual Maze* MakeMaze() const;
            virtual Room* MakeRoom(int n) const;
            virtual Wall* MakeWall() const;
            virtual Door* MakeDoor(Room* r1, Room* r2) const;

        private:
            Maze* _prototypeMaze;
            Room* _prototypeRoom;
            Wall* _prototypeWall;
            Door* _prototypeDoor;
    };
}


#endif /* B60E47A3_A640_4263_ABA1_067197236E1B */
