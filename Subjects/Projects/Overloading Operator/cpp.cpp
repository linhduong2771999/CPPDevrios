#include "header.h"

Champion::Champion(const char *name_val, double health, int level)
    : name{nullptr}, health{health}, level{level}
{
    if (name_val == nullptr)
    {
        name = new char[8];
        strcpy(this->name, "Unknown");
    }
    else
    {
        this->name = new char[strlen(name_val) + 1 + level];
        strcpy(this->name, name_val);
        this->name[0] = toupper(this->name[0]);
        switch (level)
        {
        case 1:
            strcat(this->name, "*");
            break;
        case 2:
            strcat(this->name, "**");
            break;
        case 3:
            strcat(this->name, "***");
            break;
        case 4:
            strcat(this->name, "{}");
            break;
        case 5:
            strcat(this->name, "[]");
            break;
        default:
            break;
        }
    }
    // cout << "Default Constructor" << endl;
}

Champion::Champion(const Champion &source)
    : name{nullptr}, health{source.health}, level{source.level}
{
    this->name = new char[strlen(source.name) + 1];
    strcpy(this->name, source.name);
    this->health = source.health;
    this->level = source.level;

    cout << "Copy Constructor" << endl;
}

Champion &Champion::operator=(const Champion &rhs)
{
    if (this->name == rhs.name && health == rhs.health && level == rhs.level)
    {
        return *this;
    }
    // Resize the character array
    char *temp = new char[strlen(this->name) + 1 + rhs.level]();
    // Remove special character
    for (size_t i = 0; i < strlen(this->name); i++)
    {
        if ((int(this->name[i]) >= 65 && int(this->name[i]) <= 90) || (int(this->name[i]) >= 97 && int(this->name[i]) <= 122))
        {
            temp[i] = this->name[i];
        }
    }
    this->health = rhs.health;
    this->level = rhs.level;
    switch (this->level)
        {
        case 1:
            strcat(temp, "*");
            break;
        case 2:
            strcat(temp, "**");
            break;
        case 3:
            strcat(temp, "***");
            break;
        case 4:
            strcat(temp, "{}");
            break;
        case 5:
            strcat(temp, "[]");
            break;
        default:
            break;
    }
    delete[] this->name;
    this->name = temp;
    temp = nullptr;

    // cout << "Copy Assignment" << endl;
    return *this;
}

Champion::Champion(Champion &&source)
    : name{source.name}, health{source.health}, level{source.level}
{
    source.name = nullptr;
    // cout << "Move Constructor" << endl;
}

// Champion &Champion::operator=(Champion &&rhs)
// {
//     if (this->name == rhs.name && this->health == rhs.health && this->level == rhs.level)
//     {
//         return *this;
//     }

//     // Resize the character array
//     char *temp = new char[strlen(this->name) + 1 + level];
//     strcpy(temp, this->name);
//     switch (level)
//         {
//         case 1:
//             strcat(temp, "*");
//             break;
//         case 2:
//             strcat(temp, "**");
//             break;
//         case 3:
//             strcat(temp, "***");
//             break;
//         case 4:
//             strcat(temp, "{}");
//             break;
//         case 5:
//             strcat(temp, "[]");
//             break;
//         default:
//             break;
//         }

//     this->health = rhs.health;
//     this->level = rhs.level;

//     // cout << "Move Assignment" << endl;
//     return *this;
// }

void Champion::operator-()
{
    if (this->level != 0)
    {
        // Resize the character array
        char *temp = new char[strlen(this->name) + 1 + this->level]();
        for (size_t i = 0; i < strlen(this->name); i++)
        {
            if ((int(this->name[i]) >= 65 && int(this->name[i]) <= 90) || (int(this->name[i]) >= 97 && int(this->name[i]) <= 122))
            {
                temp[i] = this->name[i];
            }
        }
        // Reduce the level to add the special character
        this->health = (this->health - 1000);
        this->level = (this->level - 1);
        switch (this->level)
        {
        case 1:
            strcat(temp, "*");
            break;
        case 2:
            strcat(temp, "**");
            break;
        case 3:
            strcat(temp, "***");
            break;
        case 4:
            strcat(temp, "{}");
            break;
        case 5:
            strcat(temp, "[]");
            break;
        default:
            break;
        }
        delete[] this->name;
        this->name = temp;
        temp = nullptr;
    }
}

bool Champion::operator==(const Champion &rhs) const
{
    if ((strcmp(this->name, rhs.name) == 0) &&
        (this->health == rhs.health) &&
        (this->level == rhs.level))
    {
        
        return true;
    }
    return false;
}

bool Champion::operator!=(const Champion &rhs) const
{
    if (*this == rhs)
    {
        return false;
    }
    return true;
}

bool Champion::operator>(const Champion &rhs) const {
    if (this->health > rhs.health ||
    this->level > rhs.level)
    {
        return true;
    }
    return false;
}

bool Champion::operator<(const Champion &rhs) const {
    if (*this > rhs)
    {
        return false;
    }
    return true;
}

Champion Champion::operator+(const Champion &rhs) const {
    Champion temp;
    if ((this->level + rhs.level) > 5)
    {
        temp.level = 5;
        temp.health = (this->health + rhs.health)/2;
    } else {
        temp.level = this->level + rhs.level;
        temp.health = this->health + rhs.health;
    }
    return temp;
}

void Champion::operator+=(const Champion &rhs) {
    *this = *this + rhs;
}

Champion &Champion::operator++(){
    if (this->level <= 5)
    {
         // Resize the character array
        char *temp = new char[strlen(this->name) + 1 + this->level]();
        for (size_t i = 0; i < strlen(this->name); i++)
        {
            if ((int(this->name[i]) >= 65 && int(this->name[i]) <= 90) || (int(this->name[i]) >= 97 && int(this->name[i]) <= 122))
            {
                temp[i] = this->name[i];
            }
        }
        // Upgrade the level to add the special character
        this->health = (this->health + 1000);
        this->level = (this->level + 1);
        switch (this->level)
        {
        case 1:
            strcat(temp, "*");
            break;
        case 2:
            strcat(temp, "**");
            break;
        case 3:
            strcat(temp, "***");
            break;
        case 4:
            strcat(temp, "{}");
            break;
        case 5:
            strcat(temp, "[]");
            break;
        default:
            break;
        }
        delete[] this->name;
        this->name = temp;
        temp = nullptr;

        return *this;
    }
    return *this;
}

Champion Champion::operator++(int){
    Champion temp_obj {*this};
    ++(*this);
    return temp_obj;
}

Champion &Champion::operator--(){
    if (this->level <= 5)
    {
         // Resize the character array
        char *temp = new char[strlen(this->name) + 1 + this->level]();
        for (size_t i = 0; i < strlen(this->name); i++)
        {
            if ((int(this->name[i]) >= 65 && int(this->name[i]) <= 90) || (int(this->name[i]) >= 97 && int(this->name[i]) <= 122))
            {
                temp[i] = this->name[i];
            }
        }
        // Upgrade the level to add the special character
        this->health = (this->health - 1000);
        this->level = (this->level - 1);
        switch (this->level)
        {
        case 1:
            strcat(temp, "*");
            break;
        case 2:
            strcat(temp, "**");
            break;
        case 3:
            strcat(temp, "***");
            break;
        case 4:
            strcat(temp, "{}");
            break;
        case 5:
            strcat(temp, "[]");
            break;
        default:
            break;
        }
        delete[] this->name;
        this->name = temp;
        temp = nullptr;

        return *this;
    }
    return *this;
}

Champion Champion::operator--(int){
    Champion temp_obj {*this};
    --(*this);
    return temp_obj;
}

void Champion::display_info() const
{
    cout << "Name: " << name << " "
         << "Health: " << health << " "
         << "Level: " << level << endl;
}

ostream &operator<<(ostream &os, const Champion &lhs){
    os << lhs.name << " " << lhs.health << " " << lhs.level;
    return os;
}

istream &operator>>(istream &is, Champion &lhs){
    char *temp = new char[100];
    int level = 0;
    double health = 0;
    is >> temp;
    is >> health;
    is >> level;
    delete [] lhs.name;
    lhs.name = temp;
    lhs.health = health;
    lhs.level = level;
    temp = nullptr;

    return is;
}


Champion::~Champion()
{
    delete[] name;
}
