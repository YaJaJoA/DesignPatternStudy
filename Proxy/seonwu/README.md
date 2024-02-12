# Proxy

### 의도

---

다른 객체에 대한 액세스를 제어하기 위해 대리자 또는 플레이스 홀더를 제공

대상 원본 객체를 대리하여 대신 처리하게 함으로써 로직의 흐름을 제어하는 행동패턴

### 동기

---

객체에 대한 액세스를 제어하는 이유는 해당 객체의 생성 및 초기화 비용을 실제로 사용할 때까지 늦추는 것

원본 객체를 수정할수 없는 상황일 때를 극복할 수 있다.

### 구조

---

- Proxy
    - 대상 객체(RealSubject)를 중계할 대리자 역할
    - 프록시는 대상 객체를 합성(composition)한다.
    - 프록시는 대상 객체와 같은 이름의 메서들르 호출하며, 별도의 로직을 수행 할수 있다 (인터페이스 구현 메소드)
- Subject
    - Proxy와 RealSubejct를 하나로 묶는 인터페이스 (다형성)
    - 대상 객체와 프록시 역할을 동일하게 하는 추상 메소드 정의 - `operation()`
    - 인터페이스가 있기 때문에 클라이언트는 Proxy역할과 RealSubject 역할의 차이를 의식할 필요 없음
- RealSubject
    - 원본 대상 객체
- Client
    - Subject 인터페이스를 이용하여 프록시 객체를 생성해 이용
    - 클라이언트는 프록시를 중간에 두고 프록시를 통해 RealSubject와 데이터를 주고받음
    

### 

### 결과

---

프록시 패턴은 객체에 액세스 할 때 간접성을 도입한다.

추가된 간접성은 프록시의 종류에 따라 여러 용도로 사용 가능

1. 원격 프록시는 객체가 다른 주소 공간에 존재하는 사실을 숨길 수 있다
2. 가상 프록시는 객체를 필요에 따라 생성하는 것과 같은 최적화를 수행할 수 있다
3. 보호 프록시 및 스마트 참조는 객체에 액세스할 때 추가 관리작업을 허용한다

그 외에도 아래의 효과를 얻을 수 있다

- 보안 : 프록시는 클라이언트가 작업을 수행할 수 있는 권한이 있는지 확인하고 검사 결과가 긍정적인 경우에만 요청을 대상으로 전달
- 캐싱 : 프록시가 내부 캐시를 유지하여 데이터가 캐시에 아직 존재하지 않는 경우에만 대상에서 작업이 실행되도록 한다
- 데이터 유효성 검사 : 프록시가 입력을 대상으로 전달하기 전에 유효성을 검사
- 지연 초기화 : 대상의 생성 비용이 비싸다면 프록시는 그것을 필요로 할 때까지 연기할 수 있다.
- 로깅 : 프록시는 메소드 호출과 상대 매개변수를 인터셉트하고 이를 기록한다.
- 원격 객체 : 프록시는 원격 위치에 있는 객체를 가져와서 로컬처럼 보이게 할 수 있다.

### 구현

---

가상프록시를 통해 자원관리하는 예시를 구현한다.

이미지 뷰어 프로그램을 만들어 고해상도 이미지를 불러와 사용자에게 보여준다.

고해상도 이미지 경로를 인자로 받아 메모리에 적재하고 showImage() 메소드 호출로 화면에 렌더링한다.

Subject

```tsx
// 대상 객체와 프록시 객체를 묶는 인터페이스 (다형성)
interface IImage {
    showImage(): void; // 이미지를 렌더링하기 위해 구현체가 구현해야 하는 추상메소드
}
```

RealSubject

```tsx
// 대상 객체 (RealSubject)
class HighResolutionImage implements IImage {
    private img: string;

    constructor(path: string) {
        this.loadImage(path);
    }

    private loadImage(path: string): void {
        // 이미지를 디스크에서 불러와 메모리에 적재 (작업 자체가 무겁고 많은 자원을 필요로함)
        try {
            setTimeout(() => {
                this.img = path;
                console.log(`${path}에 있는 이미지 로딩 완료`);
            }, 1000);
        } catch (e) {
            console.error(e);
        }
    }

    showImage(): void {
        // 이미지를 화면에 렌더링
        console.log(`${this.img} 이미지 출력`);
    }
}
```

Proxy

```tsx
// 프록시 객체 (Proxy)
class ImageProxy implements IImage {
    private proxyImage: IImage | null = null;
    private path: string;

    constructor(path: string) {
        this.path = path;
    }

    showImage(): void {
        // 고해상도 이미지 로딩하기
        this.proxyImage = new HighResolutionImage(this.path); //RealSubject
        this.proxyImage.showImage(); //RealSubject의 operation()
    }
}
```

Client

```tsx

const highResolutionImage1: IImage = new ImageProxy("./img/고해상도이미지_1");
const highResolutionImage2: IImage = new ImageProxy("./img/고해상도이미지_2");
const highResolutionImage3: IImage = new ImageProxy("./img/고해상도이미지_3");

highResolutionImage2.showImage();
```

‘이미지 로딩 완료’ → ‘이미지 출력’ 텍스트가 순서대로 출력됨

이렇게 작업하면 대상 객체 대신에 프록시 객체에서 경로 데이터를 지니고 있다가 `showImage`를 호출하면 그때서야 대상 객체를 로드(lazyload)하여, 이미지를 메모리에 적재하고 대상 객체의 `showImage()`메서드를 위임 호출하여 실제 메소드를 호출하는 시점에 메모리 적재가 이루어지기 때문에 불필요한 자원낭비가 발생하지 않게 된다.

### Proxy/Reflect 객체

---

자바스크립트 진영은 독립적인 Proxy객체가 존재한다.

자바스크립트에서 Proxy 객체의 역할은 대상 객체를 감싸(wrapping) 속성 조회, 할당, 열거 및 함수 호출 등 여러 기본 동작을 가로채 특별한 다른 동작을 가미시키는 대리자 역할을 한다.

대상 객체는 Object, Array 등 자바스크립트의 모든 자료형이 대상이 될 수 있다.

```tsx
let obj = {
	name : 선우
	print: function () {
		console.log(`my name is ${this.name}`);
	}
}

obj.print = new Proxy(obj.print, {
		apply(target, thisArg, args) {
			console.log('메서드 실행할 때 중간에 가로채 로직 시행');
			console.log('target: ', target); // 대상 함수
      console.log('thisArg: ', thisArg); // this의 값
      console.log('args: ', args); // 매개변수 목록 (배열)

			console.log('이름 수정');

			thisArg.name='김선우';

			Reflect.apply(target, thisArg, args); //대상 원본 함수 실행
		}
	}
});

obj.print();
```

```tsx
메서드 실행할 때 중간에 가로채 로직 시행
target: [Function: print]
thisArg: { name: '선우' , print: [Function: print] }
args: []
이름 수정
My name is 김선우
```
