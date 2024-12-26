#include "inventory.h"

Inventory::Inventory(string type_collection)
: type_collection {type_collection}, inventory {inven_data} {
    cout << "Inventory Constructor" << endl;
}

void Inventory::get_inventory(const string &type_collection){
    if (type_collection == "user")
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
    } else if (type_collection == "admin"){
        if (inventory.size() <= 0)
        {
            display_text("- Our inventory is currently empty. Please comback later.", true);
        } else {
            for (size_t i = 0; i < inventory.size(); i++)
            {
                cout << "-------------------------" << endl;
                cout << "- name: " << inventory.at(i).name 
                << "(" << "stock: " << inventory.at(i).quantity << "), "
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
} 

void Inventory::update_shopping_cart(const string &buying_input, const int &quantity_input, const bool &actionType){
    // true indicates adding, false indicates deleting
    bool isFound = false;
    for (size_t i = 0; i < inventory.size(); i++)
    {
        if (buying_input == inventory.at(i).name || buying_input == inventory.at(i).serial_number)
        {
            if (actionType)
            {   
                // handle the quantity
                
                if (inventory.at(i).quantity == 0)
                {
                    display_text("# The product is out of stock", true);
                } else if (quantity_input < inventory.at(i).quantity)
                {
                    inventory.at(i).quantity -= quantity_input; 
                } else {
                    display_text("# The quantity in stock is not enough", true);
                }   
                

                shopping_cart.push_back(inventory.at(i));

            } else {
                shopping_cart.erase(shopping_cart.begin() + i);
            }
            isFound = true;
        }
    }
    if (!isFound)
    {
        display_text("# Invalid product name or serial number.", true);
    }
    
}