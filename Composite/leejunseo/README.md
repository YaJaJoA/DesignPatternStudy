# Composite
- Based on "Design Patterns: Elements of Reusable Object-Oriented Software" by Erich Gamma

## 요약
각각의 객체들을 하나로 묶어서 사용할 수 있게 만든다

### 배경 (사용하는 경우)
비슷한 맥락에서 사용되는 여러 개의 클래스들이 있는 경우, 각각의 클래스를 생성하고 관리하기 보단
이를 하나로 묶어 사용하는 것이 편리하다.
따라서 여러 오브젝트들을 하나로 묶어 사용하는 Composite 클래스를 만들어 사용한다.

- 클래스 계층의 일부 또는 전체를 표현할 때
- Client가 오브젝트들의 Composition과 개별적인 오브젝트를 구별없이 사용하고 싶을 때

## 구현
Composite 패턴에서 중요한 것은 여러 개의 primitive class와 이들을 하나로 묶을 container를 모두 표현할 수 있는 공통의 추상 클래스를 만드는 것이다.
추상 클래스로 container를 구성함으로써 여러 개의 primitive class를 저장하고 호출할 수 있다.

Composite 패턴을 사용할 때에는 다음을 고려해야한다.
1. 부모로의 레퍼런스를 명시 : child에서 parent로 레퍼런스를 가지고 있다면 composite구조를 순회하기 쉬워진다.
1. Component 공유 : composite class의 component들을 서로 공유하는 것이 효율적일 때도 있지만, 각 component가 하나의 parent만을 가져야할 때가 있다. 이런 경우는 Flyweight 패턴을 사용해 여러 개의 parent를 저장하지 않을 수 있다.
1. Component의 Interface의 크기 : Composite 패턴은 composite클래스와 primitve 클래스들을 모두 표현할 수 있는 interface를 사용한다. 따라서 interface가 많은 클래스를 표현하기 위해 방대해질 수 있다. 하지만 이는 객체지향 프로그래밍이 지향하는 바와 어긋난다. 따라서 이를 절충할 수 있는 방안을 고안해야한다.
1. Child management operation을 구현하기 : Composite 구조에서 Component를 관리할 수 있는 코드를 작성해야한다.
1. Component의 모음을 Component로 구현해야하는가? : --??--
1. Child 정렬 순서
1. 성능향상을 위한 캐싱
1. 누가 Component를 삭제할 것인가?
1. Component 저장을 위한 자료구조 선택

## 결과물
- Composite 패턴은 primitive 오브젝트와 composite 오브젝트로 구성된 클래스 계층 구조를 정의한다. primitive 오브젝트들은 더 복잡한 composite 오브젝트로 묶일 수 있고, 그 오브젝트들도 다른 composite 오브젝트로 구성될 수 있다.
- Composite 패턴은 primitive 오브젝트와 composite 오브젝트를 동일하게 취급할 수 있기 때문에 사용이 간편해진다.
- 새로운 종류의 component를 만들기 쉬워진다. composite 오브젝트를 만드는 것으로 기존과 동일한 방식으로 사용 가능한 새로운 클래스를 정의할 수 있다.
- 소프트웨어 디자인을 general하게 만들 수 있다

## 연관된 패턴
-[Chain of Responsiblility](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/ChainOfResponsiblility/leejunseo/README.md)
-[Decorator](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/Decorator/leejunseo/README.md)
-[Flyweight](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/Flyweight/leejunseo/README.md)
-[Iterator](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/Iterator/leejunseo/README.md)
-[Visitor](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/Visitor/leejunseo/README.md)
