#include "inventory.h"
#include "common.h"

Inventory::Inventory(vector<Product> inven_data)
: inventory {inven_data} {
    cout << "Inventory Constructor" << endl;
}

void Inventory::get_inventory(const string &type_collection) const{
    if (type_collection == "user")
    {
        if (shopping_cart.size() <= 0)
        {
            display_text("- Your shopping cart is currently empty. Try to buy something.", true);
        } else {
            double total_price = 0;
            display_text("- Your Shopping cart", false);
            cout << "(" << shopping_cart.size() << ")" << ": ";
            for (size_t i = 0; i < shopping_cart.size(); i++)
            {
                cout << shopping_cart.at(i).name 
                << "(" << shopping_cart.at(i).quantity << "), "; 
                total_price += shopping_cart.at(i).price;
            }
            cout << " | " << "Total price: " << total_price << endl;
        }
    } else if (type_collection == "admin"){
        if (inventory.size() <= 0)
        {
            display_text("- Our inventory is currently empty. Please comeback later.", true);
        } else {
            display_text("- Shopping list: ", true);
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
    // the action type: true indicates adding, false indicates deleting
    bool isFound = false;
    Product temp_obj;

    for (size_t i = 0; i < inventory.size(); i++)
    {
        if (buying_input == inventory.at(i).name || buying_input == inventory.at(i).serial_number)
        {
            temp_obj.name = inventory.at(i).name;
            temp_obj.price = inventory.at(i).price*quantity_input;
            temp_obj.quantity = quantity_input;
            if (actionType)
            {   
                // handle the quantity in the inventory
                if (inventory.at(i).quantity == 0)
                {
                    display_text("# The product is out of stock", true);
                } else if (quantity_input <= inventory.at(i).quantity)
                {
                    inventory.at(i).quantity -= quantity_input; 
                    shopping_cart.push_back(temp_obj);
                } else {
                    display_text("# The quantity in stock is not enough", true);
                }   
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

void Inventory::clear_inventory(const string &type_collection){
    if (type_collection == "user")
    {   
        if (shopping_cart.size() <= 0)
        {
            display_text("- Your cart is currently empty. Please buy something.", true);
        } else {
         shopping_cart.clear();
        }
    } else if (type_collection == "admin") {
        if (inventory.size() <= 0)
        {
            display_text("- Our inventory is currently empty. Please comeback later.", true);
        } else {
            inventory.clear();
        }
    } else {
        display_text("-> Invalid user or admin. Please try another login.", true);
    }
    
}