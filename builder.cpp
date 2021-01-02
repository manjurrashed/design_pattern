//
//  main.cpp
//  Design_pattern_002
//
//  Created by Aarisha Zahra Khan on 2021-01-01.
//

#include <iostream>
using namespace std;

class Builder {
public:
    virtual void buildHeader() = 0;
    virtual void buildBody() = 0;
    virtual string getResult() = 0;
    virtual ~Builder() {}
};
class RedConcreateBuild : public Builder {
    string data;
public:
    RedConcreateBuild () { data = "Red"; }
    void buildHeader() { data += "-Header"; }
    void buildBody() { data += "-Body"; }
    string getResult() { return data + "-Table"; }
};
class BlueConcreateBuild : public Builder {
    string data;
public:
    BlueConcreateBuild () { data = "Blue"; }
    void buildHeader() { data += "-Header"; }
    void buildBody() { data += "-Body"; }
    string getResult() { return data + "-Table"; }
};
class Director {
    Builder *builder;
public:
    Director(Builder *b) { builder = b; }
    void ConstructTable(Builder *b = nullptr) {
        if (b)
            builder = b;
        builder->buildHeader();
        builder->buildBody();
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Builder Pattern!\n" << endl;

    RedConcreateBuild redBuilder;
    BlueConcreateBuild blueBuilder;
    
    cout << redBuilder.getResult() << endl;
    cout << blueBuilder.getResult() << endl;
    
    Director director(&redBuilder);
    director.ConstructTable();
    
    director.ConstructTable(&blueBuilder);
    
    cout << redBuilder.getResult() << endl;
    cout << blueBuilder.getResult() << endl;
    return 0;
}
