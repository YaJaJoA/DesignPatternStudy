# Prototype
- Based on "Design Patterns: Elements of Reusable Object-Oriented Software" by Erich Gamma

## 요약
상속을 통해 서브 클래스를 만드는 대신, 원형이 되는 인스턴스를 복제하는 방법으로 인스턴스를 생성함.

### 배경 (사용하는 경우)
- 서로 다른 두 프레임워크 간에 인스턴스 생성이 필요한 경우
- 클래스의 확장 또는 생성이 런타임에 결정되는 경우
- Factory 클래스의 위계가 Product 클래스의 위계와 병렬적으로 확장되는 것을 피하는 경우
- 인스턴스가 몇 가지 상태의 조합 중 하나로 생성되는 경우 (각각을 클래스로 정의하기 보단, 템플릿을 만들고 복제하는 것이 더 편한 경우)

## 구현


## 장단점
1. 생성할 Prototype의 종류가 런타임에 결정된다.
1. 변수들의 값 만을 달리해 새로운 오브젝트를 정의할 수 있다. (클래스를 정의하지 않아도 됨)
1. 구조를 달리해 새로운 오브젝트를 정의할 수 있다.
1. 서브클래스 생성을 줄일 수 있다.
1. 어플리케이션에서 동적으로 클래스를 설정할 수 있다. (생성할 클래스를 런타임에 설정할 수 있음)
   - 타입을 변수로 전달할 수 없는 C++ 같은 언어에서 장점임.
  


## 연관된 패턴
- [Abstract Factory](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/AbstractFactory/leejunseo/README.md)
- [Composite](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/Composite/leejunseo/README.md)
- [Decorator](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/Decorator/leejunseo/README.md)
