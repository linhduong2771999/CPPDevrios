#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
    --------
    - Classes and Objects
    - + Class: a detailed blueprint or pattern, it defines a data structure that includes properties (attributes) and behaviors (methods)
    - + Object: an instance, it represents a specific entity that has attributes and behaviors defined by its class.
    --------

    --------
    - Public vs Private 
    - + Makes fix bug more easier
    - + If one of your private attributes' value are changed accidentally, the only place can change that private value is 
    - its methods
    --------
    
    --------
    - Declaration (specification)  vs Implementation method
    - + Specification is placed in header file .h
    - + Declaration is placed in .cpp file
    -
    - + If you include or import header .h file multiple in many different .cpp files. The compiler will generate a duplicate 
    - declarations method errors.
    - + To solve duplicate declarations problem, use "include guard" or "#pragma once".
    --------
    
    --------
    - Constructor & Destructor
    - + If you provide no constructor and destructor, C++ will automatically provide with an empty one.
    - + If you create a object on the heap (dynamic allocation memory), you must use the destructor in order to delete memory
    - the object on the heap.
    --------

    --------
    - Default Constructor
    - + In default, compiler will generate Constructor with no initialization information.
    - + Once you create a Constructor for an object, the default Constructor will not be called automatically by the compiler
    --------

    --------
    - Constructor Initialization List
    - + Before the Constructor is called, all attributes of the Class Declaration will be initialized with value. As a result,
    -the action of initialization of attributes in the Constructor is assignment.
    --------

    --------
    - Delegating Constructor
    --------

    --------
    - Default Constructor Parameters
    - + We can create on Constructor that does everything(Initialize value).
    --------    

    --------
    - Copy Constructor
    - - Compiler will generate Default Copy Constructor:
    -   + When pass by value
    -   + Returning an object from a function by value
    -   + Constructing an object based on another of the same class
    - + Always define a Copy Constructor on your own if you use raw pointer
    --------

    --------
    - Shallow Copy 
    - + When an object is copy, it is copy pointers point to the same address from the original object
    --------

    --------
    - Move Constructor
    - Vector<Move> vec; vec.push_back(Move{10});
    - The function "push back" above is pushing an unnamed temporary object create by the compiler in the memory,
    -the compiler will call the "copy Constructor" to do it. But instead of making a copy, we will use move constructor
    -to do this (much more efficient in performance). 
    - + It means that we move the data from the original object to the new object instead of copying it.
    -
    - EX: total = 100 + 200
    - 300 will be stored in unnamed temporary object value (after that 300 is stored in total)
    --------

    --------
    - Const With Class
    --------

    --------
    - Static Class Member
    - + A data member that belongs to the class, not the objects when it creates.
    - + Store class-wide information
    - + Cannot initialized static variable in Class Declaration
    --------

    --------
    - Struct & Class
    - + Member Attributes of "struct" is public by default while "class" is private
    - + Do not declare methods in "Struct" (since it is only use for passive data)
    - + Struct use for contain passive data(like a container)
    - + Class is use for active data, complex behavior,
    --------

    --------
    - Friend
    - + Is an another function or class that has access to private class member
    -   - function: can be standalone or is a member methods of other class
    -   - class: The entire class have access to the private attributes of the class granting friendship
    - + Friendship is not symmetric (must be explicitly granted)
    -   - If A is a friend of B
    -   - B is not a friend of A
    --------
*/

// Declaring class
class Person{
    // attributes
    private: 
    string name;
    int age;
    double height;
    int *ptr;
    static int num_person;

    public: 
    void add_name(string name_add);
    void display_name() const;
    void display_ptr() const;
    static void display_static();
    // Person();
    // Person(string name_add, int age);
    Person(string name_add = "None", int age = 0, double height = 0);

    // Copy Constructor
    Person(const Person &source);
    // Move Constructor
    Person(Person &&source) noexcept;
    ~Person();

};

int Person::num_person = 1;

void Person::add_name(string name_add){
    name = name_add;
}

void Person::display_name() const{
    cout << name << endl;
}

void Person::display_ptr() const{
    cout << *ptr << endl;
}

void Person::display_static(){
    cout << num_person << endl;
}

// Person::Person(): Person{"Nguyen Linh Duong", 25, 1.7} {
//     cout << "Default constructor" << endl;
// }
// Person::Person(string name_add, int age_add)
// : Person {name_add, age_add, 0} {
//     cout << "Constructor: " << name << " " << age << " " << height << endl;
// }
Person::Person(string name_add, int age_add, double height_add)
: name{name_add}, age{age_add}, height{height_add} {
    ptr = new int;
    *ptr = age_add;
    cout << "Constructor: " << name << " " << age << " " << height << endl;
}

// Copy Constructor
Person::Person(const Person &source)
: name{source.name}, age{source.age}, height{source.height}, ptr{source.ptr} {
    ptr = new int;
    *ptr = *source.ptr;
    num_person++;
    cout << "Copy Constructor: " << name << " " << age << " " << height << endl;
}

// Move Constructor
Person::Person(Person &&source) noexcept : name{source.name}, age{source.age}, height{source.height}, ptr{source.ptr} {
    source.ptr = nullptr;
    cout << "Move constructor of: " << name << endl;

}

Person::~Person(){
    delete ptr;
    num_person--;
    cout << "Destructor of: " << name << endl;
}

class Player{
    private:
        int health;

    public:
    Player(int health = 0);
    Player(const Player &source);
    Player(Player &&source);

    ~Player();
};

Player::Player(int health_val)
: health{health_val} {}

Player::Player(const Player &source)
: health {source.health} {
}

Player::Player(Player &&source)
: health {source.health} { source.health = 0; }

int main(){

    // Person duong;
    // duong.add_name("Nguyen linh duong");
    // duong.display_name();

    // Person dinh;
    // Person person_arr[] = {duong, dinh};
    // Person *duong_ptr = new Person();
    // delete duong_ptr;

    // Person linh("linh", 12);
    // Person khanh("khanh", 12, 1.75);
    // Person *nguyen_ptr = new Person("nguyen", 12);
    // delete nguyen_ptr;

    // Testing shallow copy constructor
    // Person nguyen("Nguyen Linh Duong", 25, 1.7);
    // nguyen.display_ptr();
    // Person dinh(nguyen);
    // nguyen.display_ptr();

    // Testing deep copy constructor
    // const Person nguyen("Nguyen Linh Duong", 25, 1.7);
    // Person dinh;
    // Person::display_static();

    Player nguyen(5);
    Player dinh(1);

    // dinh = nguyen;
    
    return 0;
}
