#include <iostream>
#include <vector>

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

    --------
    - Virtual Function
    - + If a function is virtual, all matching overrides in derived classes are implicitly virtual.
    - + Never call virtual functions from constructors or destructors. If you were to call a virtual 
    -function from the Base constructor, and Derived portion of the class hadn’t even been created yet,
    -
    --------

    --------
    - Virtual Destructor
    - + When a base class pointer is used to delete a derived class object, the destructor of the 
    -derived class won't be called unless the base class destructor is marked as virtual.
    - + Base* obj = new Derived(); delete obj; // Only Base destructor will be called
    -
    - + Should we make all destructors virtual?: https://www.learncpp.com/cpp-tutorial/virtual-destructors-virtual-assignment-and-overriding-virtualization/
    --------

    --------
    - Override specifier
    - + Override ensures that the function is virtual and is overriding a virtual function from a 
    -base class
    - + Provides compile-time safety against mismatched signatures or missing virtual in the base 
    -class.
    - + Use for avoiding making mistakes when overiding function
    -
    - + Indicates that a member function is intended to be overridden by derived classes.
    - + Allows runtime polymorphism, enabling derived class functions to be called through base 
    -class pointers or references.
    --------

    --------
    - Final specifier
    - + Class level: If you do not intend your class to be inherited from, mark your class as final.  
    -This will prevent other classes from inheriting from it in the first place, without imposing 
    -any other use restrictions on the class itself.
    - + Methods & functions level: Prevent futher overriding on the Derived class
    - 
    --------

    --------
    - Pure Virtual Functions & Abstract Classes
    - + Abstract Class:
    -   - Cannot instantiate objects
    -   - These classes are used as base classes in inheritance 
    - + Concrete Class:
    -   - Can instantiate objects
    -
    - + Pure Virtual Functions:
    -   - Is a virtual function thats used to make a class abstract
    - 
    --------

    --------
    - Abstract Classes as Interface
    - Interface: An interface class is a class that has no member variables, and where all of the 
    -functions are pure virtual
    - 
    --------
*/

class Base {
    public:
        virtual void display_info() const {
            cout << "hello from base" << endl;
        }
        virtual void say_hello() const{
            cout << "say hello from base" << endl;
        }
        virtual ~Base(){
            cout << "Base Destructor" << endl;
        }
};

class Derived: public Base {
    public:
        virtual void display_info() const {
            cout << "hello from derived" << endl;
        }
         void say_hello() const override{
            cout << "say hello from derived" << endl;
        }
        virtual ~Derived(){
            cout << "Derived Destructor" << endl;
        }
};

void greetings(const Base &obj){
    // obj.display_info();
    obj.say_hello();
}

class Shape{
    protected:

    public:
        virtual void draw() = 0;
        virtual void rotate() = 0;
        ~Shape(){};
};

class Open_Shape: public Shape {
    protected:

    public:
        ~Open_Shape(){};
};

class Close_Shape: public Shape{
    protected:

    public:
        ~Close_Shape(){};
};

class Line: public Open_Shape {
    protected:
    public:
        virtual void draw() override {
            cout << "Draw line" << endl;
        }
        virtual void rotate() override {
            cout << "Rotate line" << endl;
        }
        ~Line(){};
};

class Circle: public Close_Shape {
    protected:
    public:
        virtual void draw() override {
            cout << "Draw Circle" << endl;
        }
        virtual void rotate() override{
            cout << "Rotate Circle" << endl;
        }
        ~Circle(){};
};



int main(){
    // Derived a;
    // greetings(a);

    // Base *ptr = new Derived();
    // // ptr->display_info();
    // // delete ptr;

    // Derived b;
    // Base &c = b;
    // c.say_hello();

    // Pure virtual functions
    Shape *a = new Circle();
    Shape *b = new Circle();
    Shape *c = new Line();
    Shape *d = new Line();

    vector <Shape *> vector_ptr = {a, b, c, d};
    for (auto ptr : vector_ptr)
    {
        ptr->draw();
        ptr->rotate();

    }


    delete a;

    return 0;
}

