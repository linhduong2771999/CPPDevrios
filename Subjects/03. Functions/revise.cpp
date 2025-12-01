#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

/*
    student's info: full name, id, contact num, subject(math, physic, chemistry), score 

    1. Add student
    2. Show all students
    3. Update student
    4. Delete student
    5. Sort students (sort by name, sort by score)
    6. Search student (seach by name or id)
    7. Show highest score (show top n highest score)
*/

// vector <vector<string>> student_list {};
vector <vector<string>> student_list {
    {"Nguyen Linh Duong", "NLD277", "0942740975", "math", "8"},
    {"Trieu Khanh", "TK32", "033294702", "chemistry", "4"},
    {"Quynh Anh", "QA56", "0718297362", "chemistry", "7"},
    {"Anh Ngoc", "AN22", "08572921", "math", "7"},
    {"Kdan Chan", "KC98", "01237112", "Physic", "9"}
};

void show_student_list(const vector <vector<string>> &student_list);
void show_student(const vector <vector<string>> &student_list);
void create_student(vector <vector<string>> &student_list);
void update_student(vector <vector<string>> &student_list);
void delete_student(vector <vector<string>> &student_list);
void sort_class(vector <vector<string>> &student_list, const string sortType);
void show_highest_score(vector <vector<string>> &student_list);
void display_text(const string &text, const bool &isEndl);

int find_student(const vector <vector<string>> &student_list);
/*
- getline_text function
    If using cin before getline() it will leave '\n' in the buffer, getline() will read what 
    leftover on the buffer (in this case, it read \n as the first character and skip the 
    user input). 
    use cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' ); from the <limits> library
    to clear '\n'.
*/ 
void getline_text(string &text);


void menu();
void heading(const string &text);


int main(){
    // Function definition & Declaration
    // Function Prototype
    // Function Parameter
    // Function Default Argument values
    // Function Overloading
    // Pass arrays to function
    // Pass by reference
    // Using const 
    int chosen_num {-1};



    heading(" Managing student software ");
    menu();
    while (chosen_num != 0)
    {
        display_text("Enter a number: ", false);
        cin >> chosen_num;
        if (cin.fail()){
            cin.clear();
            cin.ignore(100, '\n');
            display_text("Invalid number", true);
            /*
                When cin enters a fail state, it fails to parse the number into variable, so
                the value of variable is unclear (in this case chosen_num is set to 0 after fail
                state). We reset the value same as initialized value;
            */ 
           chosen_num = -1; 
        } else if(chosen_num > 8) {
            display_text("Please choose the number between 0 and 8", true);
        } else if(chosen_num == 1) {
            display_text("-> Create student", true);
            create_student(student_list);
        } else if(chosen_num == 2) {
            display_text("-> Show class", true);
            show_student_list(student_list);
        } else if(chosen_num == 3) {
            display_text("-> Update student", true);
            update_student(student_list);
        } else if(chosen_num == 4) {
            display_text("-> Delete student", true);
            delete_student(student_list);
        } else if(chosen_num == 5) {
            display_text("-> Show a student", true);
            show_student(student_list);
        } else if(chosen_num == 6) {
            display_text("-> Sort class by name(ascending)", true);
            sort_class(student_list, "ascending");
        } else if(chosen_num == 7) {
            display_text("-> Sort class by name(descending)", true);
            sort_class(student_list, "descending");
        } else if(chosen_num == 8) {
            display_text("-> Highest score list:", true);
            show_highest_score(student_list);
        } else if(chosen_num == 9) {
            heading(" Managing student software ");
            menu();
        }  else if(chosen_num == 10) {
        }   
    }

    heading(" Copy right@ 2025 ");
    
    return 0;
}

void show_student_list(const vector <vector<string>> &student_list){
    if (student_list.size() <= 0)
    {
        display_text("There are no students in the class currently. Please create and add into the list.", true);
    } else {
        for (size_t i = 0; i < student_list.size(); i++)
        {   
            cout << " + ";
            for (size_t j = 0; j < student_list.at(i).size(); j++)
            {
                cout << student_list.at(i).at(j) << " - ";
            }
            cout << endl;
        }
    }
}

void show_student(const vector <vector<string>> &student_list){
    int student_position {-1};

    if (student_list.size() <= 0)
    {
        display_text("There are no students in the class currently. Please create and add into the list.", true);
    } else {
        student_position = find_student(student_list);
        if (student_position != -1)
        {
            cout << " + ";
            cout << student_list.at(student_position).at(0) << " - "
            << student_list.at(student_position).at(1) << " - "
            << student_list.at(student_position).at(2) << " - "
            << student_list.at(student_position).at(3) << " - "
            << student_list.at(student_position).at(4) << " - ";
            cout << endl;
        } 
    }
}

void create_student(vector <vector<string>> &student_list){
    string name = {" "};
    string id = {" "};
    string contact = {" "};
    string subject = {" "};
    string score = {" "};
    vector <string> student {};
    display_text("      - Name: ", false);
    // We use getline_text function first in order to clear the '\n' character which was left in the buffer after cin stage
    getline_text(name);
    display_text("      - ID: ", false);
    getline(cin, id);
    display_text("      - Contact: ", false);
    getline(cin, contact);
    display_text("      - Subject: ", false);
    getline(cin, subject);
    display_text("      - Score: ", false);
    getline(cin, score);

    student.push_back(name);
    student.push_back(id);
    student.push_back(contact);
    student.push_back(subject);
    student.push_back(score);
    student_list.push_back(student);
}

void update_student(vector <vector<string>> &student_list){
    string name = {" "};
    string id = {" "};
    string contact = {" "};
    string subject = {" "};
    string score = {" "};
    int student_position = {-1};

    if (student_list.size() <= 0)
    {
        display_text("There are no students in the class currently. Please create and add into the list.", true);
    } else {
        student_position = find_student(student_list);
        if (student_position != -1)
        {
            display_text("      - Name: ", false);
            getline(cin, name);
            display_text("      - Contact: ", false);
            getline(cin, contact);
            display_text("      - Subject: ", false);
            getline(cin, subject);
            display_text("      - Score: ", false);
            getline(cin, score);

            student_list.at(student_position).at(0) = name;
            student_list.at(student_position).at(2) = contact;
            student_list.at(student_position).at(3) = subject;
            student_list.at(student_position).at(4) = score;
        }
    }
}

void delete_student(vector <vector<string>> &student_list){
    int student_position {-1};
    if (student_list.size() <= 0)
    {
        display_text("There are no students in the class currently. Please create and add into the list.", true);
    } else {
        student_position = find_student(student_list);
        if (student_position != -1)
        {
            student_list.erase(student_list.begin() + student_position);
        }
    }
}

void sort_class(vector <vector<string>> &student_list, const string sortType){
    vector <string> temp_student {};

    if (student_list.size() <=0)
    {
        display_text("There are no students in the class currently. Please create and add into the list.", true);
    } else {
        for (size_t i = 0; i < student_list.size(); i++)
        {
            for (size_t j = i + 1; j < student_list.size(); j++)
            {
                    if (
                        (sortType == "ascending" && (student_list.at(i).at(0) > student_list.at(j).at(0))) ||
                        (sortType == "descending" && (student_list.at(i).at(0) < student_list.at(j).at(0)))
                    ){
                            temp_student = student_list.at(i);
                            student_list.at(i) = student_list.at(j);
                            student_list.at(j) = temp_student;
                    } 
            }
        }
    }
}

void show_highest_score(vector <vector<string>> &student_list){
    vector <string> temp_student {};
    for (size_t i = 0; i < student_list.size(); i++)
    {
        for (size_t j = i + 1; j < student_list.size(); j++)
        {
            if (student_list.at(i).at(4) < student_list.at(j).at(4))
            {
                temp_student = student_list.at(i);
                student_list.at(i) = student_list.at(j);
                student_list.at(j) = temp_student;
            }
        }
    }
    for (size_t i = 0; i < student_list.size(); i++)
    {
        cout << " + ";
        cout << student_list.at(i).at(0) << 
        " - "<< student_list.at(i).at(4) << 
        endl;
    }
}

int find_student(const vector<vector<string>> &student_list){
    string id {""};

    display_text("      - Enter ID: ",false);
    getline_text(id);
    while (true)
    {
        for (size_t i = 0; i < student_list.size(); i++)
        {
            if (id == student_list.at(i).at(1))
            {
                return i;
            }
        }

        display_text("There is no student with the current id.", true);
        display_text("      - Enter ID(type -out- to exit): ",false);
        getline(cin, id);
        if (id == "out")
        {
            return -1;
        }
    }
}


void display_text(const string &text,  const bool &isEndl){
    if (isEndl)
    {
        cout << text << endl;
    } else {
        cout << text;
    }
}

void getline_text(string &string){
    cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
    getline(cin, string);
}

void menu(){
    display_text("  1. Add student", true);
    display_text("  2. Show class", true);
    display_text("  3. Update student details", true);
    display_text("  4. Delete a student", true);
    display_text("  5. Show a student", true);
    display_text("  6. Sort by name(ascending)", true);
    display_text("  7. Sort by name(descending)", true);
    display_text("  8. Highest score", true);
    display_text("  9. Menu", true);
    display_text("  0. Exit", true);
}
void heading(const string &text){
    display_text("********", false);
    display_text(text, false);
    display_text("********", true);
}