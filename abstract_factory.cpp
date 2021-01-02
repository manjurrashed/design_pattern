//
//  main.cpp
//  Design_pattern_002
//
//  Created by Aarisha Zahra Khan on 2021-01-01.
//

#include <iostream>
using namespace std;

#define MAC 0

class WidgetFactory {
public:
    virtual string CreateScrollBar() = 0;
    virtual string CreateButton() = 0;
    virtual ~WidgetFactory() {}
};
class MacWidgetFactory : public WidgetFactory {
    string CreateScrollBar() {
        return "Mac Scrollball";
    }
    string CreateButton() {
        return "Mac Button";
    }
};
class WindowsWidgetFactory : public WidgetFactory {
    string CreateScrollBar() {
        return "Windows Scrollball";
    }
    string CreateButton() {
        return "Windows Button";
    }
};

class Client {
    WidgetFactory *widget;
public:
    Client() {
#if MAC
        widget = new MacWidgetFactory();
#else
        widget = new WindowsWidgetFactory();
#endif
    }
    string CreateScrollBar() {
        return widget->CreateScrollBar();
    }
    
    string CreateButton() {
        return widget->CreateButton();
    }
    
    ~Client() {
        delete widget;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Abstract Factory Pattern!\n" << endl;
    Client client;
    cout << client.CreateButton() << endl;
    cout << client.CreateScrollBar() << endl;
    return 0;
}

