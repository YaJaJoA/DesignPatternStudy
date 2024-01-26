# Decorator

### 의도

---

객체에 동적으로 새로운 책임(기능)을 추가할 수 있게 한다.(서브클래스를 생성하는 것보다 융통성 있는 방법을 제공한다.)

→ 객체로부터 독립적인 기능을 계속해서 추가하면서 확장할 수 있다.

### 동기

---

전체 객체가 아닌 개별적인 객채에 대하여 새로운 책임을 추가해야 하는 상황이 있다.

이렇게 새로운 서비스의 추가가 필요 할 떄 일반적으로는 상속을 통해 해결이 가능하다.

이미 존재하는 클래스를 상속받고 또다른 클래스에서 필요한 속성을 상속받아와서 서브클래스의 인스턴스에 원하는 속성이 생기도록 할 수 있다. 다만 이러한 속성의 선택이 정적이므로 유용한 방법이 아니다. 

더 좋은 방법은 필요한 기능을 추가하는 다른 객체에다가 해당 구성요소를 둘러싸는것이다.

무언가를 감싸는 객체를 장식자(decorator) 라고 한다.

- 장식되는 대상과 장식을 동일한 개념으로 처리
- 기능을 장식처럼 계속 추가할 수 있는 패턴
- 기능을 실행 중에 동적으로 변경 또는 확장 할 수 있는 패턴

### 구조

---

- Component(Interface) : 원본 객체와 장식된 객체 모두를 하나의 타입으로 묶는 역할
- ConcreteComponent : 원본 객체 (데코레이팅 할 객체)
- Decorator : 추상화된 장식자 클래스
    - 원본 객체를 합성(composition)한 wrapper 필드와 인터페이스의 구현 메소드를 가지고 있다.
- ConcreteDecorator : 구체적인 장식자 클래스
    - 부모 클래스가 감싸고 있는 하나의 Component를 호출하면서 호출 전/후로 부가적인 로직을 추가할 수 있다.

### 사용처

---

- 데코레이터 패턴은 객체들을 사용하는 코드를 훼손하지 않으면서 런타임에 추가 행동들을 객체들에 할당할 수 있어야 할 때 사용
- 상속을 사용하여 객체의 행동을 확장하는 것이 어색하거나 불가능할 때 사용

### 구현

---

```jsx
interface Component {
    operation(): string;
}
```

```jsx
class ConcreteComponent implements Component {
    public operation(): string {
        return 'ConcreteComponent';
    }
}
```

```jsx
class Decorator implements Component {
    protected component: Component;

    constructor(component: Component) {
        this.component = component;
    }
    public operation(): string {
        return this.component.operation();
    }
}
```

```jsx
class ConcreteDecorator extends Decorator {
    public operation(): string {
        return `ConcreteDecoratorA(${super.operation()})`;
    }
}
```

### 장단점

---
장점
- 새 자식 클래스를 만들지 않고도 객체의 확장이 가능 → 설계의 융통성 증대
- 클래스 계층의 상부 클래스에 많은 기능이 누적되는 것을 피할 수 있다.
- 런타임에 객체들로부터 책임을 추가하거나 제거 가능
- 객체를 여러 데코레이터로 래핑하여 여러 행동을 합성 가능


단점
- 래퍼들의 스택에서 특정 래퍼를 제거하기 어렵다
- 데코레이터의 행동이 데코레이터 스택 내의 순서에 의존하지 않는 방식으로 데코레이터를 구현하기가 어렵다
- 계층들의 초기 설정코드가 보기 어려울 수 있다.
