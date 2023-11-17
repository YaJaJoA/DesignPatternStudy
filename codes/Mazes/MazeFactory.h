#ifndef C485CCEA_8993_4710_88EF_3F969FC820C5
#define C485CCEA_8993_4710_88EF_3F969FC820C5

#include "Maze.h"

using namespace BaseMazeComponents;

namespace BaseMazeFactories{
    class BaseMazeFactory {
        public:
            BaseMazeFactory() {};

            virtual Maze* MakeMaze() const
                { return new Maze; }
            virtual Wall* MakeWall () const
                { return new Wall; }
            virtual Room* MakeRoom(int n) const
                { return new Room(n); }
            virtual Door* MakeDoor(Room* r1, Room* r2) const
                { return new Door(r1,r2); }
    };
}
#endif /* C485CCEA_8993_4710_88EF_3F969FC820C5 */
