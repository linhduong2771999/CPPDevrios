#include <iostream>


using namespace std;

/*
    --------
    - Polymorphism
    - + Compile time, early biding, static binding (EX: overloaded function/operator)
    - + Runtime, late binding, dynamic binding (EX: function overriding)
    --------

    --------
    - Base class pointer, base reference
    -
    -
    --------


*/

class Base {
    public:
        virtual void display_info() const {
            cout << "hello from base" << endl;
        }
};

class Derived: public Base {
    public:
        virtual void display_info() const {
            cout << "hello from derived" << endl;
        }
};

void greetings(const Base &obj){
    obj.display_info();
}

int main(){
    Derived a;
    greetings(a);

    Base *ptr = new Derived();
    ptr->display_info();

    return 0;
}


/*
    why c++ has to separate compile and run time to executed
    if Account is a base, saving is a derived, and trust is a derived from saving, does trust has two base part

*/