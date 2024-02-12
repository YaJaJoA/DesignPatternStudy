from colorama import Fore, Style

# Implementor
class RoomImp():
    _origin = (0,0)
    _width = 0
    _height = 0
    def __init__(self) -> None:
        pass

    def impSetOrigin(self, origin: tuple):
        self._origin = origin

    def impSetSize(self, w: int, h: int):
        self._width = w
        self._height = h

    def impSetFloorColor(self, color: str):
        self._fColor = color

    def draw(self):
        print(self._width, self._height)

        fColor = Fore.RED if self._fColor == "red" else Fore.BLUE if  self._fColor == 'blue' else Fore.WHITE

        [print(''.join([f"{fColor}■{Style.RESET_ALL}" for _ in range(self._width)])) for _ in range(self._height)]

# ConcreteImplementor
class NormalRoomImp(RoomImp):
    def __init__(self) -> None:
        super().__init__()

class BlueRoomImp(RoomImp):
    def __init__(self) -> None:
        super().__init__()

# Abstractor
class Room():
    def __init__(self, imp: RoomImp) -> None:
        self._imp = imp
        self._imp.impSetFloorColor('white')
    
    def setOrigin(self, origin: tuple):
        self._imp.impSetOrigin(origin)

    def setSize(self, w: int, h: int):
        self._imp.impSetSize(w, h)

    def setFloorColor(self, color: str):
        self._imp.impSetFloorColor(color)
        
    def draw(self):
        self._imp.draw()

# RefinedAbstraction
class RoomColored(Room):
    def __init__(self, imp: RoomImp) -> None:
        super().__init__(imp)
        self.fColor = "Red"

    def setOrigin(self, origin: tuple):
        return super().setOrigin(origin)
        

    def setSize(self, w: int, h: int):
        return super().setSize(w, h)

    def draw(self):
        super().setFloorColor(self.fColor)
        return super().draw()

# Client
class roomMaker():
    def __init__(self, room: Room) -> None:
        self._room = room
        self.make()

    def make(self):
        self._room.setSize(5, 5)
        self._room.setOrigin((0, 0))

        if type(self._room) is  RoomColored:
            self._room.setFloorColor("blue")

        self._room.draw()

if __name__ == "__main__":
    implementor = NormalRoomImp()
    room = Room(implementor)
    roomMaker(room)

    implementor = NormalRoomImp()
    room = RoomColored(implementor)
    roomMaker(room)
