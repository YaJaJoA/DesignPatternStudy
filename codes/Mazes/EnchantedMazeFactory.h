#ifndef B6A291D6_38DC_417D_95A1_1A462D6D3312
#define B6A291D6_38DC_417D_95A1_1A462D6D3312
#include "EnchantedMaze.h"
#include "MazeFactory.h"

using namespace BaseMazeFactories;
using namespace EnchantedMazeComponent;

namespace EnchantedMazeFactories{
    class EnchantedMazeFactory : public BaseMazeFactory {
        // MazeFactory를 상속받아 부모 클래스에 정의된 연산을 재정의한 후
        // 구체적인 요소를 생성하여 반환하도록 구현하는 서브클래스

        public:
            EnchantedMazeFactory();

            virtual Room* MakeRoom(int n) const
                { return new EnchantedRoom(n, CastSpell());}
                // 이때는 Room을 상속받은 EnchantedRoom의 인스턴스를 생성하여 반환함
            virtual Door* MakeDoor(Room* r1, Room* r2) const
                { return new DoorNeedingSpell(r1,r2); }
                // 이때는 Door를 상속받은 DoorNeedingSpell의 인스턴스를 생성하여 반환함
        protected:
            Spell* CastSpell() const;
    };
}


#endif /* B6A291D6_38DC_417D_95A1_1A462D6D3312 */
