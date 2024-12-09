#include <iostream>
#include <limits>

#include "header.h"

using namespace std;

/*
    User input: name player, number to choose character 
    Create a base class call PLayer:
    + name
    + class 
    + health
    + mana
    + level
    + skill 
    Derived class (human, monster, angel) have unique perk:
    + human: intelligent  
    + monster: strength
    + angel: blessing

*/

void display_text(const string &text, const bool isEndl);
void clear_buffer();

int main(){ 
    string name_player;
    string character_player;
    vector <string> class_human {"Knight", "Viking" ,"Samurai"};
    vector <string> class_monster {"Org", "Undead", "Dare Evil"};
    vector <string> class_angel {"White ghost", "Holy Eyes", "Chi"};
    int choose_class = -1;

    display_text("- Type your account's name: ", true);
    cin >> name_player;
    display_text("- Type your character's name: ", true);
    cin >> character_player;
    display_text("- Choose your character's class below (type number 1 - 3): ", true);

    while (choose_class != 0)
    {
        switch (expression)
        {
        case /* constant-expression */:
            /* code */
            break;
        
        default:
            break;
        }
    }
    


    

    Human human_1 {"Nguyen Linh Duong", "Borudus", "Knight", 1000, 250, 1, "Betrusted"};
    Monster monster_1 {"Nguyen Linh Duong", "Borudus", "Knight", 1000, 250, 1, "Betrusted"};
    Angel angel_1 {"Nguyen Linh Duong", "Borudus", "Knight", 1000, 250, 1, "Betrusted"};
    human_1.display_info();
    monster_1.display_info();
    angel_1.display_info();

     Player::display_total_player();
    return 0;
}

void display_text(const string &text, const bool isEndl){
    if (isEndl)
    {
        cout << text << endl;
    } else {
        cout << text;
    }
}

void clear_buffer(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
