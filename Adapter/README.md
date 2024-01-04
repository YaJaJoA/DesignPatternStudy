# Adapter
- Based on "Design Patterns: Elements of Reusable Object-Oriented Software" by Erich Gamma

## 요약
사용할 클래스를 수정하지 않고도 다른 인터페이스를 통해 사용하기 위한 방법

### 배경 (사용하는 경우)
기존 클래스를 수정할 수 없지만 그 클래스가 구현하지 않는 인터페이스를 통해서 호출해야 할 때 사용한다

## 종류
Adapter는 class adapter과 object adapter 방식으로 구현할 수 있다.
사용해야할 클래스는 Adaptee Class, 구현할 인터페이스는 Target Interface, Adaptee Class를 wrapping하는 클래스를 Adapter Calss라 부르겠다.
1. Class Adapter 
- Adaptee Class와 Target Interface를 모두 Adapter Class에서 상속받는 방식
- Adaptee Class 의 Method 를 구현한 후 Target Interface의 Method로 호출한다
- Concrete Class를 만들기 때문에 Adaptee Class의 동작을 override할 수 있다

2. Object Adapter
- Target Interface를 상속받고 Adaptee Class를 pointer로 가리키는 방식
- 다형성을 사용해 Derived Class 들을 Adapter에서 사용할 수 있다
- Adaptee Class의 동작을 override할 수 없기 때문에 수정이 제한적이다

### 고려할 점
1. **얼마나 많은 동작을 Adapting 해야하는 가?** 변환해야할 동작에 따라 Adapter 방식이 바뀔 수 있다. 단순히 함수의 이름을 변환하는 것부터 복잡한 변환에 이르기까지 요구사항에 맞춰 Adapter Class를 구현해야한다.
2. **부착 가능한 Adapter** 클래스의 재사용성은 클래스를 사용하기 위해 필요한 정보가 적을 때 높아진다. 인터페이스를 통해 Adapting하면 다른 어플리케이션에서 요구하는 Interface를 사용해 Adaptee Class 를 사용할 수 있다.
3. **투명성을 제공하기 위해 양방향 Adpater를 사용해야하는가?** 하나의 클래스를 서로 다른 어플리케이션에서 사용해야할 때 별도의 클래스로 변환하는 대신 양쪽에서 요구하는 Interface를 모두 상속해 사용할 수 있다.

## 구현
1. 추상 함수를 사용함 (Interface)
-
1. Delegate를 사용 
-
1. Parameterized Adapte
-

## 결과
1.
1.
1.

## 연관된 패턴
- [Bridge](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/Bridge/leejunseo/README.md)
- [Decorator](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/Decorator/leejunseo/README.md)
- [Proxy](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/Proxy/leejunseo/README.md)