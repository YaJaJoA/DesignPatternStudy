class Vehicle:
    def __init__(self) -> None:
        pass

    def sound(self):
        print("빵빵")


class Car(Vehicle):
    def __init__(self) -> None:
        super().__init__()

    def bonk(self):
        print("빵")

    def sound(self):
        bonk()


class Truck(Vehicle):
    def __init__(self) -> None:
        super().__init__()

    def sound():
        noise()

    def noise(self):
        print("빵아아앙")


class Train(Vehicle):
    def __init__(self) -> None:
        super().__init__()

    def sound():
        Ahhhh()

    def Ahhhh(self):
        print("AHHHHHHHHHHHHHHHHHHHHH")


class VehicleAdapter:
    def __init__(self, vehicle) -> None:
        self.vehicle = vehicle
        pass

    def makeSound(self):
        method_list = [
            method for method in dir(self.vehicle) if method.startswith("__") is False
        ][0]
        method = getattr(self.vehicle, method_list)
        method()


if __name__ == "__main__":
    vehicle = Vehicle()
    car = Car()
    truck = Truck()
    train = Train()

    vehicle_list = [
        VehicleAdapter(car),
        VehicleAdapter(truck),
        VehicleAdapter(train),
    ]

    for i in vehicle_list:
        i.makeSound()
