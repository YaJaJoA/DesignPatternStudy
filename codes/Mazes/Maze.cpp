#include "Maze.h"
#include "../CustomException.hpp"

using namespace BaseMazeComponents;

Room::Room(int RoomNo){
    _roomNumber = RoomNo;
}

MapSite* Room::GetSide(Direction direction) const{
    return _sides[direction];
}

void Room::SetSide(Direction direction, MapSite* mapSite){
    _sides[direction] = mapSite;
}

Door::Door(Room* r1, Room* r2){
    _room1 = r1;
    _room2 = r2;
}

Room* Door::otherSideFrom(Room* room){
    if(room == _room1)
        return _room2;
    else if(room == _room2)
        return _room1;
    else // if room is not either room1 or room2
        return nullptr; // return null pointer
}

int Room::GetRoomNumber() const{
    return _roomNumber;
}

Maze::Maze(){
    numberOfRooms = 0;
}

bool Maze::AddRoom(Room* room){
    if (!(numberOfRooms < MAX_ROOMS))
        return false;

    rooms[numberOfRooms++] = room;
    return true;
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

