#include <iostream>
#include <string>
#include <vector>


#include "inventory.h"

using namespace std;


int main(){
    Inventory inven;
    cout << "hello" << endl;
    inven.display();

    return 0;
}



/*
    inventory:
    attributes:
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