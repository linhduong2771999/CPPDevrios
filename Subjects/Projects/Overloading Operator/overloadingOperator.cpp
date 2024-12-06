#include <iostream>

#include "header.h"

using namespace std;


/*
    - (reduce 1 lv)
    ==
    !=
    < ()
    >
    +
    +=
    ++
    --
    >>
    <<
*/

/*
    champ + champ = champ level 2
    champ lv2 + champ lv2 = champ level 3
*/




int main(){
    Champion champ_1 {"jinx", 900, 0};
    // -champ_1;
    // champ_1.display_info();
    Champion champ_2 {"vayne", 1200, 1};
    // cout << (champ_2 == champ_1) << endl; 
    // cout << (champ_2 != champ_1) << endl; 
    // cout << (champ_2 > champ_1) << endl; 
    // cout << (champ_2 < champ_1) << endl; 
    Champion champ_3 {"jhin", 2100, 2};
    Champion champ_4 {"caitlyn", 3400, 3};
    Champion champ_5 {"twitch", 4170, 4};
    Champion champ_6 {"kogmaw", 5250, 5};
    // champ_1.display_info();
    // champ_2.display_info();
    // champ_3.display_info();
    // champ_4.display_info();
    // champ_5.display_info();
    // champ_6.display_info();
    // champ_1 = champ_1 + champ_2;
    champ_6 = champ_5--;
    champ_5.display_info();
    champ_6.display_info();

    cin >> champ_1;
    cout << champ_1 << endl;
    // -champ_3;

    
    

    return 0;
}