from colorama import Fore, Back, Style
from random import randint

TREE_SYMBOL = "\u21DE"
size = 0


# Client
class Terrain:
    def __init__(self, width, height) -> None:
        global size
        self.width = width
        self.height = height
        self._map = [
            [Fore.GREEN + "■" + Style.RESET_ALL for _ in range(width)]
            for _ in range(height)
        ]
        size += 200

    def display(self):
        m = self._map
        [print("".join(m[i])) for i in range(len(m))]


# ConcreteFlyweight
class TreeColor:
    def __init__(self, species) -> None:
        global size

        self.color = Fore.BLACK
        if species == "Oak":
            self.color = Fore.LIGHTRED_EX
        elif species == "Birch":
            self.color = Fore.WHITE
        size += 20


# Flyweight
class Tree:
    def __init__(self, color, location: tuple, terrain: Terrain) -> None:
        global size
        # extrinsic property
        self.terrain = terrain
        self.color = color
        # UnsharedConcreteFlyweight
        # instrinsic property
        self.x = location[0]
        self.y = location[1]
        size += 10

    def place(self):
        self.terrain._map[self.y][self.x] = self.color + TREE_SYMBOL + Style.RESET_ALL


# FlyweightFactory
class TreeFactory:
    treeColorPool = {}

    def __init__(self, terrain: Terrain) -> None:
        self.terrain = terrain

    def makeTree(self, species):
        # 해당 종에 대한 TreeColor가 이미 있다면 해당 TreeColor 재사용
        if species not in self.treeColorPool:
            self.treeColorPool[species] = TreeColor(species)

        _tree = Tree(
            self.treeColorPool[species].color,
            (randint(1, self.terrain.width - 1), randint(1, self.terrain.height - 1)),
            self.terrain,
        )
        return _tree

    def clearPool(self):
        self.treeColorPool.clear()


if __name__ == "__main__":
    terrain = Terrain(20, 20)  # 100
    treefactory = TreeFactory(terrain)
    oaktrees: list[Tree] = [treefactory.makeTree("Oak") for _ in range(10)]  # 100
    birchtrees: list[Tree] = [treefactory.makeTree("Birch") for _ in range(10)]  # 100

    for i in oaktrees:
        i.place()

    for i in birchtrees:
        i.place()

    terrain.display()
    treefactory.clearPool()
    print("Total size: ", str(size) + "MB")
