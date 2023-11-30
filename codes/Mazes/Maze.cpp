#include "Maze.h"
#include "../CustomException.hpp"

using namespace BaseMazeComponents;

#pragma region MAZE METHODS
//Maze Functions
Maze::Maze(){
    numberOfRooms = 0;
}

bool Maze::AddRoom(Room* room){
    if (!(numberOfRooms < MAX_ROOMS))
        return false;

    rooms[numberOfRooms++] = room;
    return true;
}

// Implementation for Prototype Pattern
Maze* Maze::Clone() const{ // Clone for Prototype Pattern
    Maze* maze = new Maze();
    for(int i = 0; i < numberOfRooms; i++){
        maze->AddRoom(rooms[i]->Clone());
    }
    return maze;
}

// returns a pointer to the room with the given room number.
// null pointer if no such room exists.
Room* Maze::RoomNo(int roomNumber) const{
    for(int i = 0; i < numberOfRooms; i++){
        if(rooms[i]->GetRoomNumber() == roomNumber)
            return rooms[i];
    }
    return nullptr;
}
#pragma endregion Maze Methods

#pragma region DOOR METHODS
Door::Door(Room* r1, Room* r2){
    _room1 = r1;
    _room2 = r2;
}

Door::~Door(){
    delete _room1;
    delete _room2;
}

// Implementation for Prototype Pattern
Door::Door (const Door& other){ // copy constructor
    _room1 = other._room1;
    _room2 = other._room2;
}

void Door::Initialize(Room* r1, Room* r2){ // Initializer for Prototype Pattern
    _room1 = r1;
    _room2 = r2;
}

Door* Door::Clone() const{ // Clone for Prototype Pattern
    return new Door(*this);
}
// End Prototype Pattern

Room* Door::otherSideFrom(Room* room){
    if(room == _room1)
        return _room2;
    else if(room == _room2)
        return _room1;
    else // if room is not either room1 or room2
        return nullptr; // return null pointer
}
#pragma endregion Door Methods

#pragma region Room Methods
Room::Room(int RoomNo){
    _roomNumber = RoomNo;
}

MapSite* Room::GetSide(Direction direction) const{
    return _sides[direction];
}

void Room::SetSide(Direction direction, MapSite* mapSite){
    _sides[direction] = mapSite;
}

int Room::GetRoomNumber() const{
    return _roomNumber;
}

// Implementation for Prototype Pattern
Room* Room::Clone() const{ // Clone for Prototype Pattern
    return new Room(*this);
}

void Room::Initialize(int RoomNo){ // Initializer for Prototype Pattern
    _roomNumber = RoomNo;
}
#pragma endregion Room Methods

#pragma region Wall Methods
Wall::Wall(){
}

// Implementation for Prototype Pattern
Wall* Wall::Clone () const{ // Clone for Prototype Pattern
    return new Wall(*this);
}
#pragma endregion Wall Methods
