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
    * (update to three lv)
    *=
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
    Champion jinx {"jinx", 1000, 1};
    Champion vayne {"vayne", 1200, 1};
    Champion jhin {"jhin", 1100, 1};
    // jinx.display_info();
    // vayne.display_info();

    jhin = jinx = vayne;
    jinx.display_info();
    vayne.display_info();



    // jinx = vayne


    return 0;
}