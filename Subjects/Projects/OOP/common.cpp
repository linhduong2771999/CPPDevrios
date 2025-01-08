#include "common.h"
#include "inventory.h"

// Helpers
bool isValidInteger(const string &str)
{
    if (str.length() <= 0)
    {
        return false;
    }
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isdigit(str.at(i)))
        {
            return false;
        }
    }
    return true;
}
// For displaying interface
void home()
{
    display_banner("Home");
    display_text("1. Home", true);
    display_text("2. Shopping as guest", true);
    display_text("3. Login", true);
}

void guest_shopping(Inventory &inven)
{
    string buying_input;
    string quantity_input;
    string credit_input;
    int quantity_value = 0;
    const string credit_card = "277NLD99";

    display_banner("Shopping list");
    inven.get_inventory("admin");

    while (buying_input != "e" && buying_input != "b")
    {
        display_text("-> What you want to buy(name or serial number, press b for payment, e to exit): ", false);
        getline(cin, buying_input);
        if (buying_input != "e" && buying_input != "b")
        {
            bool isValidQuantity = false;
            while (!isValidQuantity)
            {
                display_text("-> Quantity: ", false);
                getline(cin, quantity_input);
                if (isValidInteger(quantity_input))
                {
                    quantity_value = stoi(quantity_input);
                    isValidQuantity = true;
                }
            }
            inven.update_shopping_cart(buying_input, quantity_value, true);
            inven.get_inventory("user");
        }
        
    }

    if (buying_input == "b")
    {
        bool isPaymentSuccess = false;
        while (!isPaymentSuccess)
        {
            display_text("- Enter your credit card: ", false);
            getline(cin, credit_input);

            if (credit_input == credit_card)
            {
                inven.clear_inventory("user");
                isPaymentSuccess = true;
                display_text("*Payment successfully.", true);
            }
            else
            {
                display_text("# Invalid credit card number.", true);
            }
        }
    }
}
void payment(const string &credit_input, const Inventory &inven)
{
    inven.get_inventory("user");
}

// for constructing interface
void cut_line()
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
}
void clear_buffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void display_text(const string &text, bool isEndl)
{
    if (isEndl)
    {
        cout << text << endl;
    }
    else
    {
        cout << text;
    }
}

void display_banner(const string &heading)
{
    display_text("**********************************Window Shopping**********************************", true);
    display_text("---------------------------------> ", false);
    display_text(heading, false);
    display_text(" <---------------------------------", true);
}