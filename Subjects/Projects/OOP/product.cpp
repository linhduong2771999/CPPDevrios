#include "product.h"

Product::Product(
    string name, 
    string description, 
    string serial_number, 
    int quantity,
    double price,
    string expired_date
)
: name {name},
 description {description},
 serial_number {serial_number},
 quantity {quantity},
 price {price},
 expired_date {expired_date}
{  } 