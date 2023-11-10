#include <string>
#include <iostream> 
using namespace std;

//전방 선언
class Button;
class CheckBox;
class Header;

// Abstract Factory
// 추상 메소드를 호출하는 추상클래스(혹은 추상 메소드 뿐이므로 인터페이스)이자
class ComponentFactory {
    public:
        virtual Button* createBtn(string text);
        virtual CheckBox* createCheckBox(bool checked);
        virtual Header* createHeader(string font);
};
//Abstract Product - 추상 팩토리에서 만들어내는 것으로, 구체 팩토리에서 각각 다르게 구현되는 요소(product?)들
class Button {
    public:
        Button(string text) {
            this->btnText = text;
        };
        virtual void render();
        void clickEvent() {
            cout << btnText << "버튼을 클릭했습니다." << endl;
        }
    protected:
        string btnText = "";
};

class CheckBox {
    public:
        CheckBox(bool checked){
            this->isChecked = checked;
            render(); // 체크가 변경되면 재렌더링 해야하므로 렌더 메소드 호출
        };
        virtual void render();
    protected:
        bool isChecked = false;
};

class Header {
    public:
        Header(string font){
            this->titleFont = font;
        };
        void setFont(string font){
            this->titleFont = font;
            render(); // 체크가 변경되면 재렌더링 해야하므로 렌더 메소드 호출
        };
        virtual void render();
    protected:
        string titleFont;
};


//concrete factory(구체 팩토리)
class ChromeFactory : public ComponentFactory {
    public:
        virtual Button* createBtn(string text){
            return new ChromeButton(text);
        };
        virtual CheckBox* createCheckBox(bool checked){
            return new ChromeCheckBox(checked);
        };
        virtual Header* createHeader(string font){
            return new ChromeHeader(font);
        };
};

class IEFactory : public ComponentFactory{
    public:
        virtual Button* createBtn(string text){
            return new IEButton(text);
        };
        virtual CheckBox* createCheckBox(bool checked){
            return new IECheckBox(checked);
        };
        virtual Header* createHeader(string font){
            return new IEHeader(font);
        };
};

//concrete product
// Button
class ChromeButton : public Button{
    public:
        ChromeButton(string text);
        virtual void render() {
            cout << "Chrome 브라우저 렌더링 API를 통해 " << this->btnText << "버튼을 렌더링합니다." << endl;
        };
};
class IEButton : public Button{
    public:
        IEButton(string text);
        virtual void render() {
            cout << "Internet Exploer 브라우저 렌더링 API를 통해 " << this->btnText << "버튼을 렌더링합니다." << endl;
        };
};
// CheckBox
class ChromeCheckBox : public CheckBox {
    public:
        ChromeCheckBox(bool checked);
        virtual void render() {
            cout << "Chrome 브라우저 렌더링 API를 통해 " << (this->isChecked ? "체크된" : "체크되지 않은") << "체크박스를 렌더링합니다." << endl;
        }
};
class IECheckBox : public CheckBox {
    public:
        IECheckBox(bool checked);
        virtual void render() {
            cout << "Internet Exploer 브라우저 렌더링 API를 통해 " << (this->isChecked ? "체크된" : "체크되지 않은") << "체크박스를 렌더링합니다." << endl;
        }
};
// Header
class ChromeHeader : public Header {
    public:
        ChromeHeader(string font);
        virtual void render() {
            cout << "Chrome 브라우저 렌더링 API를 통해" << this->titleFont << "폰트의 헤더를 렌더링 합니다." << endl;
        }
};
class IEHeader : public Header {
    public:
        IEHeader(string font);
        virtual void render() {
            cout << "Internet Exploer 브라우저 렌더링 API를 통해" << this->titleFont << "폰트의 헤더를 렌더링 합니다." << endl;
        }
};

int main() {
    ChromeFactory* factory = new ChromeFactory();
    
    Button* btn = factory->createBtn("확인");
    CheckBox* checkbox = factory->createCheckBox(false);
    Header* header = factory->createHeader("궁서체");

    btn->render();
    checkbox->render();
    header->render(); 

    return 0;
}