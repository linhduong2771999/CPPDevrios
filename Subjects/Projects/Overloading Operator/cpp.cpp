#include "header.h"


Champion::Champion(const char *name_val, int health, int level)
:name {nullptr}, health {health}, level {level} {
    if (name_val == nullptr)
    {
        name = new char[1];
        *name = '\0';
    } else {
        this->name = new char[strlen(name_val) + 1];
        strcpy(this->name, name_val);
    }
}

Champion::Champion(const Champion &source)
: name {nullptr}, health {source.health}, level {source.level} {
    this->name = new char[strlen(source.name) + 1];
    strcpy(this->name, source.name);
}

Champion &Champion::operator=(const Champion &rhs){
    if (this->name == rhs.name && health == rhs.health && level == rhs.level)
    {
        return *this;
    }
    
    delete [] this->name;
    this->health = rhs.health;
    this->level = rhs.level;
    this->name = new char[strlen(rhs.name) + 1];
    strcpy(this->name, rhs.name);
    return  *this;

}

void Champion::display_info(){
    cout << "Name: " << name << " " 
    << "Health: " << health << " "
    << "Level: " << level << endl; 
}

Champion::~Champion(){
    delete [] name;
}

