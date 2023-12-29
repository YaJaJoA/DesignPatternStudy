
# Builder
## 개요
복잡한 객체의 구조를 분리해 같은 생성 과정으로 다른 결과물들을 만들 수 있음.
<br><br>

## 동기
RTF 파일 리더는 RTF를 많은 텍스트 서식으로 변환을 해야 한다. 리더는 RTF 문서를 아스키 문자 또는 텍스트 위젯으로 변환한 뒤 원하는 서식으로 변환을 할 것이다. 문제는 문자 서식의 종류가 매우 많다는 것이다. 따라서 리더의 변환 추가가 쉬워야 한다.
<br><br>
## 사용처
<li> 복잡한 객체를 생성하기 위한 알고리즘이 객체를 구성하는 부분 및 구성 방식과 독립적이여야 할 때
<li> 생성 과정이 생성된 객체에 대한 다양한 형태를 혀용해야 할 때
<br><br>

## 구성
* 빌더: 제품 객체의 부품을 생성하는 추상 인터페이스를 특정함.
* 구상빌더
    * 빌더 인터페이스를 상속함으로써 제품의 부들을 생성하고 조립함.
    * 생성된 표현을 정의하고 추적함.
    * 제품을 받을 인터페이스 제공.
* 감독: 빌더 인터페이스를 사용해 객체 생성
* 제품
    * 생성 중인 복잡한 객체를 표현. 구상빌더는 제품의 내부 표현을 구축하고 제품 조립 프로세스를 정의함.
    * 구성 부품을 정의하는 클래스 포함, 최종 결과로 부품을 조립하는 인터페이스 포함.
<br><br>

## 동작 방식
1. 클라이언트가 감독 객체를 생성한 뒤 빌더 객체와 함께 구성함.
2. 감독은 빌더에게 제품의 부품들이 생성되어야 하는지 알려줌.
3. 빌더는 감독 객체의 요청에 따라 제품에 부품을 추가함.
4. 클라이언트는 빌더에게 완성된 제품을 받음.
<br><br>

## 장단점
* 제품 내부 표현을 다양하게 나타낼 수 있음.
* 코드에서 생성과 표현을 분리시킬 수 있음.
    * 복잡한 객체의 생성과 표현을 캡슐화시킴으로써 모듈화를 증진시킬 수 있음.
* 생성 과정에서 더 잘 컨트롤할 수 있게 됨.
<br><br>

## 관련 패턴
* Abstract Factory
* Composite