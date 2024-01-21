class Component:
    def __init__(self) -> None:
        pass

    def Draw():
        print("hi")

    def Resize():
        print("hi")


class Decorator(Component):
    def __init__(self, comp: Component) -> None:
        self._component = comp
        super().__init__()

    def Draw(self):
        self._component.Draw()

    def Resize(self):
        self._component.Resize()


class Sticker(Decorator):
    _image = None
    _size = (0, 0)

    def __init__(self, comp: Component, size: tuple, image: str) -> None:
        super().__init__(comp)
        self._image = image
        self._size = size

    def Draw(self):
        super().Draw()
        self.DrawImage(self._image)

    def DrawImage(self):
        print(self._image)
