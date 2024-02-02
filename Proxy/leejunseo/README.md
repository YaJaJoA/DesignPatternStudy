# Proxy
- Based on "Design Patterns: Elements of Reusable Object-Oriented Software" by Erich Gamma

## 요약
다른 오브젝트에 접근하기 위해 미리 자리를 맡아두는 대리자를 제공한다.

### 배경 (사용하는 경우)
생성과 초기화에 큰 비용이 들지만 사용하기 전까지 생성할 필요가 없는 오브젝트가 있을 수 있다.
이러한 오브젝트는 사용 전에 미리 생성되면 메모리와 시간이 낭비될 수 있다. 오브젝트의 생성을 늦추면서도 기능 상에 지연이 되지 않으려면 오브젝트가 생성되기 전에 대신 기능을 수행할 대상이 필요하다.

Proxy는 어플리케이션의 기능을 수행하면서도 오브젝트를 나중에 생성할 수 있도록 기능 수행의 역할을 대신 전해준다. Proxy는 대상이 되는 오브젝트에게 명령을 전달해주거나 데이터를 저장했다가 전달한다.

## 구현
Proxy는 Subject(전달해줄 대상)의 정보를 알지 않아도 된다. 인터페이스를 통해 필요한 기능을 실행할 수 있도록 구현하여도 무방하다. 그러나 Subject를 필요에 의해 생성할 경우, 그 정보를 알아야 한다.

## 결과물
- Remote Proxy는 **다른 메모리 공간(서로 다른 프로세스, 서로 다른 프로그램 등)에 접근한다는 사실을 숨길 수 있다**. 다른 메모리 공간에 접근해야하는 어플리케이션을 Proxy를 통해 접근하도록 만들어 동일한 메모리 공간을 사용하는 것으로 만들 수 있다. 이 경우, Proxy가 메모리 공간 간의 소통을 전담한다.

- Virtual Proxy는 **오브젝트 생성 및 초기화를 유예할 수 있다**. 생성에 많은 비용이 드는 경우 이를 유예, 관리해 효율성을 높일 수 있다.



## 연관된 패턴
-[Adapter](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/Adapter/leejunseo/README.md)
-[Decorator](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/Decorator/leejunseo/README.md)
