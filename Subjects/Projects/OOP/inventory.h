#ifndef INVENTORY_H_
#define INVENTORY_H_
#include <iostream>
#include <string>
#include <vector>

#include "product.h"

using namespace std;

// const vector<Product> inven_data = {}

class Inventory{
    private:
        const string type_collection;
        vector <Product> inventory;
        vector <Product> shopping_cart;
    public: 
        Inventory(vector<Product> inven_data);
        // Inventory(const Inventory &source);
        // Inventory(Inventory &&source);
        void get_inventory(const string &type_collection) const;
        void update_shopping_cart(const string &buying_input, const int &quantity_input, const bool &actionType);
        void clear_inventory(const string &type_collection);
};

#endif