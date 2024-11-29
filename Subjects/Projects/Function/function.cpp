#include <iostream>
#include <vector>
#include <string>

using namespace std;

void display_text(const string &text, bool isEndl);
void display_list(const vector<vector<string>> &list_people);


int main(){
    cout << endl;
    cout << endl;
    vector<vector<string>> list_people = {
        {"Nguyen Linh Duong", "NLD1"},
        {"Trieu Khanh", "TK2"},
        {"Nguyen My Dinh", "NMD3"}
    };
    int num;
    // display_list(list_people);
    
    display_text("------------------------------------------------------------", false);
    display_text("Citizen Management Software--",true);
    display_text("- Thank you for choosing CMS for managing your business                                 -", true);
    display_text("-----------------------------------------------------------------------------------------", true);
    display_text("- Type a number below to enter a service you want to use:                               -", true);
    display_text("------------------------------------------------------------>                           -", true);
    display_text("- Type 1 for managing                                                                   -", true);
    display_text("- Type 2 for tutorials                                                                  -", true);
    display_text("- Type 3 for support                                                                    -", true);
    display_text("- Type 4 for software's info                                                            -", true);
    display_text("- Type 5 for company's info                                                             -", true);
    display_text("- => Type here: " , false);
    cin >> num;
    cout << endl;
    display_text("-----------------------------------------------------------------------------------------", true);


    



    cout << endl;
    cout << endl;
    return 0;
}

void display_text(const string &text, bool isEndl){
    if (isEndl)
    {
        cout << text << endl;
    } else {
        cout << text;
    }
}

void display_list(const vector<vector<string>> &list_people){
    for (size_t i = 0; i < list_people.size(); i++)
    {
        for (size_t j = 0; j < list_people.at(i).size(); j++)
        {
            cout << list_people.at(i).at(j) << " ";
        }
        cout << endl;
    }
}

/*
press 1 for manage menu
press 2 for tutorials
press 3 for support information
press 4 for software's information
press 5 for company information
*/

/*
update name
create name
delete name
read name

*/