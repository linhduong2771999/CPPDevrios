#include "header.h"


Champion::Champion(const char *name_val, double health, int level)
:name {nullptr}, health {health}, level {level} {
    if (name_val == nullptr)
    {
        name = new char[8];
        strcpy(this->name, "Unknown");
    } else {
        this->name = new char[strlen(name_val) + 1 + level];
        strcpy(this->name, name_val);
        strcat(this->name, "*");
        this->name[0] = toupper(this->name[0]);
    }
    // cout << "Default Constructor" << endl;
}

Champion::Champion(const Champion &source)
: name {nullptr}, health {source.health}, level {source.level} {
    this->name = new char[strlen(source.name) + 2];
    strcpy(this->name, source.name);
    strcat(this->name, "*");
    this->health = source.health;
    this->level = source.level;
    // cout << "Copy Constructor" << endl;
}

Champion &Champion::operator=(const Champion &rhs){
    if (this->name == rhs.name && health == rhs.health && level == rhs.level)
    {
        return *this;
    }
    
    this->health = rhs.health;
    this->level = rhs.level;
    // cout << "Copy Assignment" << endl;

    return  *this;

}

Champion::Champion(Champion &&source)
: name {source.name}, health {source.health}, level {source.level} {
    source.name = nullptr;
    // cout << "Move Constructor" << endl;
}

Champion &Champion::operator=(Champion &&rhs){

    if (this->name == rhs.name && health == rhs.health && level == rhs.level)
    {
        return *this;
    } 
    delete [] this->name;
    this->name = rhs.name;
    rhs.name = nullptr;
    // cout << "Move Assignment" << endl;
    return *this;
}

void Champion::operator-(){
    if (this->level != 0)
    {
        this->health = (this->health/2);
        this->level = (this->level - 1);
    }
}

void Champion::display_info(){
    cout << "Name: " << name << " " 
    << "Health: " << health << " "
    << "Level: " << level << endl; 
}

Champion::~Champion(){
    delete [] name;
}

