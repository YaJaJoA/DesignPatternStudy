# Template Method
## 개요
알고리즘의 구조만 정의하고, 알고리즘 각 단계 처리를 서브 클래스에서 재정의할 수 있게 함
<br>
<br>

## 동기
코드의 중복을 피하고, 알고리즘의 일부를 다양하게 수정하면서 일관된 구조를 유지해야하는 상황을 해결하기 위해서 나타났다.
예를 들어 철권같은 격투게임에서 각 캐릭마다 공격하는 방식은 비슷하지만, 각 캐릭터가 공격하는 세부적인 방법을 다르게 나타내야하는 상황 등
구조를 일반화하고 내용을 다양화해야할 때를 위해 만들어졌다.
<br>
<br>

## 사용처
* 어떤 한 알고리즘을 이루는 부분 중 변하지 않는 부분을 한 번 정의해 놓고 다양해질 수 있는 부분은 서브 클래스에서 정의할 수 있도록 남겨두고자 할 때
* 서브클래스 사이의 공통적인 행동을 추출하여 공통 클래스에 몰아둠으로써 코드 중복을 피하고 싶을 때
* 서브클래스의 확장을 제어하고자 할 때
<br>
<br>

## 구성
* AbstractClass:
    * 서브클래스들이 재정의를 통해 구현해야하는 알고리즘 처리 단계 내의 기본 연산 정의
    * 알고리즘의 뼈대를 정의하는 템플릿 메서드 구현
* ConcreteClass:
    * 서브클래스마다 달라진 알고리즘 처리 단계를 수행하기 위한 기본 연산 구현
* hook 연산:
    * 필요하다면 서브클래스에서 확장할 수 있는 기본 행동을 제공하는 연산.
    * 확장용 연산
<br>
<br>

## 구현
#include <iostream>
using namespace std;

// View 클래스 정의
class View {
public:
    // 템플릿 메서드: 그림 그리기
    void Display() {
        // 포커스 설정
        SetFocus();

        // 실제적인 그리기 구현
        DoDisplay();

        // 포커스 해제
        ResetFocus();
    }

protected:
    // 추상 메서드: 실제적인 그리기
    virtual void DoDisplay() = 0;

    // 훅 메서드: 포커스 설정
    virtual void SetFocus() {
        cout << "Setting focus...\n";
    }

    // 훅 메서드: 포커스 해제
    virtual void ResetFocus() {
        cout << "Resetting focus...\n";
    }
};

// 서브 클래스 1: 사각형 그리기
class RectangleView : public View {
protected:
    void DoDisplay() override {
        cout << "Drawing a rectangle...\n";
    }
};

// 서브 클래스 2: 원 그리기
class CircleView : public View {
protected:
    void DoDisplay() override {
        cout << "Drawing a circle...\n";
    }
};

int main() {
    RectangleView rectangle;
    CircleView circle;

    rectangle.Display(); // 사각형 그리기
    circle.Display();    // 원 그리기

    return 0;
}

## 연관된 패턴
1. FactoryMethod