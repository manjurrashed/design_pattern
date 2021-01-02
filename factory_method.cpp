//
//  main.cpp
//  Design_pattern_002
//
//  Created by Aarisha Zahra Khan on 2021-01-01.
//

#include <iostream>
using namespace std;
class Document {
public:
    virtual void showInfo() = 0;
    virtual ~Document() {}
};
class DrawDocument : public Document {
public:
    void showInfo() { cout << "Draw Document\n"; }
};
class TextDocument : public Document {
public:
    void showInfo() { cout << "Tex Document\n"; }
};

class Application {
public:
    virtual Document *CreateDocument() = 0;
    virtual ~Application() {}
};
class DrawApplication: public Application {
    Document *CreateDocument() { return new DrawDocument; }
};
class TextApplication: public Application {
    Document *CreateDocument() { return new TextDocument; }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Factory Method Pattern!\n" << endl;

    Application * app = new DrawApplication;
    Document *doc = app->CreateDocument();
    doc->showInfo();
    delete doc;
    delete app;
    
    app = new TextApplication;
    doc = app->CreateDocument();
    doc->showInfo();
    delete doc;
    delete app;
    
    return 0;
}
