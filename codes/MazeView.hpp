#ifndef F3EFA6DA_930A_4C28_9718_40BF0B9AF9D7
#define F3EFA6DA_930A_4C28_9718_40BF0B9AF9D7

#include <iostream>
#include "Mazes/Maze.h"
class RoomView{
public:
    RoomView();
    ~RoomView();

    void SetSide(BaseMazeComponents::Direction direction, char side_character);
    auto GetRoomViewChar() const { return room_view_char; };
    void Draw() const;

private:
    wchar_t room_view_char[3][3];
};

class MazeView{
public:
    MazeView();
    MazeView(int width, int height);
    ~MazeView();
    void SetMaze(BaseMazeComponents::Maze* maze);
    void Draw();
    void Draw(int RoomNo);

private:
    BaseMazeComponents::Maze* current_maze;

};

#pragma region RoomView Methods
RoomView::RoomView(){
    // initialize room_view_char
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            room_view_char[i][j] = ' ';
        }
    }
    // draw corners
    room_view_char[0][0] = L'\u250C';
    room_view_char[0][2] = L'\u2510';
    room_view_char[2][0] = L'\u2514';
    room_view_char[2][2] = L'\u2518';
}

RoomView::~RoomView(){
}

void RoomView::SetSide(BaseMazeComponents::Direction direction, char side_character){
    switch(direction){
        case BaseMazeComponents::North:
            room_view_char[0][1] = side_character;
            break;
        case BaseMazeComponents::South:
            room_view_char[2][1] = side_character;
            break;
        case BaseMazeComponents::East:
            room_view_char[1][2] = side_character;
            break;
        case BaseMazeComponents::West:
            room_view_char[1][0] = side_character;
            break;
    }
}

void RoomView::Draw() const{
    std::wcout << room_view_char[0][0] << room_view_char[0][1] << room_view_char[0][2] << '\n';
    std::wcout << room_view_char[1][0] << room_view_char[1][1] << room_view_char[1][2] << '\n';
    std::wcout << room_view_char[2][0] << room_view_char[2][1] << room_view_char[2][2] << '\n';
}

#pragma endregion RoomView Methods

#pragma region MazeView Methods
MazeView::MazeView(){
}
MazeView::MazeView(int width, int height){
}
MazeView::~MazeView(){
}

void MazeView::SetMaze(BaseMazeComponents::Maze* maze){
    current_maze = maze;
}

void MazeView::Draw(){
    if (current_maze == nullptr)
        return;

    // draw current_maze
    const int MAX_ROOM_NUMBER = BaseMazeComponents::Maze::MAX_ROOMS;
    for(int i = 0; i < MAX_ROOM_NUMBER; i++){
        MazeView::Draw(i);
    }
}

void MazeView::Draw(int RoomNo){
    if (current_maze == nullptr)
        return;

    // draw getRoomNo
    BaseMazeComponents::Room* room = current_maze->RoomNo(RoomNo);

    if (room == nullptr) return;

    RoomView room_view;
    // draw room's sides
    for(int j = 0; j < 4; j++){
        BaseMazeComponents::MapSite* side = room->GetSide((BaseMazeComponents::Direction)j);
        // draw side
        if (side == nullptr)
            side = new BaseMazeComponents::Wall();
        side->GetPrintableChar();
        room_view.SetSide((BaseMazeComponents::Direction)j, side->GetPrintableChar());   
    }
    std::wcout << "\033[A\033[A\033[A\033[A"; // move cursor up
    std::wcout << "Room #" << RoomNo << "\n";
    room_view.Draw();
    
    return;
}

#pragma endregion MazeView Methods

#endif /* F3EFA6DA_930A_4C28_9718_40BF0B9AF9D7 */
