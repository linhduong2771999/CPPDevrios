#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

class Champion{
    private:
        char *name;
        double health;
        int level;

    public:
    Champion(const char *name = nullptr, double health = 0, int level = 0);
    Champion(const Champion &source);
    Champion &operator=(const Champion &rhs); // p1 = p2
    Champion(Champion &&source);
    // Champion &operator=(Champion &&source); // p1 = p2

    void operator-();
    bool operator==(const Champion &rhs) const;
    bool operator!=(const Champion &rhs) const;
    bool operator>(const Champion &rhs) const;
    bool operator<(const Champion &rhs) const;
    Champion operator+(const Champion &rhs) const;
    void operator+=(const Champion &rhs);
    Champion operator*(const Champion &rhs) const;
    Champion &operator++();
    Champion operator++(int);
    Champion &operator--();
    Champion operator--(int);

    friend ostream &operator<<(ostream &os,const Champion &lhs);
    friend istream &operator>>(istream &is, Champion &lhs);
    ~Champion();
    void display_info() const;

};


#endif