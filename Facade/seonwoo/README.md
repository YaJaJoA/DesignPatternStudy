### 의도

하위 시스템의 일련의 인터페이스에 대한 통합된 인터페이스를 제공한다.

Facade는 하위 시스템을 사용하기 쉽도록 상위 수준의 인터페이스를 정의

→ 복잡한 서브 시스템 의존성을 최소화하는 방법

→ 클라이언트로 하여금 복잡한 내부 로직을 의식하지 않도록 해준다

### 동기

시스템을 하위 시스템으로 구조화하면 복잡성을 줄일 수 있다. 일반적인 설계 목표 중 하나는 통신 및 하위 시스템 간 종속성을 최소화하는 것이다. 이를 위한 방법 중 하나는 하위 시스템보다 일반적인 기능에 대해 단일하고 간소화된 인터페이스를 제공하는 facade객체를 도입하는 것이다.

### 사용하는 경우

- 복잡한 (서브)시스템에 대한 단순한 인터페이스 제공을 통해 접근을 하도록 하고 싶을때
- 추상 개념에 대한 구현 클래스와 사용자 사이에 너무 많은 종속성이 존재할 때
- 서브시스템을 계층화 시킬 때

### 구조

- Facade: 서브시스템 기능을 편리하게 사용할 수 있도록 단순하고 일관된 통합 인터페이스를 제공, 서브시스템을 구성하는 어떤 클래스가 어떤 요청을 처리해야 하는지 알고 있으며, 사용자의 요청을 해당 서브시스템 객체에 전달
    - 복잡한 서브시스템을 사용하기 쉽게 하는 단순한 창구의 역할
    - 클라이언트와 서브시스템이 서로 긴밀하게 연결되지 않도록 한다.
- Subsystem class : 서브시스템의 기능을 구현하고, Facade객체로 할당된 작업을 실제로 처리한다. 그러나 Facadce에 대한 아무런 정보도 가지고 있지 않음.
    - 수십가지의 라이브러리 혹은 클래스들이 서브시스템에 해당한다

퍼사드 패턴은 여타 다른 디자인 패턴과 달리 클래스 구조가 정형화 되어있지 않다.

클래스 위치나 위임 방식등에 대한 조건이 없다. 그냥 퍼사드 클래스를 만들어 기능 집약화를 해주면 그게 디자인패턴이 된다.

### 구현

서브시스템(하위시스템)

```tsx
class Row {
	constructor(public name: string, public birthday: string, public email: string) {}
}

class DBMS {
	private data: { [key: string]: Row } {}; // (인덱스 시그니쳐)이름(key)이 문자열이고 값이 Row타입이라는 뜻
	
	put(key: string, row: Row) {
		this.data[key] = row;
	}
	
	query(key: string): Row | null { //유니언 타입, 반환값이 Row타입 혹은 null이라는 뜻(키에 해당값이 없을경우)
		return this.data[key] || null; //데이터가 있을 경우 앞의 값을 리턴, 없을 경우 null리턴
	}
}

class Cache {
	private cache: { [ key: string]: Row } = {};

	get(key: string): Row | null {
		return this.cache[key] || null
	}

	put(row : Row)  {
		this.cache[row.name] = row;
	}
}

class Message {
	constructor(private row: Row) {}

	makeName(): string {
		return `Name: ${this.row.name}`;
	}

	makeBirthday(): string {
		return `Birthday: ${this.row.birthday}`;
	}
	makeEmail(): string {
		return `Email: ${this.row.email}`;
	}
}
```

Facade

```tsx
class Facade {
    private dbms: DBMS = new DBMS();
    private cache: Cache = new Cache();

    insert(): void {
        this.dbms.put("유저1", new Row("유저1", "2000-02-14", "user1@naver.com"));
        this.dbms.put("유저2", new Row("유저2", "2000-11-02", "user2@naver.com"));
    }

    run(name: string): void {
        let row: Row | null = this.cache.get(name);

        // 1. 만약 캐시에 없다면
        if (row == null) {
            row = this.dbms.query(name); // DB에 해당 데이터를 조회해서 row에 저장하고
            if (row !== null) {
                this.cache.put(row); // 캐시에 저장
            }
        }

        // 2. dbms.query(name)에서 조회된 값이 있으면
        if (row !== null) {
            const message: Message = new Message(row);

            console.log(message.makeName());
            console.log(message.makeBirthday());
            console.log(message.makeEmail());
        }
        // 3. 조회된 값이 없으면
        else {
            console.log(name + " 가 데이터베이스에 존재하지 않습니다.");
        }
    }
}
```
Client

```tsx
// 1. 퍼사드 객체 생성
const facade = new Facade();

// 2. db 값 insert
facade.insert();

// 3. 퍼사드로 데이터베이스 & 캐싱 & 메세징 로직을 한 번에 조회
const name = "홍길동";
facade.run(name);
```

### 특징

장점

- 서브시스템의 복잡성에 코드를 분리하여, **외부에서 시스템을 사용하기 쉬워진다**
- 하위 시스템 간의 의존 관계가 많은 경우 이를 감소시키고 **의존성을 한 곳으로 모을 수 있다**
- 복잡한 코드를 감춤으로써, **클라이언트가 시스템의 코드를 모르더라도 Facade 클래스만 이해하고 사용 가능**하다

단점

- • 퍼사드 클래스가 서브 시스템에 대한 모든 의존성을 가지게 된다
