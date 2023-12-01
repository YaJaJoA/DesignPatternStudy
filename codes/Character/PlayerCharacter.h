#ifndef A4A98600_A0CB_4E55_ACEE_01DDD535F733
#define A4A98600_A0CB_4E55_ACEE_01DDD535F733

#include "BaseCharacter.h"

namespace Player{
    class PlayerCharacter : public BaseCharacter::BaseCharacter{
        public:
            PlayerCharacter() {};
            virtual ~PlayerCharacter() {};

            // IMovable interface
            virtual void MoveLeft() {};
            virtual void MoveRight() {};
            virtual void MoveUp() {};
            virtual void MoveDown() {};
            // end IMovable interface

            int GetCurrentRoomNumber() const { return currentRoomNo; };
            void SetCurrentRoomNumber(int roomNo) { currentRoomNo = roomNo; };
        private:
            int currentRoomNo;
    };
}

#endif /* A4A98600_A0CB_4E55_ACEE_01DDD535F733 */
