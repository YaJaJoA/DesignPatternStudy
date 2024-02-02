#include <iostream>
using namespace std;

// 프록시를 사용하여 이미지를 로드하는 간단한 예제
// 가상 프록시에서 공통적으로 사용될 인터페이스
class Image {
public:
    virtual void display() = 0;
};

// 실제 이미지를 나타내는 클래스
class RealImage : public Image {
private:
    string filename;

public:
    RealImage(const string& file) : filename(file) {
        loadFromDisk();
    }

    void display() {
        cout << "Displaying image: " << filename << endl;
    }

private:
    void loadFromDisk() {
        cout << "Loading image from disk: " << filename << endl;
    }
};

// 가상 프록시 클래스
class ProxyImage : public Image {
private:
    RealImage* realImage;
    string filename;

public:
    ProxyImage(const string& file) : filename(file), realImage(nullptr) {}

    void display() override {
        if (realImage == nullptr) {
            realImage = new RealImage(filename);
        }
        realImage->display();
    }
};

int main() {
    // 클라이언트는 가상 프록시를 통해 이미지를 로드하고 표시
    Image* image1 = new ProxyImage("image1.jpg");
    image1->display();  // 이미지를 처음 로드할 때, 실제 이미지를 로드하고 표시

    cout << "------------------------" << endl;

    // 이미지를 두 번째로 로드할 때는 이미 로드된 이미지를 다시 사용
    Image* image2 = new ProxyImage("image2.jpg");
    image2->display();

    delete image1;
    delete image2;

    return 0;
}