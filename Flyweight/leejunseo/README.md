# Flyweight
- Based on "Design Patterns: Elements of Reusable Object-Oriented Software" by Erich Gamma

## 요약
공유하는 데이터가 있는 많은 수의 오브젝트들을 효율적으로 저장할 때 사용한다

### 배경 (사용하는 경우)
일부 정보를 제외하고 중복된 정보를 공유하는 인스턴스들이 다량으로 존재할 때 용량을 절약하기 위해 중복된 정보를 필요할 때만 계산하여 사용한다.

## 구현
Flyweight 클래스는 intrisic data와 extrinsic data로 구분하는 것이 중요하다. intrinsic state는 flyweight로 구현하고자 하는 객체들이 공유해 사용하고자 하는 정보로 다수의 인스턴스들에서 중복으로 사용되는 값들을 의미한다. extrinsic state는 flyweight를 관리하는 클래스에서 런타임에 계산하는 정보들로 인스턴스의 고유한 값들이 된다.

Flyweight 패턴은 다음과 같은 클래스들을 사용해 구현할 수 있다.
- Flyweight
    - Flyweight 클래스들이 extrinsic state를 전달받아 수행하는 메소드들이 정의된 인터페이스이다.
- ConcreteFlyweight
    - Flyweight 인터페이스를 구현하여 intrinsic state를 저장한다. ConcreteFlyweight에서 저장하는 정보는 반드시 intrinsic state가 된다. 즉, ConcreteFlyweight의 context와 독립적이어야 한다
- UnsharedConcreteFlyweight
    - 공유되지 않는 flyweight 클래스들을 의미한다.  Flyweight 클래스들은 공유될 수 있지만 반드시 공유해야하는 것은 아니다.
- FlyweightFactory
    - flyweight들의 생성과 관리를 담당한다. flyweight들이 공유될 수 있도록 보장한다. client가 flyweight를 요청할 때에 존재하는 flyweight를 전달한다. 만약 존재하지 않는다면 새로운 flyweight를 만든다.
- Client
    - flyweight들의 레퍼런스를 갖고 사용

## 결과물
공유되서 사용되는 정보들은 intrinsic state로 저장하는 ConcreteFlyweight를 정의하고, Runtime에서 extrinsic state를 전달해 필요한 동작을 수행한다.
따라서 extrinsic state들을 저장하고 계산하는 동작을 Client에서 구현해야한다. 또한 flyweight pool를 관리하고 flyweight factory로 flyweight의 생성, 관리해야하기 때문에 구조가 복잡해진다.

이를 통해 다음과 같은 결과를 얻을 수 있다.
- 공유를 통해 instance의 생성을 줄일 수 있다.
- 필요한 메모리 공간을 줄일 수 있다.
- extrinsic state를 사용한 추가적인 연산이 필요해진다. 즉, 런타임에서 수행 시간이 증가한다.


## 연관된 패턴
-[Chain of Responsiblility](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/ChainOfResponsiblility/leejunseo/README.md)
