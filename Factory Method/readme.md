# Factory Method

## 개요

객체 생성을 위한 인터페이스 정의, 하지만 서브클래스가 어느 클래스로 인스턴스화 될지는 모름.
<br>
<br>

## A.K.A

가상 생성자
<br>
<br>

## 동기

문서 프로그램이 있다. 사용자가 프로그램을 실행하면 Document 클래스를 생성할 것이다. 하지만 아직 프로그램은 사용자가 새로운 문서를 작성할 것인지, 기존 문서를 열 것인지는 모른다. 이 때 딜레마가 발생한다. 프로그램은 Document 클래스를 인스턴스화해야 하지만 어떤 클래스인지는 모르고 인스턴스화 될 수 없는 추상 클래스에 대해서만 알고 있다.
<br>
그래서 Factory Method를 사용한다. Factory Method를 사용하면 생성할 Document 하위 클래스에 대한 정보를 캡슐화하고 프레임워크 밖으로 이동시킨다.

## 적용성

언제 쓰는가

<ul>
<li> 생성해야 하는 클래스를 모를 때
<li> 클래스가 생성하는 객체를 하위 클래스가 지정하기를 원할 떄
<li> 클래스는 여러 도우미 하위 클래스 중 하나에 책임을 위임하고, 어떤 도우미 하위 클래스가 위임인지에 대한 지식을 지역화하려고 할 때.
</ul>

## 구성

Product: factory method가 생성하는 객체의 인터페이스를 정의<br>
ConcreteProduct: Product 인터페이스 구현<br>
Creator: Product 타입 객체를 반환하는 factory method 정의<br>
ConcreteCreator: ConcreteProduct의 인스턴스를 반환하기 위해 factory method 상속
<br><br>

## 장단점
Factory Method를 사용하면 어플리케이션별 클래스를 바인딩할 필요가 없다.<br>
코드에서 Product 인터페이스만 다루면 된다. 심지어 사용자 정의 클래스에서도 동작한다.
잠재적 단점으로는 클라이언트가 특정 객체의 생성을 위해 Creator를 하위 클래스로 만들어야 한다. 클라이언트가 Creator를 하위 클래스로 가지고 있으면 하위 클래싱에 상관 없지만, 그렇지 않은 경우에는 다른 변환 지점이 필요하다.
<br><br>

## 샘플 코드
이전 시간에 공부한 Abstract Factory를 사용한 코드에는 문제가 하나 있다. 미로, 방, 문, 벽 등을 생성할 때 하드 코딩한다는 것이다. 이제 이것을 개선 시켜 보자.

```cpp
class MazeFactory {
 public:
  MazeFactory();
  virtual Maze* MakeMaze() const { return new Maze; }
  virtual Wall* MakeWall() const { return new Wall; }
  virtual Room* MakeRoom(int n) const { return new Room(n); }
  virtual Door* MakeDoor(Room* r1, Room* r2) const { return new Door(r1, r2); }
};
```
전 시간에는 Abstract Factory를 사용해서 미로 생성기 객체를 만들고, 그 객체를 이용해서 각각의 미로, 문, 벽 등을 생성해 주었다.<br>
때문에 마법이 부여된 문, 함정이 설치된 방 등 여러가지 변칙을 주려먼 해당 class 생성기들을 만들어 줘야 한다.
<code>BombMazeFactory</code>나 <code>SpikeMazeFactory</code>를 만드는 방식으로 말이다.<br><br>

```cpp
class MazeGame {
 public:
  Maze* CreateMaze();
  // factory methods:
  virtual Maze* MakeMaze() const { return new Maze; }
  virtual Room* MakeRoom(int n) const { return new Room(n); }
  virtual Wall* MakeWall() const { return new Wall; }
  virtual Door* MakeDoor(Room* r1, Room* r2) const { return new Door(r1, r2); }
};
```
MazeGame에서 Maze 객체를 반환하기 때문에 MazeGame 내부의 return 값들을 수정해주기만 하면 손쉽게 BombRoom이나 SpikeDoor 등을 변화를 줄 수 있게 된다.

예를 들자면, 상자를 만드는 기업이 있다. 이 기업은 빨간색, 파란색, 노란색 상자를 만든다. Abstract Factory만 사용했을 때는 빨간색 상자 만드는 공장 따로, 파란색 만드는 공장 따로, 노란색 만드는 공장 따로 돌려서 만들어서 만약 상자 색상이 추가 된다면 해당 색상 상자를 생산하는 공장을 추가로 지어줘야 했다. 하지만 Factory Method를 사용한다면 모든 똑같은 상자를 만든 뒤 그 위에 채색만 다르게 하는 방식으로 바뀌기 때문에 색상이 추가되어도 하나의 공장에서 채색 라인만 늘리면 되게 된다.
<br><br>
## 관련 패턴
<li>Abstract Factory
<li>Prototype
