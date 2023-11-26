#include <string>

enum MATERIAL { metal, wood, paper, stone, clay };

class Box {
 private:
  MATERIAL material;

 public:
  virtual void setMaterial(MATERIAL){};
  virtual void fillInside(int num){};
  virtual void setPacking(int type){};
};

class BoxBuilder {
 private:
  Box box;

 public:
  virtual BoxBuilder setMaterial(MATERIAL mat) { box.setMaterial(mat); };
  virtual BoxBuilder fillInside(int num) { box.fillInside(num); };
  virtual BoxBuilder setPacking(int type) { box.setPacking(type); };

  virtual Box post() { return box; };
};

Box boxA = BoxBuilder().setMaterial(metal).setPacking(5).fillInside(2).post();
Box boxB = BoxBuilder().setMaterial(wood).setPacking(1).fillInside(1).post();
Box boxC = BoxBuilder().setMaterial(paper).setPacking(2).fillInside(50).post();
Box boxD = BoxBuilder().setMaterial(stone).setPacking(4).fillInside(5).post();
Box boxE = BoxBuilder().setMaterial(clay).setPacking(3).fillInside(5).post();