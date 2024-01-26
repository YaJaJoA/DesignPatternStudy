# Facade
- Based on "Design Patterns: Elements of Reusable Object-Oriented Software" by Erich Gamma

## 요약
복잡한 시스템을 사용자가 쉽게 사용할 수 있도록 단순화된 인터페이스를 제공한다.

### 배경 (사용하는 경우)
어플리케이션의 구조가 복잡해지고 규모가 커지면 사용자가 이를 사용하기 어려워진다. 또는 서브 시스템을 만드는 경우 대다수의 사용자들은 내부 클래스들을 직접 다루기 보단 정해진 시나리오로 기능 만을 사용하는 경우가 많다. Facade 패턴은 사용자가 쉽게 기능을 사용할 수 있도록 단순화된 인터페이스를 제공한다.

## 구현
Facade는 서브 시스템의 클래스들에 대한 레퍼런스를 가지고 기능을 구현한다. 서브 시스템의 클래스들은 Facade에 대한 정보를 가지고 있지않는다. 
따라서 서브 시스템은 Facade의 구조에 상관없이 독립적으로 변경될 수 있다. 
Facade는 이러한 변화에 맞춰 로직을 변경해야한다.


## 결과물
Facade는 사용자가 서브 시스템을 사용하는 방법, 시나리오를 미리 구현하여 단순화된 인터페이스로 제공한다. 
사용자는 서브 시스템에 대한 정보 없이 Facade 만을 사용해 이를 사용할 수 있다. 
Facade 패턴의 가장 큰 특징은 서브 시스템과 사용자 간의 의존 관계가 없다는 점이다.
Facade 클래스가 서브 시스템과 사용자 간의 의존 관계를 대신한다.
또한 Facade는 서브 시스템 접근에 있어서 사용을 강제하지 않는다. 즉, Facade를 사용하지 않고 서브 시스템에 접근할 수 있다.



## 연관된 패턴
-[Abstract Factory](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/AbstractFactory/leejunseo/README.md)
