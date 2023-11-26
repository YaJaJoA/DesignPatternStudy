# 빌더 패턴



**복잡하게 구성된 객체를 효과적으로 생성하는 패턴**이다.

알려진 Builder패턴은 2가지 있다.

1. 생성시 지정해야 할 인자가 많을 때 사용하는 패턴 
    - 생성해야하는 객체가 Optional한 속성을 많이 가질 때 사용하기 유용하다
        
        ```jsx
        class Tourplan{
        	Tourplan(stringm title, Date startdate, int nights, int days,
        	string whereToStay, DetailPlan* plans);
        }
        new TourPlan("여행 계획", Date.of(2021,12, 24), 3, 4, "호텔",
            new DetailPlan(1, "체크인")); 
        //넘겨야 할 인자가 많아 타입 혹은 순서에 의한 오류가 발생할 수 있으며 가독성이 떨어진다
        ```
        
2. 객체 생성 시 여러 단계를 순차적으로 거칠 때, 이 단계의 순서를 결정해 두고 각 단계를 다양하게 구현할 수 있도록 하는 패턴

GoF에서 다루는 내용은 두번째 빌더 패턴에 속한다.
현재의 개발자들이 사용하는 빌더 패턴은 1번에 더 가깝다.

인자를 많이 받아야 하는 상황에서 생성자를 가지는 객체를 생성할 때, 더 유연하고 바람직한 코드를 짜기 위해 사용하는 패턴



### 정의
---
- 빌더 패턴은 **복잡한 객체**를 생성하는 클래스와 표현하는 클래스를 분리하여, 동일한 절차에서 서로 다른 표현을 생성하는 방법을 제공
    - 여기서 ‘표현’ → ‘조립’ 으로 생각하면 이해가 쉽다

### 구조
---
- *Builder*: 무언가를 만드는 책임을 갖는다. 무언가를 만들고 반환하는 메서드를 제공해야함(추상메서드) 예제에서는 `House` 객체의 일부 요소들을 생성하기 위한 추상 인터페이스 정의
- ConcreteBuilder: Builder의 추상 메서드를 구체적으로 `구현` 한다.
- Dircetor : Builder 에서 제공하는 추상메소드들을 정해진 순서대로 정확히 호출하는 책임을 갖는다.
- Product: 생성할 복합 객체를 표현한다. ConcreteBuilder는 제품 내부 표현을 구축하고 복합 객체가 어떻게 구성되는지에 관한 절차를 정의한다. 예제에서는 `House`

### 구현

---

```tsx
class House {
    private rooms: number[] = [];
    private doors: [number, number][] = []; //튜플형식

    addRoom(roomNumber: number): void {
        this.rooms.push(roomNumber);
    }

    addDoor(roomFrom: number, roomTo: number): void {
        this.doors.push([roomFrom, roomTo]);
    }

    // Additional methods or properties as needed
}
```

```tsx
interface HouseBuilder {
    buildRoom(roomNumber: number): void;
    buildDoor(roomFrom: number, roomTo: number): void;
    getHouse(): House;
}
```

```tsx
export default class Director {
    private builder: HouseBuilder;

    constructor(builder: HouseBuilder) {
        this.builder = builder;
    }

    construct(): House {
        this.builder.buildRoom(1);
        this.builder.buildRoom(2);

        this.builder.buildDoor(1, 2);

        return this.builder.getHouse();
    }
}
```

```tsx
class ConcreteHouseBuilder implements HouseBuilder {
    private house: House = new House();

    buildRoom(roomNumber: number): void {
        this.house.addRoom(roomNumber);
    }

    buildDoor(roomFrom: number, roomTo: number): void {
        this.house.addDoor(roomFrom, roomTo);
    }

    getHouse(): House {
        return this.house;
    }
}
```

```tsx
import House, Director, ...

const director = new Director(new HouseBuilder())

const result = director.build()

console.log(result) 

```

### 결과

장점

- 유연성을 확보할 수 있음
- 생성과 표현에 필요한 코드를 분리
    - 가독성을 높일 수 있음 (상황에 따라선 오히려 안좋을 수도 있음)
    - 재사용성을 높일 수 있음
- 복합 객체(Product)를 생성하는 절차를 좀 더 세밀하게 나눌 수 있다 
→ 변경이 용이하다(추가, 제거 등)

단점

- 많은 코드를 요구한다
