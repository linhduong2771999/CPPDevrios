#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

// interface
void main_UI();
void viewing_list(const vector<vector<string>> &list_people);
void creating_person(vector<vector<string>> &list_people);
void updating_person(vector<vector<string>> &list_people);
void deleting_person(vector<vector<string>> &list_people);
void tutorial_UI();
void support_UI();
void softInfo_UI();
void compInfo_UI();

void clear_bufferInput();
void display_text(const string &text, bool isEndl);
void capitalize_firstLetter(string &name);
void generate_id(string &id, const string &name, const vector<vector<string>> &list_people);

vector <string>find_person(const string &id, const vector<vector<string>> &list_people);

int main(){
    // vector<vector<string>> list_people = {
    //     {"Nguyen Linh Duong", "NLD1"},
    //     {"Trieu Khanh", "TK2"},
    //     {"Nguyen My Dinh", "NMD3"}
    // };
      vector<vector<string>> list_people = {};

    int mainUI_num = -1;

    main_UI();
    while (mainUI_num != 0)
    {
        display_text("- => Type a number(9 to open menu): " , false);
        cin >> mainUI_num;
        // Verify number
        if (cin.fail()){
            clear_bufferInput();
            mainUI_num = -1;
            display_text("- Warning: Invalid number. Please enter a number.", true);
        } else if(mainUI_num >= 10){
            clear_bufferInput();
            display_text("- Warning: Invalid number. Please enter from 1 to 10.", true);
        } else if(mainUI_num == 0){
            cout << "exit" << endl;
        } else if(mainUI_num == 1){
            viewing_list(list_people);
        } else if(mainUI_num == 2){
            creating_person(list_people);
        } else if(mainUI_num == 3){
            updating_person(list_people);
        } else if(mainUI_num == 4){
            deleting_person(list_people);
        } else if(mainUI_num == 5){
            tutorial_UI();
        } else if(mainUI_num == 6){
            support_UI();
        } else if(mainUI_num == 7){
            softInfo_UI();
        } else if(mainUI_num == 8){
            compInfo_UI();
        } else if(mainUI_num == 9){
            main_UI();
        } 

        // clear_bufferInput(); // Clear anything that is left on the input buffer
    }

    // display_text("-----------------------------------------------------------------------------------------", true);
    return 0;
}

// Interface
void main_UI(){
    cout << endl;
    cout << endl;
    display_text("-------------------------------------------------------------", false);
    display_text("Citizen Management Software-",true);
    display_text("- Thank you for choosing CMS for managing your business                                 -", true);
    display_text("-----------------------------------------------------------------------------------------", true);
    display_text("- Type a number below to enter a service you want to use:                               -", true);
    display_text("------------------------------------------------------------>                           -", true);
    display_text("- Type 0 to exit the program                                                            -", true);
    display_text("- Type 1 for viewing                                                                    -", true);
    display_text("- Type 2 for creating                                                                   -", true);
    display_text("- Type 3 for updating                                                                   -", true);
    display_text("- Type 4 for deleting                                                                   -", true);
    // display_text("- Type 5 for tutorials                                                                  -", true);
    // display_text("- Type 6 for support                                                                    -", true);
    // display_text("- Type 7 for software's info                                                            -", true);
    // display_text("- Type 8 for company's info                                                             -", true);
}

void viewing_list(const vector<vector<string>> &list_people){
    display_text("------------------------------------------------------------>                           -", true);
    display_text("- List of employees: ", true);
    if (list_people.size() <= 0)
    {
        display_text("- Your list is empty. Please create and add a person.", true);
    } else {
        for (size_t i = 0; i < list_people.size(); i++)
        {
            cout << "-     + Name: ";
            cout << list_people.at(i).at(0);
            cout << " (ID: ";
            cout << list_people.at(i).at(1) << ")";
            cout << endl;
        }
    }
    display_text("------------------------------------------------------------>                           -", true);
}
void creating_person(vector<vector<string>> &list_people){
    string id = {""};
    string name = {" "};
    vector<string> person = {};
    
    clear_bufferInput();
    display_text("------------------------------------------------------------>                           -", true);
    display_text("- Enter name: ", false);
    getline(cin, name);

    capitalize_firstLetter(name);
    generate_id(id, name, list_people);
    person.push_back(name);
    person.push_back(id);

    list_people.push_back(person);
    display_text("- Creating successfully. Press 1 to view new list", true);
}
void updating_person(vector<vector<string>> &list_people){
    if (list_people.size() <= 0)
    {
        display_text("- Your list is empty. Please create and add a person.", true);
    } else {
        string id = {""}, newId = {""};
        string name = {""};
        vector <string> person = {};

        clear_bufferInput();
        display_text("------------------------------------------------------------>                           -", true);
       
        while (person.size() <= 0)
        {
            display_text("- Enter id: ", false);
            getline(cin, id);
            person = find_person(id, list_people);
            if (person.size() <= 0)
            {
                cout << "- There are no person with id: " << id << endl;
            }
        }

        cout << "- Old name: " << person.at(0) << " | " << "Old id: " << person.at(1) << endl;
        display_text("- Update name: ", false);
        getline(cin, name);
        
        // Update and generate new id
        for (size_t i = 0; i < list_people.size(); i++)
        {
            if (id == list_people.at(i).at(1))
            {
                capitalize_firstLetter(name);
                generate_id(newId, name, list_people);
                list_people.at(i).at(0) = name;
                list_people.at(i).at(1) = newId;
            }
        }
        display_text("- Updating successfully. Press 1 to view new list", true);
    }
}
void deleting_person(vector<vector<string>> &list_people){
    if (list_people.size() <= 0)
    {
        display_text("- Your list is empty. Please create and add a person.", true);
    } else {
        string id = {""};
        string name = {""};
        vector <string> person = {};

        clear_bufferInput();
        display_text("------------------------------------------------------------>                           -", true);
       
        while (person.size() <= 0)
        {
            display_text("- Enter id: ", false);
            getline(cin, id);
            person = find_person(id, list_people);
            if (person.size() <= 0)
            {
                cout << "- There are no person with id: " << id << endl;
            }
        }
        // Delete
        for (size_t i = 0; i < list_people.size(); i++)
        {
            if (id == list_people.at(i).at(1))
            {
                list_people.erase(list_people.begin() + i);
            }
        }

        display_text("- Deleting successfully. Press 1 to view new list", true);
    }
}
void tutorial_UI(){
    display_text("tutorial", true);
}
void support_UI(){
    display_text("support", true);
}
void softInfo_UI(){
    display_text("software info", true);
}
void compInfo_UI(){
    display_text("company info", true);
}

void clear_bufferInput(){
    cin.clear();
    cin.ignore( numeric_limits<streamsize>::max() , '\n');
}

void display_text(const string &text, bool isEndl){
    if (isEndl)
    {
        cout << text << endl;
    } else {
        cout << text;
    }
}

void capitalize_firstLetter(string &name){
    for (size_t i = 0; i < name.length(); i++)
    {
        if (i == 0 || name.at(i - 1) == ' ')
        {
            name.at(i) = toupper(name.at(i));
        }
    }
}

void generate_id(string &id, const string &name, const vector<vector<string>> &list_people){
     for (size_t i = 0; i < name.length(); i++)
    {
        if (i == 0 || name.at(i - 1) == ' ')
        {
            id.push_back(name.at(i));
        }
    } 
    id = id + to_string(list_people.size() + 1);
}

vector <string>find_person(const string &id, const vector<vector<string>> &list_people){
    vector<string> person = {};
    for (size_t i = 0; i < list_people.size(); i++)
    {
        if (id == list_people.at(i).at(1))
        {
            person.push_back(list_people.at(i).at(0));
            person.push_back(list_people.at(i).at(1));
        }
    }
    return person;
}

/*
update name
create name
delete name
read name

*/