#include <iostream>
#include <cstring>
#include <string>

using namespace std;

/*
    C-style Strings & C++ Strings

    --------
    - Character functions: allow working characters such as conversion,
    -lowercase, uppercase...
    - Include <cctype> library if want to use.
    --------

    --------
    - C-style Strings
    - + Stored contiguous in memory, fixed in size, terminated by Null Character(\0),
    -can be access as an array.
    - + my_name = "Dng", C-style will not allow assignment like that
    -because "my_name" represents a location (it fixed in size and cannot be replaced). Use "strcpy" function to assign.
    - + my_name is called C-style string variable
    - + "Dng" is called C-style string literal
    -
    - <cstring> library contains functions work with C-style Strings: copying, concat,
    -comparison, searching...
    --------

    --------
    - C++ Strings
    - + Stored contiguous in memory, dynamic in size,
    - + You can use the assignment to assign value to string variables
    - ex: str1 = str2 + "nguyen" (String Class + C-style string) you can do this.
    - ex: str1 = "str2" + "nguyen" (C-style string + C-style string) you can't do this.
    _
    --------


    --------
    - When you pass string literal(const char[]) to function has string object parameter
    -(string str). Compiler will create temporary string object (it is called implicit 
    - conversion) holds the text of string literal.
    -
    - The compiler can convert from literal to object but not from object to literal
    --------

*/

int main(){

    char str_arr[12]; 
    strcpy(str_arr, "Nguyen ");
    strcat(str_arr, "Linh ");
    strcat(str_arr, "Duong");
    cout << str_arr << endl;
    cout << strlen(str_arr) << endl;
    cout << strcmp(str_arr, "Arieu Khanh") << endl;

    cout << "---------------------------------------" << endl;

    string str1;
    string str2 = {"Nguyen"};
    string str3 = {"Linh"};
    string str4 = {"Duong"};

    string str5 = str2 + " " + str3 + " " + str4;
    string str6 = str2 + " " + "Linh" + " " + str4; 

    // cout << str5.at(20) << endl; // this will do bound checking
    cout << str6[20] << endl;
    cout << str6.substr(0, 12) << endl; // extract specific strings
    cout << str6.find("Linh") << endl; // find specific strings
    cout << str6.erase(0, 4) << endl; // remove specific strings
    cout << str6.length() << endl; // display length of strings

    str6.clear(); // clear strings


    return 0;
}