#ifndef B0BC0DA6_CE6A_4B77_8F6D_CD14B2BD870B
#define B0BC0DA6_CE6A_4B77_8F6D_CD14B2BD870B

namespace BaseMazeComponents{
    enum Direction {North, South, East, West};

    class MapSite {
        public:
            virtual void Enter() {};
    };

    class Room : public MapSite {
        public:
            Room(int RoomNo);

            MapSite* GetSide (Direction) const;
            void SetSide (Direction, MapSite*);

            //virtual void Enter();

            int GetRoomNumber() const;
        private:
            MapSite* _sides [4]; //방은 4개의 방향을 가지고 있고, 각 방향에는 MapSite의 서브클래스 인스턴스가 올 수 있다.

            int _roomNumber;
    };

    class Wall : public MapSite {
        public:
            Wall() {};

           // virtual void Enter();

    };

    class Door : public MapSite {
        public:
            Door(Room* = 0, Room* = 0); //문을 초기화 하기 위해서는 문이 어느 방 사이에 있는지 알아야 한다.
            //virtual void Enter();
            Room* otherSideFrom(Room *);

        private:
            Room* _room1;
            Room* _room2;
            bool _isOpen;
    };

    class Maze {
        constexpr static int MAX_ROOMS = 4;
        public:
            Maze(); 
            bool AddRoom (Room*);
            Room* RoomNo (int) const;
        private:
            /// @brief Maze에 존재하는 Room들을 저장하는 Array
            /// @details Maze는 Room들을 저장하는 Array를 가지고 있으며, 이 Array는 Maze의 생성자에서 초기화 된다. \
                Vector를 사용하도록 할 예정(Room의 추가, 제거가 생긴다면 Vector를 사용하는 것이 좋을 것 같다.)
            Room * rooms[MAX_ROOMS];
            int numberOfRooms;
    };
}


#endif /* B0BC0DA6_CE6A_4B77_8F6D_CD14B2BD870B */
