#ifndef F5F816B8_2452_47E5_A0A8_5A7E478E795A
#define F5F816B8_2452_47E5_A0A8_5A7E478E795A
#include "Maze.h"

using namespace BaseMazeComponents;

namespace EnchantedMazeComponent{
    class Spell {
        public:
            Spell* CastSpell() const;
    };

    class EnchantedRoom : public Room{
        public:
            EnchantedRoom(int n, Spell* sp);
    };

    class DoorNeedingSpell : public Door{
        public:
            DoorNeedingSpell(Room* r1, Room* r2);
    };
}


#endif /* F5F816B8_2452_47E5_A0A8_5A7E478E795A */
