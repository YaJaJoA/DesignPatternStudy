# Singleton
- Based on "Design Patterns: Elements of Reusable Object-Oriented Software" by Erich Gamma

## 요약
클래스의 인스턴스가 단 한개만 존재하도록 유지함

### 배경 (사용하는 경우)
프로그램의 어느 곳에서 클래스에 접근해도 유일한 인스턴스가 사용되도록 보장한다.

## 구현
C++의 경우 
```
class Singleton{
public:
    Singleton* Instance(){
        if(_instance == 0){ // Singleton 클래스의 Instance가 존재한다면 그 Instance를 return
            _instance = new Singleton(); // 존재하지 않는다면 새로 생성한다
        }
        return _instance;
    }
protected:
    Singleton(); // Derived Class에선 접근할 수 있어야 함
private:
    static Singleton* _instance = 0; // 유일한 Instance
}
```
위와 같이 `Singleton()`을 `Protected`로 선언하면 외부코드에서는 `Instance`를 직접 생성할 수 없다. `Singleton::Instance()`는 유일한 인스턴스를 반환해준다.


## 결과물
1. **유일한 인스턴스에 접근하는 것을 보장한다.** 간접적으로 인스턴스를 생성하고 접근하게 만들기 때문에 인스턴스가 유일하도록 제한할 수 있다.
1. **상속을 통해 동작과 구성 요소를 수정할 수 있다.** 싱글톤 클래스를 상속받아 함수와 동작 방식 등을 수정할 수 있다.
1. **인스턴스의 개수를 늘릴 수 있다.** 기존에 싱글톤이었던 클래스의 인스턴스를 늘리고 싶다면 인스턴스를 생성하는 부분만 수정해주면 된다.
1. **클래스 함수보다 유연하게 동작한다.** 실제 인스턴스의 멤버함수를 호출하기 때문에 `class method` (`static method`)를 사용하는 것보다 제약이 덜하고 유연하게 사용할 수 있다. (C++ : `static method`는 `virtual`이 될 수 없기 때문에 `overriding`이 제한적이다.)

## 연관된 패턴
- [Abstract Factory](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/AbstractFactory/leejunseo/README.md)
- [Prototype](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/Prototype/leejunseo/README.md)
- [Builder](https://github.com/YaJaJoA/DesignPatternStudy/blob/main/Builder/leejunseo/README.md)