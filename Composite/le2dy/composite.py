class Stuff:
    def __init__(self, name) -> None:
        self._name = name
        pass


class Box:
    def __init__(self, name, *args: Stuff) -> None:
        self._name = name
        self._innerStuff: list[Stuff] = args
        pass

    def print(self, prefix=""):
        for i in self._innerStuff:
            print(prefix + i._name)
            if isinstance(i, Box):
                i.print(f'{prefix}{"-" * 5}')
        # self._innerStuff.append(...args)


if __name__ == "__main__":
    pencil = Stuff("pencil")
    eraser = Stuff("eraser")
    box = Box("box", pencil, eraser)
    another_pencil = Stuff("pencil")
    another_eraser = Stuff("eraser")
    biggerBox = Box("big Box", another_pencil, another_eraser, box)

    ruler = Stuff("ruler")
    mechPen = Stuff("mechanical Pencil")
    biggestBox = Box("I'm the King of the Box!", ruler, mechPen, biggerBox)

    biggestBox.print()
