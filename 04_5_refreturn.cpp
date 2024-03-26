#include <iostream>

/* function which returns refernce */

class A {
    private: 
    int x;

    public:
    //constructor
    A(int c) : x(c) { }

    int& AccessX() {
        return x;
    }
    int GetX() {
        return x;
    }
    void ShowX() {
        std::cout << x << std::endl;
    }
};

int main() {
    A a(5);
    a.ShowX();

    int& c = a.AccessX();
    c = 4;
    a.ShowX();

    int d = a.AccessX();
    d = 3;
    a.ShowX();

    int f = a.GetX();
    f = 1;
    a.ShowX();
}