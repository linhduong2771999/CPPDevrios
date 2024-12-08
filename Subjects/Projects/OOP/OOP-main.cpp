#include <iostream>

#include "common.h"
#include "inventory.h"

using namespace std;


int main(){
    int num = -1;
    home();
    while (num != 0)
    {   
        display_text("- Type here (0 for exit, 1 for home): ", false);
        cin >> num;  
        if (cin.fail()){
            clear_buffer();
            num = -1;
            display_text("Warning: Please type a valid number.", true);
        }
        switch (num){
        case 1:
            clear_buffer();
            cut_line();
            home();
            break;
        case 2:
            clear_buffer();
            cut_line();
            display_banner("Login");
            display_text("Login", true);
            break;
        case 3:
            clear_buffer();
            cut_line();
            display_banner("Inventory");
            display_text("Inventory", true);
            break;
        default:
            break;
        }
        
    }
    

    return 0;
}



/*
    interface & user input:
    0. display login for admin or customer
        + type only password to login
        + determine user or admin
    1. display option to choose inventory type 
        + input (user or admin): name of the type collection
        
    2. display the collection
        + input (admin): option want to modify
        + input (user): name of product want to buy
    inventory:
    attributes:
        + type of collection
        + collection
    method: 
        + display product
        + add product
        + update product
        + delete product
    
    product:
    attributes: 
        + name
        + description
        + quantity
        + serial number
        + price
        + expire date

*/