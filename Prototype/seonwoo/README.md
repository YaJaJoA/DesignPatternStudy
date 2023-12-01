# 원형(Prototype) 패턴

### 정의

- **실행 중에 생성된 객체로 다른 객체를 생성하는 패턴**
    
    일반적으로 객체의 생성은 클래스 이름 앞에 `new`키워드를 사용해서 생성된다
    
    하지만 프로토타입 패턴의 경우 new와 클래스의 이름이 아닌, 이미 생성된 객체를 통해서 새로운 객체를 생성한다.
    
- **Prototype으로 만든 객체의 상태를 변경해도 원본 객체의 상태는 변경되지 않도록 해야함**
**(DeepCopy; 깊은 복사)**
    
    이때 원본 객체와 생성된 객체간에는 어떠한 상태도 서로 공유하지 않고, 독립적이다.
    → 원본 객체의 상태값은 깊은 복사 방식으로 복사본의 상태값으로 할당한다.
    

### 동기(문제)

객체가 있고, 그 객체의 복사본을 만들어 사용해야 하는 상황이라고 가정하자

그러기 위해서는 같은 클래스의 새 객체를 생성해야 한다. 그런 다음 원본 객체의 모든 필드를 살펴본 후 해당 값들을 새 객체에 복사하면 된다.

여기서 만약 필드의 일부가 비공개이거나, 필드가 너무 많은 경우 객체를 복사하는데 문제가 생긴다.

또한 객체의 클래스를 알아야 하므로, 원본 클래스에 의존적인 코드를 작성해야 한다.

### 활용

제품의 `생성`, `복합`, `표현` 방법에 독립적인 제품을 만들때 사용한다.

- 인스턴스화할 클래스를 런타임에 지정할 때(동적 할당)
- 제품 클래스 계통과 병렬적으로 만드는 팩토리 클래스를 피하고 싶을 때
- 객체를 생성하는데 비용이 들고, 이미 유사한 객체가 존재하는 경우에 사용된다.

### 구조

1. Prototype 원형 : 
인스턴스를 복사하여 새로운 인스턴스를 만들기 위한 메소드를 정의
2. ConcretePrototype 구체적인 원형 :
인스턴스 복사 메소드를 어떻게 구현할지를 결정한다.
3. Client 이용자 :
프로토타입을 저장하고 필요한 때에 복사해서 전달해주는 역할을 한다.

### 구현

자바스크립트는 `Object.assign()` 메서드를 통해 바로 프로토타입 패턴을 사용 가능하다.

입력한 문자로 문자열을 감싸주는 `MessageBox`와 밑줄을 그어주는 `UnderlinePen` 두 가지를 구현한 내용이다.

```tsx
abstract class Product {
    abstract use(s: string): void;
    createClone(): Product {
        return Object.assign(Object.create(Object.getPrototypeOf(this)), this);
    }
}

class MessageBox extends Product {
    constructor(private decoChar: string) {
        super();
        this.decoChar = decoChar;
    }

    use(s: string) {
        const decoLenth = s.length + 2;
        const line = this.decoChar.repeat(decoLenth);
        
        console.log(line);
        console.log(this.decoChar + s + this.decoChar);
        console.log(line);
    }

    createClone(): Product {
        return this.clone();
    }
}

class UnderlinePen extends Product {
    constructor(private ulChar: string) {
        super();
        this.ulChar = ulChar;
    }

    use(s: string) {
        console.log(s);

        const line = this.ulChar.repeat(s.length);
        console.log(line);
    }

    createClone(): Product {
        return this.clone();
    }
}

class Manager {
    private showcase = new Map<string, Product>();

    register(name: string, prototype: Product) {
        this.showcase.set(name, prototype);
    }

    create(name: string): Product {
        const product = this.showcase.get(name);
        if (!product) {
            throw new Error(`Product ${name} is not registered.`);
        }
        return product.createClone();
    }
}
```

### 결과

원형 패턴은 추상 팩토리 및 빌더와 비슷한 결과를 가진다.

사용자 쪽에는 구체적인 제품을 알리지 않아도 되기 때문에 사용자 쪽에서 다룰 클래스가 적다.

수정하지 않고도 응용프로그램에 따라 필요한 클래스들과 동작할 수 있게 된다.

- 런타임에 새로운 제품을 추가하고 삭제가능
- 값을 다양화함으로써 새로운 객체를 명세한다
- 구조를 다양화함으로써 새로운 객체를 명세
- 서브클래스의 수를 줄인다
- 동적으로 클래스에 따라 응용프로그램을 설정 가능
