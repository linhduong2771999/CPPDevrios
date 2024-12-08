#include "inventory.h"

Inventory::Inventory(string type_collection)
: type_collection {type_collection} {
    cout << "Inventory Constructor" << endl;
}