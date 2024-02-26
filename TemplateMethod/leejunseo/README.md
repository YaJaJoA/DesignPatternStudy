# TemplateMethod
- Based on "Design Patterns: Elements of Reusable Object-Oriented Software" by Erich Gamma

## 요약
알고리즘의 틀을 만들고, 알고리즘을 구성하는 각 단계들은 서브클래스가 구현하게 만든다.
알고리즘의 구조를 변경하지 않고도 특정 단계들을 수정할 수 있게 만든다.

### 배경 (사용하는 경우)
알고리즘을 구현할 때에

1. 반드시 사용될 부분을 정해놓고, 구현은 서브클래스들이 만들게 할 때
1. 중복된 코드를 피하기 위해 서브클래스들이 공통적으로 수행할 동작들을 공통의 클래스에 정의하고 싶을 때
1. 서브클래스의 확장을 재어하고 싶을 때 
    - Hook을 사용해 서브클래스들의 기능 확장을 제어할 수 있다.

## 구현
1. AbstractClass (Application)
    - `primitive operation` : 서브클래스들이 구현할 알고리즘의 각 단계
    - `template method` : 알고리즘의 틀을 정의한 메소드. `template method`는 `primitive operation`을 호출해 기능을 구현한다.
1. ConcreteClass (MyApplication)
    - ConcreteClass 는 `primitive operation`을 구현해 알고리즘을 변화시킬 수 있다.

### 고려할 점
1. **C++ : Access Control 사용** `primitive opration`들을 `protected pure virtual` 함수로 선언하면 ConcreteClass 들이 반드시 구현해야 하고, 외부에서 접근하는 것을 제한할 수 있다.
1. **`primitive operation`을 최소화** `primitive operation`의 개수가 많아지면 불필요한 자세한 부분까지 ConcreteClass에서 구현해줘야 할 수 있다.
1. **명명 규칙을 정한다** `primitive operation` 임을 알아볼 수 있도록 명명규칙을 정하는 것을 고려할 수 있다.

## 결과
1. **Hollywood Principle** : Template Method는 AbstractClass 에서 ConcreteClass들을 호출할 수 있게 만든다. 의존성을 역전하기 때문에 Client는 AbstractClass에 대한 정보만을 사용해 알고리즘을 사용할 수 있다. 즉, Concrete Method에 대한 정보 없이도 Template Method 만을 사용해 기능을 사용할 수 있음을 의미한다. 
1. **`Template Method`는 다양한 패턴들의 근간이 된다.** 의존성을 역전하는 것은 여러 디자인 패턴의 핵심이다. 서브클래스들의 Implementation에 대한 정보 없이도 Template Method의 틀을 사용해 알고리즘을 구성할 수 있다.

## 연관된 패턴
- [Factory Method](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/FactoryMethod/leejunseo/README.md)
- [Strategy](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/Strategy/leejunseo/README.md)
