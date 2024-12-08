#include "common.h"

// Displaying interface
void home(){
    display_banner("Home");
    display_text("1. Home", true);   
    display_text("2. Shopping as guest", true);   
    display_text("3. Login", true);
}

// Building interface
void cut_line(){
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
void clear_buffer(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void display_text(const string &text, bool isEndl){
    if (isEndl)
    {
        cout << text << endl;
    } else {
        cout << text;
    }
}

void display_banner(const string &heading){
    display_text("**********************************Window Shopping**********************************",true);
    display_text("---------------------------------> ", false);
    display_text(heading, false);
    display_text(" <---------------------------------", true);

}