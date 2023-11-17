# Factory Method
- Based on "Design Patterns: Elements of Reusable Object-Oriented Software" by Erich Gamma

## 요약
클래스의 생성을 담당하는 인터페이스를 정의한 후, 어떤 클래스를 생성할 지는 인터페이스를 구현하는 각각의 클래스에서 정의하도록 만든다.


### 배경 (사용하는 경우)
1. 클래스가 생성할 클래스의 타입을 미리 알 지 못할 때
1. 하위 클래스(상속받은 클래스)에서 생성할 클래스를 지정할 때
1. 클래스가 하위 클래스에게 생성하는 역할을 미루고, 어떤 하위 클래스가 그 역할을 수행할 지 숨기고 싶을 때(localize, 클래스 밖으로 알리고 싶지 않을 때)

## 구현
```
/// Product.h
class Product{
public:
    int pid;
    Product(int id){pid = id;};
}

class Clay : Product{
public:
    int pid;
    int sand_weight;
    Product(int id, int weight){pid = id; sand_weight = weight};
}



/// Creator.h
class Creator{
public:
    // Product는 생성될 클래스의 virtual base class
    virtual Product* Create() = 0; // 순수 가상함수로 선언하면 Creator를 상속받은 클래스에서 이를 구현해야한다.
};

class ConcreteCreator : Creator{
public:
    // 
    Product* Create(){ return new Clay(cnt++, 100); };
private:
    static int cnt=0;
}

/// main.cpp
int main(){
    ConcreteCreator* CreatorA = new ConcreteCreator();
    Product* A = CreatorA.Create();
}
```


## 결과물
1. 클래스 생성을 간접적으로 할 수 있게 만든다. 직접 생성하는 경우 생성 과정이 변경이 있을 때 클래스를 생성하는 부분을 전부 수정해야한다. 간접적으로 생성한다면 Factory Method 내부만 수정하면 되므로 변경이 유연해진다.

1. 클래스 위계들을 연결할 수 있다. 각 클래스 위계들이 전체적으로 결합된 것이 아니라 Factory Method를 통해서만 결합되었기 때문에 병렬적으로 연결된 것이다.

1. 템플릿을 사용해 상속을 방지한다. C++의 템플릿을 사용한다면 Factory Method를 만들기 위해 Sub클래스를 만드는 것을 피할 수 있다.


## 연관된 패턴
- [Abstract Factory](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/AbstractFactory/leejunseo/README.md)
