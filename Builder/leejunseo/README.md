# Builder
- Based on "Design Patterns: Elements of Reusable Object-Oriented Software" by Erich Gamma

## 요약
복잡한 구조의 클래스를 생성하는 과정을 전담하는 별도의 클래스를 만들어 클래스의 사용과 형성을 분리한다.

### 배경 (사용하는 경우)
1. 클래스의 각 부품들을 생성하는 부분과 부품들을 결합해 클래스를 형성하는 과정을 분리해야 할 때 
1. 복잡한 구조의 클래스를 형성하는 과정이 여러 방식으로 진행될 수 있을 때

## 구현


## 결과물
- 제품 생성 과정을 다양하게 정의할 수 있음
- 부품의 추가와 재정의를 쉽게 할 수 있다
- 클라이언트는 Director에게 간접적으로 프로덕트 생성을 요청
- 클라이언트는 Builder에게서 결과물을 얻음

#### Abstract Factory vs Builder ?
- Abstract Factory는 내부에서 부품 클래스의 생성과 조립이 모두 이루어진다.
- Builder 패턴은 부품 클래스를 생성은 Builder 클래스에서 담당하고, 조립되는 순서와 과정은 Director 패턴에서 이루어진다.
- 정확한 차이가 이것이 맞는 지는 모르겠다.

## 연관된 패턴
- [Abstract Factory](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/AbstractFactory/leejunseo/README.md)
- [Factory Method](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/FactoryMethod/leejunseo/README.md)
