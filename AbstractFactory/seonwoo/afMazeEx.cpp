enum Direction {North, South, East, West};

class MapSite {
    public:
        virtual void Enter() = 0;
};

class Room : public MapSite {
    public:
        Room(int RoomNo);

        MapSite* GetSide (Direction) const;
        void SetSide (Direction, MapSite*);

        virtual void Enter();
    private:
        MapSite* _sides [4]; //방은 4개의 방향을 가지고 있고, 각 방향에는 MapSite의 서브클래스 인스턴스가 올 수 있다.

        int _roomNumber;
};

class Wall : public MapSite {
    public:
        Wall();

        virtual void Enter();
};

class Door : public MapSite {
    public:
        Door(Room* = 0, Room* = 0); //문을 초기화 하기 위해서는 문이 어느 방 사이에 있는지 알아야 한다.
        virtual void Enter();
        Room* otherSideFrom(Room *);

    private:
        Room* _room1;
        Room* _room2;
        bool _isOpen;
};

class Maze {
    public:
        Maze();

        void AddRoom (Room*);
        Room* RoomNo (int) const;
    private:
        // ...
};

//교재에 명시되어있지 않아서 임의로 작성
class MazeGame {
    public:
        Maze* CreateMaze(MazeFactory& mf); //추상팩토리 예제코드에 맞춰 매개변수 설정
};


/* 패턴을 적용하여 해결할 문제가 있는 예시 함수
Maze* MazeGame::CreateMaze() {
    Maze* aMaze = new Maze;
    Room* r1 = new Room(1);
    Room* r2 = new Room(2);
    Door* theDoor = new Door(r1,r2);

    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);
    // 방의 모든 면을 세팅하는 코드, 반복되는 작업이 존재한다.
    r1->SetSide(North, new Wall);
    r1->SetSide(East, theDoor);
    r1->SetSide(South, new Wall);
    r1->SetSide(West, new Wall);

    r2->SetSide(North, new Wall);
    r2->SetSide(East, theDoor);
    r2->SetSide(South, new Wall);
    r2->SetSide(West, new Wall);

    return aMaze;   
}
*/

// 여기까지 생성 패턴 소개 단계에서 공통으로 사용하는 예시 코드 내용

class MazeFactory {
    public:
        MazeFactory() ;

        virtual Maze* MakeMaze() const
            { return new Maze; }
        virtual Wall* MakeWall () const
            { return new Wall; }
        virtual Room* MakeRoom(int n) const
            { return new Room(n); }
        virtual Door* MakeDoor(Room* r1, Room* r2) const
            { return new Door(r1,r2); }
};


// MazeFactory를 매개변수로 받도록 하여, 클래스 이름을 하드코딩하여 생긴 문제를 해결한 함수
Maze* MazeGame::CreateMaze (MazeFactory& factory) {
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


class EnchantedMazeFactory : public MazeFactory {
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
