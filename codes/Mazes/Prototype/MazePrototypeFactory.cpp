#include "MazePrototypeFactory.h"
#include "../Maze.h"

using namespace BasePrototypeFactory;

MazePrototypeFactory::MazePrototypeFactory() {
    _prototypeMaze = new Maze();
    _prototypeWall = new Wall();
    _prototypeRoom = new Room(0);
    _prototypeDoor = new Door();
}

MazePrototypeFactory::MazePrototypeFactory (Maze* m, Wall* w, Room* r, Door* d) {
    _prototypeMaze = m;
    _prototypeWall = w;
    _prototypeRoom = r;
    _prototypeDoor = d;
}

Maze* MazePrototypeFactory::MakeMaze() const{ 
    return _prototypeMaze->Clone();
}

Room* MazePrototypeFactory::MakeRoom(int n) const {
    Room* room = _prototypeRoom->Clone();
    room->Initialize(n);
    return room;
}


Wall* MazePrototypeFactory::MakeWall() const {
    return _prototypeWall->Clone();
}

Door* MazePrototypeFactory::MakeDoor (Room* r1, Room* r2) const {
    Door* door = _prototypeDoor->Clone();
    door->Initialize(r1, r2);
    return door;
}