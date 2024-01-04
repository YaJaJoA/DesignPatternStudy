# Adapter
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

## 결과물

-
## 연관된 패턴
