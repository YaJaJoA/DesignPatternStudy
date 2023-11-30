#ifndef B94D1D17_F533_492C_AE19_7059A277576E
#define B94D1D17_F533_492C_AE19_7059A277576E

namespace BaseCharacter{
    class IMovable{
        public:
            virtual void MoveLeft() = 0;
            virtual void MoveRight() = 0;
            virtual void MoveUp() = 0;
            virtual void MoveDown() = 0;
    };
    class BaseCharacter: public IMovable{
        public:
            BaseCharacter() {};
            virtual ~BaseCharacter() {};

            // IMovable interface
            
            // end IMovable interface
        private:
            int x;
            int y;
    };
}

#endif /* B94D1D17_F533_492C_AE19_7059A277576E */
