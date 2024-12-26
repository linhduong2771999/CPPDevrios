#ifndef INVENTORY_H_
#define INVENTORY_H_
#include <iostream>
#include <string>
#include <vector>

#include "product.h"
#include "common.h"

using namespace std;

class Inventory{
    private:
        const string type_collection;
        vector <Product> inventory;
        vector <Product> shopping_cart;
    public:
        Inventory(string type_collection = "Unknown");
        // Inventory(const Inventory &source);
        // Inventory(Inventory &&source);

    void get_inventory(const string &user, const string &admin){
        if (type_collection == user)
        {
            if (shopping_cart.size() <= 0)
            {
                display_text("- Your shopping cart is currently empty. Try to buy something.", true);
            } else {
                for (size_t i = 0; i < shopping_cart.size(); i++)
                {
                    cout << "- Your Shopping cart: " << endl;
                    cout << "-------------------------" << endl;
                }
            }
        } else if (type_collection == admin){
            if (inventory.size() <= 0)
            {
                display_text("- Our inventory is currently empty. Please comback later.", true);
            } else {
                for (size_t i = 0; i < inventory.size(); i++)
                {
                    cout << "-------------------------" << endl;
                    cout << "- name: " << inventory.at(i).name 
                    << "(" << "stock: " << inventory.at(i).quantity << "),"
                    << "price: $" << inventory.at(i).price << " || "
                    << "SN: " << inventory.at(i).serial_number << " - "
                    << "Expired: " << inventory.at(i).expired_date << endl;
                    cout << "- description: " << inventory.at(i).description << " " << endl;
                    cout << "-------------------------" << endl;
                }
            }
        } else {
            display_text("-> Invalid user or admin. Please try another login.", true);
        }
};

#endif