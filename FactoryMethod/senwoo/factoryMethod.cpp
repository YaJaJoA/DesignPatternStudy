#include <iostream>
#include <string>
using namespace std;

class Component {
public:
    virtual void additionalConfig() = 0;
    virtual void render() = 0;
    virtual const string& getType() const = 0;  // 추가: 컴포넌트 타입 반환
    virtual ~Component() {}
};

class Button : public Component {
private:
    string type;  // 추가: 컴포넌트 타입 저장

public:
    Button(const string& compType) : type(compType) {}

    void additionalConfig() override {
        cout << "Button 추가 설정." << endl;
    }

    void render() override {
        cout << type << " Button 렌더링" << endl;
    }

    const string& getType() const override {
        return type;
    }
};

class CheckBox : public Component {
private:
    string type;  // 추가: 컴포넌트 타입 저장

public:
    CheckBox(const string& compType) : type(compType) {}

    void additionalConfig() override {
        cout << "CheckBox 추가 설정." << endl;
    }

    void render() override {
        cout << type << " CheckBox 렌더링" << endl;
    }

    const string& getType() const override {
        return type;
    }
};

class TextEdit : public Component {
private:
    string type;  // 추가: 컴포넌트 타입 저장

public:
    TextEdit(const string& compType) : type(compType) {}

    void additionalConfig() override {
        cout << "TextEdit additional configuration." << endl;
    }

    void render() override {
        cout << type << " TextEdit 렌더링" << endl;
    }

    const string& getType() const override {
        return type;
    }
};

class ComponentFactoryMethod {
public:
    virtual Component* createOperation(const string& type) = 0;
    virtual Component* createComponent(const string& type) = 0;
    virtual ~ComponentFactoryMethod() {}
};

class ButtonFactory : public ComponentFactoryMethod {
public:
    Component* createOperation(const string& type) override {
        Component* button = createComponent(type);
        button->additionalConfig();
        return button;
    }

    Component* createComponent(const string& type) override {
        Component* button = nullptr;

        if (type == "window") {
            button = new Button(type);
        } else if (type == "mac") {
            button = new Button(type); // Replace with MacButton if available
        }

        return button;
    }
};

class CheckBoxFactory : public ComponentFactoryMethod {
public:
    Component* createOperation(const string& type) override {
        Component* checkbox = createComponent(type);
        checkbox->additionalConfig();
        return checkbox;
    }

    Component* createComponent(const string& type) override {
        Component* checkbox = nullptr;

        if (type == "window") {
            checkbox = new CheckBox(type);
        } else if (type == "mac") {
            checkbox = new CheckBox(type); // Replace with MacCheckBox if available
        }

        return checkbox;
    }
};

class TextEditFactory : public ComponentFactoryMethod {
public:
    Component* createOperation(const string& type) override {
        Component* txtedit = createComponent(type);
        txtedit->additionalConfig();
        return txtedit;
    }

    Component* createComponent(const string& type) override {
        Component* txtedit = nullptr;

        if (type == "window") {
            txtedit = new TextEdit(type);
        } else if (type == "mac") {
            txtedit = new TextEdit(type); // Replace with MacTextEdit if available
        }

        return txtedit;
    }
};

int main() {
    ComponentFactoryMethod* factory = nullptr;
    Component* comp = nullptr;

    // 윈도우 버튼 생성
    factory = new ButtonFactory();
    comp = factory->createOperation("window");
    if (dynamic_cast<Button*>(comp)) {
        comp->render();
        delete comp;
    }

    // 맥 버튼 생성
    comp = factory->createOperation("mac");
    if (dynamic_cast<Button*>(comp)) {
        comp->render();
        delete comp;
    }

    // 윈도우 체크 박스 생성
    factory = new CheckBoxFactory();
    comp = factory->createOperation("window");
    if (dynamic_cast<CheckBox*>(comp)) {
        comp->render();
        delete comp;
    }

    // 맥 체크 박스 생성
    comp = factory->createOperation("mac");
    if (dynamic_cast<CheckBox*>(comp)) {
        comp->render();
        delete comp;
    }

    // 나머지 코드와 객체들 삭제 부분은 동일합니다.
    delete factory;

    return 0;
}
