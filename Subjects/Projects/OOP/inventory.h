#ifndef INVENTORY_H_
#define INVENTORY_H_
#include <iostream>
#include <string>
#include <vector>

#include "product.h"

using namespace std;

class Inventory{
    private:
        vector <Product> inventory;


    public:
    void display(){
        cout << "hello" << endl;
        // for (size_t i = 0; i < inventory.size(); i++)
        // {
        //     cout << inventory.at(i).name << endl;
        //     cout << inventory.at(i).description << endl;
        //     cout << inventory.at(i).serial_number << endl;
        //     cout << inventory.at(i).price << endl;
        //     cout << inventory.at(i).quantity << endl;
        //     cout << inventory.at(i).expired_date << endl;
        // }
        
    }

};

#endif