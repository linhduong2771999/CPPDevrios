#ifndef PRODUCT_H_
#define PRODUCT_H_
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product{
    public:
        string name;
        string description;
        int serial_number;
        int quantity;
        double price;
        string expired_date;

    public:

    // Default Constructor
    Product(
        string name = "Unknown",
        string description = "Empty",
        int serial_number = 0,
        int quantity = 0,
        double price = 0,
        string expired_date = "None" 
    );
};

#endif