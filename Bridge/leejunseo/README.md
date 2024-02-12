# Bridge
- Based on "Design Patterns: Elements of Reusable Object-Oriented Software" by Erich Gamma

## 요약
추상화와 구현을 분리해 개별적으로 수정할 수 있게 만든다.

### 배경 (사용하는 경우)
1. 추상화와 구현 사이의 연결을 영구적으로 유지하고 싶지 않은 경우에 사용할 수 있다.

예를 들어, 추상화 클래스들의 구현이 런타임에서 수정되거나 변경될 수 있는 경우에 사용한다.

1. 상속을 통해 추상화와 구현들이 확장될 수 있는 경우 : 브릿지 패턴을 사용해 독립적으로 확장할 수 있다.
1. 구현 부분이 변경되어도 클라이언트에 영향이 없을 경우 : 즉, 클라이언트의 코드는 다시 컴파일할 필요가 없어야 한다.
1. 클라이언트에게서 구현을 완전히 숨기고 싶은 경우 
1. 여러 객체들 간에 구현을 공유하면서도, 클라이언트는 이를 알지 못하게 하고 싶은 경우

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
1. 구현 클래스의 개수 : 한가지 구현 클래스만 사용되는 경우 추상클래스를 사용하지 않아도 된다. 그럼에도 추상클래스를 사용한다면 구현 클래스가 변경되어도 클라이언트의 코드를 컴파일하지 않아도 된다는 장점이 있다.
1. 언제, 어디서, 누가 구현 클래스를 생성할 것인가? 한 가지 방법은 추상화 클래스가 ConcreteImplementor 클래스에 대한 정보를 모두 알고 있는 것이다. 생성자에서 이들 중 하나를 선택해 만들 수 있다. 또다른 방법은 디폴트 클래스를 지정하고 추후에 사용할 때에 선택하는 것이다.
1. 구현 클래스들을 공유한다 : 
1. 다중 상속을 사용한다 : C++ 에서는 다중상속을 사용해 구현 클래스와 추상화 클래스를 모두 상속받을 수 있다. 그러나 이 방식은 정적으로 이루어지기 때문에 영구적으로 종속된다. 따라서 진정한 브릿지 패턴은 다중 상속으로 구현할 수 없다.

## 구현



## 결과
1. 인터페이스와 구현을 분리할 수 있다 : 구현은 인터페이스에게 영구적으로 종속되지 않는다. 런타임에서 구현 클래스가 설정되기 때문에 런타임에서 이를 변경할 수도 있다.
1. 확장성이 증가한다 : 구현 클래스와 추상화 클래스들을 독립적으로 확장할 수 있다.
1. 자세한 구현을 클라이언트에게서 숨길 수 있다.

## 연관된 패턴
- [Abstract Factory](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/AbstractFactory/leejunseo/README.md)
- [Adapter](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/Adapter/leejunseo/README.md)
