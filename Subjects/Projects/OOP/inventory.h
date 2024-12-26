#ifndef INVENTORY_H_
#define INVENTORY_H_
#include <iostream>
#include <string>
#include <vector>

#include "product.h"
#include "common.h"

using namespace std;

const vector<Product> inven_data = {
    {"name", "des", "em", 1, 12, "1-11"},
    {"nam", "des", "em", 1, 12, "1-11"}
};
// const vector<Product> inven_data = {}

class Inventory{
    private:
        const string type_collection;
        vector <Product> inventory;
        vector <Product> shopping_cart;
    public:
        Inventory(string type_collection = "Unknown");
        // Inventory(const Inventory &source);
        // Inventory(Inventory &&source);
        void get_inventory(const string &type_collection);
        void update_shopping_cart(const string &buying_input, const int &quantity_input, const bool &actionType);
      
};

#endif