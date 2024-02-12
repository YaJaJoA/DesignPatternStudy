from Proxy.le2dy.proxy import Point


class Point:
    _loc: tuple(int, int) = None

    def __init__(self, point: tuple(int, int)) -> None:
        self._loc = point
        pass

    def Draw(self):
        print(f"Draw dot on ({self._loc[0]}, {self._loc[1]})")


class Graphic:
    def __init__(self) -> None:
        pass

    def Draw(self, point: Point):
        point.Draw()
        pass

    def HandleMouse(self, event: str):
        self._event = event
        pass

    def GetExtent():
        pass

    def Load(self, from_path: str):
        self._path = from_path

    def Save(self, to_path: str):
        print(f"Save object at {to_path}")


class Image(Graphic):
    def __init__(self, image: str) -> None:
        super().__init__()
        self._image = image

    def GetExtent():
        pass

    def Load(self, from_path: str):
        return super().Load(from_path)

    def Save(self, to_path: str):
        return super().Save(to_path)


class ImageProxy(Graphic):
    _imageObj: Image = None
    _extent: Point = None
    _fileName: str = None

    def __init__(self, fileName: str) -> None:
        super().__init__()
        self._fileName = fileName

    def getImage(self):
        if self._imageObj == None:
            self._imageObj = Image(self._fileName)
        return self._imageObj

    def GetExtent(self):
        if self._extent == None:
            self._extent = self.getImage().GetExtent()

    def Draw(self, at: Point):
        self.getImage().Draw(at)

    def HandleMouse(self, event: str):
        self.getImage().HandleMouse(event)

    def Load(self, from_path: str):
        print(f"{from_path}, {self._extent}, {self._fileName}")

    def Save(self, to_path: str):
        print(f"{to_path}, {self._extent}, {self._fileName}")


class TextDocument:
    def __init__(self) -> None:
        self._graphic = []

    def Insert(self, graphic: Graphic):
        self._graphic.append(graphic)


if __name__ == "__main__":
    text = TextDocument
    text.Insert(ImageProxy("ImageFileName"))
