# Decorator
- Based on "Design Patterns: Elements of Reusable Object-Oriented Software" by Erich Gamma

## 요약
Subclass를 만들지 않고도 기존 클래스와 같은 인터페이스를 사용하는 데코레이터를 사용해 기능을 추가한다.

### 배경 (사용하는 경우)
- 동적으로 기능을 추가해야하고, 기존 클래스 사용에 지장을 주지 않아야 하는 경우
- subclass를 만들지 않는 것이 효율적인 경우 : 기능들의 조합이 다양해 class로 만들기 어렵거나, class의 정의가 subclass로 인해 가려질 경우

## 구현
Component : 동적으로 기능이 추가될 오브젝의 인터페이스 
Decorator : 추가할 기능을 위한 인터페이스, Component 클래스의 레퍼런스를 가진다. 
ConcreteComponent : 기능이 추가될 클래스

Decorator는 Component 인터페이스를 구현하면서, Component 클래스에 대한 레퍼런스를 가진다. 따라서 Concreteomponent를 사용하는 방법과 동일하게 Decorator를 사용하면서도 Decorator에서 정의한 기능을 추가적으로 사용할 수 있다.
Component의 기능을 그대로 사용할 수 있다는 점에서 투명성을 제공한다.

1. Component 인터페이스를 그대로 사용할 수 있게 구현한다.
2. Decorator의 추상 클래스는 생략할 수 있다. 적은 종류의 기능을 추가할 경우 추상 Decorator 클래스는 생략할 수 있다.
3. Component 클래스들은 가볍게 유지해야 한다. interface를 공유해야하기 때문에 Component 클래스가 복잡해지면 Decorator 클래스들도 복잡해질 수밖에 없다. 사용하지 않는 기능 때문에 불필요한 subclass 들이 만들어질 수 있다.
4. Decorator는 함수가 내부에서 동작하는 방법 자체(guts)를 바꾸기 보단 겉으로 드러나는 함수(skin)를 바꾸는 것이 낫다.

```
class Component {
    virtual void A() = 0;
    virtual void B() = 0;
}

class CompA : Component {
    virtual void A(){
        cout << "CompA" << endl;
    }
    virtual void B(){ return; }
}

class DecoratorA : Component {
    Component c;
    virtual void A(){
        cout << "DecoratorA" << endl;
        c.A();
    }
    
    virtual void B(){
        cout << "DecoratorA.B" << endl;
        c.B();
    }
    virtual void C(){
        cout << "new responsiblity" << endl;
    }
}

void main(){
    auto comp = CompA();
    auto deco = DecoratorA();
    deco.c = comp;
    deco.A(); 
    //>>>DecoratorA
    //>>>CompA
    deco.C();
    //>>>new responsiblity
}

```

## 결과물

1. 서브클래스보다 유연하게 기능을 추가한다 : Runtime에 Decorator를 사용해 기능을 추가할 수 있다. 따라서 subclass를 사용한 정적인 기능 추가보다 유연하게 사용할 수 있다.
2. 클래스 계층을 간소화할 수 있다 : 기능 추가 만을 위한 클래스를 정의하는 것을 피할 수 있다. 따라서 상속으로 인해 기능이 제한되거나 가려지는 일을 방지할 수 있다.
3. Decorator와 Component는 동일한 객체가 아니다 : Decorator와 소유하고 있는 Component 는 동일한 객체가 아니기 때문에 인스턴스의 identity에 의존해서는 안된다.
4. 작은 객체가 많아진다 : Decorator를 사용하면 기능 추가를 위한 작은 객체들이 매우 많아진다. 이는 시스템을 복잡하게 만들고 디버깅을 어렵게 한다.


## 연관된 패턴
- [Adapter](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/Adapter/leejunseo/README.md)
- [Composite](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/Composite/leejunseo/README.md)
- [Strategy](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/Strategy/leejunseo/README.md)
