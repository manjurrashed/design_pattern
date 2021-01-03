//
//  main.cpp
//  Design_pattern_002
//
//  Created by Manjur Khan on 2021-01-01.
//

#include <iostream>
using namespace std;

class Singleton {
    int m_value;
    static Singleton* s_instance;
    Singleton(int v = 0) {
        m_value = v;
    }
public:
    int get_value() {
        return m_value;
    }
    void set_value(int x) {
        m_value = x;
    }
    static Singleton *get_instance(){
        if (!s_instance) {
            s_instance = new Singleton;
        }
        return s_instance;
    }
};
Singleton* Singleton::s_instance = nullptr;

int main(int argc, const char * argv[]) {
    // insert code here...
    Singleton::get_instance()->set_value(19);
    std::cout << "Hello, World!\n" << Singleton::get_instance()->get_value() << endl;
    return 0;
}

