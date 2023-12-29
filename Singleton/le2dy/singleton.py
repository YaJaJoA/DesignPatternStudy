class Singleton(type):
    _instances = {}

    # __call__ 메소드 재정의
    def __call__(cls, *args, **kwargs):
        # 싱글톤 클래스를 상속받은 클래스의 인스턴스가 없으면 새 인스턴스 생성, 있으면 해당 인스턴스 반환(생성 제한)
        if cls not in cls._instances:
            cls._instances[cls] = super(Singleton, cls).__call__(*args, **kwargs)
        return cls._instances[cls]


# 구현한 싱글톤 클래스를 메타클래스로 지정
class Smartphone(metaclass=Singleton):
    def __init__(self, os) -> None:
        self.os = OperateSystem(os)


# 코드 개연성을 위한 클래스
class OperateSystem:
    def __init__(self, os) -> None:
        if os == "IOS":
            maker = "Apple"
        elif os == "AOS":
            maker = "Android"
        else:
            maker = "somethingElse"
        self.info = [os, maker]


if __name__ == "__main__":
    # 인스턴스 여러개 생성
    smartphone = Smartphone("IOS")
    smartphone2 = Smartphone("AOS")
    phone3 = Smartphone("asd")

    # 인스턴스 정보 출력
    print(smartphone.os.info)
    print(smartphone2.os.info)
    print(phone3)

    # 같은 인스턴스인지 확인
    print(smartphone == smartphone2 == phone3)
