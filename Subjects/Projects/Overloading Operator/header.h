#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
#include <cstring>

using namespace std;

class Champion{
    private:
        char *name;
        int health;
        int level;

    public:
    Champion(const char *name = nullptr, int health = 0, int level = 0);
    Champion(const Champion &source);
    Champion &operator=(const Champion &rhs); // p1 = p2
    // void operator=(const Champion &rhs); // p1 = p2


    Champion(Champion &&source);
    Champion &operator=(Champion &&source); // p1 = p2

    ~Champion();
    void display_info();

};


#endif