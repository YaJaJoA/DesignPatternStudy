#include <string>

enum SHAPE { square, circle, triangle };

class Box {
 public:
  Box(int color);

  void setColor(int color);

 private:
};

class Toy {
 public:
  Toy();

  void setShape(SHAPE);
};

class Wrapping {
 public:
  Wrapping();

  void setPattern(SHAPE);
};

class Package {
 public:
  Package();

  void foldPackage();
};

class PackageMachine {
 public:
  Package* makePackage();

  virtual Package* Packaging() const {
    return new Package();
  }  // 기본 형태 지정
  virtual Toy* PutInToy() const { return new Toy(); }
  virtual Box* Boxing(int color) const { return new Box(color); }
  virtual Wrapping* WrappingBox() const { return new Wrapping(); }
};

// PackageMachine 상속
class DottedPackageMachine : public PackageMachine {
 public:
  DottedPackage();  // 점박이 상자 생성

  virtual Package* Packaging() const {
    return new DottedPackage();
  }  //  점박이 상자 포장
  virtual Toy* PutInToy() const {
    return new DottedToy();
  }  // 점박이 장난감 상자에 넣기  상속받은 애 형태 변환
  virtual Box* Boxing(int color) const { return new DottedBox(color); }
  virtual Wrapping* WrappingBox() const { return new DottedWrapping(); }
};

Package* PackageMachine::makePackage() {
  Toy* toyA = PutInToy();
  Box* boxA = Boxing(000000);
  Wrapping* wrapA = WrappingBox();

  wrapA->setPattern(square);

  Package* packageA = Packaging();
}