DIRECTION = {"North": 0,"South": 1,"East": 2,"West": 3,}

class MapSite():
    def __init__(self) -> None:
        return self

    def Enter():
        print("Enter")

class Maze():
    def __init__(self) -> None:
        self.rooms= []
        self.no = None
        return self
    
    def AddRoom(self, r):
        self.rooms.append(r)

    def RoomNo(self, no):
        self.no = no

class Wall(MapSite):
    def __init__(self) -> None:
        return self
    
    def Enter():   # MapSite의 Enter 메소드 오버라이딩
        print("Enter")
    
class Room(MapSite):  # MapSite 클래스 상속
    def __init__(self, n) -> None:  # 초기 설정
        self.roomNumber = n
        self.sides = [0 for _ in range(4)]
        self.side = None
        return self(n)

    def Enter(self):
        print("Enter")
    
    def SetSide(self, dir, ms):
        self.sides[dir] = ms
    
    def GetSide(self, dir):
        return self.sides[dir]
    
class Door(MapSite):
    def __init__(self, r1, r2) -> None:
        self.r1 = r1
        self.r2 = r2
        self.isOpen = False
        return self    

    def OtherSideFrom(self, r):
        other = None
        if r == self.r1:
            other = self.r2
        elif r == self.r2:
            other = self.r1
        return other

class MazeFactory():
    def MakeMaze(self):  # 새 Maze 객체 리턴
        return Maze()
    
    def MakeWall(self):  # 새 Wall 객체 리턴
        return Wall()
    
    def MakeRoom(self, n): # 새 Room 객체 리턴
        return Room(n)
    
    def MakeDoor(self, r1, r2):  # 새 Door 객체 리턴
        return Door(r1,r2)

class MazeGame():
    def CreateMaze():
        factory = MazeFactory()  # Maze를 구성하기 위한 미로 생성기 객체 생성
        aMaze = factory.MakeMaze()  # Maze 객체 생성
        r1 = factory.MakeRoom(1)  # 방 생성
        r2 = factory.MakeRoom(2)  # 방 생성
        aDoor = factory.MakeDoor(r1, r2)  # 방에 문 연결

        aMaze.AddRoom(r1)  # 미로에 방 추가
        aMaze.AddRoom(r2)  # 미로에 방 추가

        r1.SetSide("North", factory.MakeWall())  # 방 북쪽에 벽 생성
        r1.SetSide("East", aDoor)                # 방 동쪽에 문 설정
        r1.SetSide("South", factory.MakeWall())  # 방 남쪽에 벽 생성
        r1.SetSide("West", factory.MakeWall())   # 방 서쪽에 벽 생성


        r2.SetSide("North", factory.MakeWall()) # 방 북쪽에 벽 생성
        r2.SetSide("East", factory.MakeWall())  # 방 동쪽에 문 설정
        r2.SetSide("South", factory.MakeWall()) # 방 남쪽에 벽 생성
        r2.SetSide("West", aDoor)               # 방 서쪽에 벽 생성
        return aMaze  # 생성한 미로 반환

if __name__ == "__main__":
    mg = MazeGame()  # 미로 생성
