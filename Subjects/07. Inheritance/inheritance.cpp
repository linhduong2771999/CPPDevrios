#include <iostream>
#include <string>

using namespace std;


/*
    --------
    - Terminology
    - + Inheritance:
    -   + Process of creating new classes from existing classes
    -   + Reuse mechanism
    - + Single Inheritance
    -   + A new class is created from another 'single' class
    - + Multiple Inheritance
    -   + A new class is created from two or more other classes
    - + Base class (Parent class, super class): Class being extened or inherited from 
    - + Derived class (child class, sub class): Class being created from the Base Class
    -
    - + "Is-A" Relationship
    - + Generalization: Combining similar classes from existing classes, more general class based
    -on common attributes
    - + Specialization: Creating new classes from existing classes providing more specialized or 
    -operations
    --------

    --------
    - Inheritance & Composition
    - + Public Inheritance
    -   + "Is-A" relationship
    -       - Employee "is-a" Person
    -       - Checking Account "is-a" Account
    - + Composition
    -   + "Has-A" relationship
    -       - Person "has-a" Account
    -       - Player "has-a" Special Attack
    --------

    --------
    - Public, Private & Protected
    - + Protected:
    -   - Attributes can be accessed by the Base class itself
    -   - Attributes can be accessed by the Derived class
    -   - Attributes cannot be accessed by the objects created from Base or Derived class
    -
    --------

    --------
    - Constructor & Destructor
    - + Constructor
    -   - When a derived object created, the "base class" constructor executed first, then
    -the "derived class" constructor executed after.
    -   - Base class constructors are always called before the derived class constructor.
    -   - If no explicit call to a base class constructor via the explicitly via the member
    -initialization list in the derived class constructor, the default constructor of the
    -base class is called.
    -   - To call a specific constructor of the base class, you must explicitly invoke it 
    -in the derived class's initialization list.
    - + Destructor
    -   - The destructor of "derived class" invokes, then "base class" destructor executed.
    -
    - + A Derived Class not inherited:
    -   - Base Class Constructor
    -   - Base Class Destructor
    -   - Base Class overloaded assignment operator
    -   - Base Class friend functions
    --------
    
    --------
    - Copy, Move Constructor, Operator=
    -
    -
    --------

    --------
    - Name Hiding Confusion
    - + If the derived class declares a member attribute with the same name as a base class 
    -attribute, the derived class’s member will hide the base class’s member when accessed 
    -through a derived object.
    - + You need to explicitly use scope resolution (e.g., BaseClass::attribute) to access 
    -the base class attribute.
    -
    --------

    --------
    - Redefining Base class methods
    -
    --------

    --------
    - Multiple Inheritance
    -
    --------
*/

class Player{
    private:
        string name;
    protected:
        int health;

    public: 
        Player() : name{"Unknown"}, health{0} {
            cout << "Base Default Constructor" << endl;
        }
        Player(string name, int health)
        : name{name}, health{health}{
            cout << "Base two-arg Constructor" << endl;
        }
        Player(const Player &source): name {source.name}, health{source.health} {
            cout << "Base Copy Constructor" << endl;
        }
        Player &operator=(const Player &rhs){
            if (this != &rhs)
            {
                this->name = rhs.name;
                this->health = rhs.health;
            }
            return *this;
        }
        void display_info(){
            cout << "Base: "<< "name: " << name << "|" << "health: " << health << endl;
        }
};

class Sub_Player: public Player {
    private:
        int level;
    public:
        int test = 1;
        Sub_Player() : Player {}, level {0}{
            cout << "Derived no-arg Constructor" << endl;
        }
        Sub_Player(int level) : Player {"Nguyen", 1000} , level{level}{
            cout << "Derived one-arg Constructor" << endl;
        }
        Sub_Player(const Sub_Player &source) : Player(source), level {source.level} {
            cout << "Derived Copy Constructor" << endl;
        }
        Sub_Player &operator=(const Sub_Player &rhs){
            if (this != &rhs)
            {
                Base:operator=(rhs); // copy the Base part
                this->level = rhs.level;
            }
            return *this;
        }

        void display_info(){
            cout << "Derived: "  << " | " << "level: " << level << endl;
        }
};


int main(){
    // Player Player_1 {"duong", 1000};
    Sub_Player Sub_player_1 {2};
    // Player_1.display_info();
    Sub_player_1.display_info();

    return 0;
}