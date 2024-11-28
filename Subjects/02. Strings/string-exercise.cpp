#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{

    // Reverse a string
    string rvs_str = {"Nguyen Linh Duong"};
    string temp_rvsStr = rvs_str;

    for (size_t i = 0; i < rvs_str.length(); i++)
    {
        temp_rvsStr.at(i) = rvs_str.at(rvs_str.length() - (i + 1));
    }

    cout << temp_rvsStr << endl;

    // Change every letter in a string to next letter
    string chge_str = {};
    // getline(cin, chge_str);
    for (size_t i = 0; i < chge_str.length(); i++)
    {
        if (int(chge_str.at(i)) >= 65 && int(chge_str.at(i) <= 90))
        {
            chge_str.at(i) = char(int(chge_str.at(i)) + 1);
        }
        else if (int(chge_str.at(i)) >= 97 && int(chge_str.at(i)) <= 122)
        {
            chge_str.at(i) = char(int(chge_str.at(i)) + 1);
        }
        else
        {
            chge_str.at(i) = char(int(chge_str.at(i)));
        }
    }

    cout << chge_str << endl;

    // Capitalize the first letter of each word in a given string
    string cap_str = {"nguyen linh duong"};
    // getline(cin, cap_str);
    cap_str.at(0) = toupper(cap_str.at(0)); // first capitalize character

    for (size_t i = 0; i < cap_str.length(); i++)
    {
        if (cap_str.at(i) == ' ')
        {
            cap_str.at(i + 1) = toupper(cap_str.at(i + 1));
        }
    }

    cout << cap_str << endl;

    // Find the largest word in a given string
    string larg_str = {" C++ is a generals-purpose progra-mming"};
    // getline(cin, larg_str);
    string temp_largStr = {}, result = {};

    for (size_t i = 0; i < larg_str.length(); i++)
    {
        if ((int(larg_str.at(i)) >= 65 && int(larg_str.at(i)) <= 90) || (int(larg_str.at(i)) >= 97 && int(larg_str.at(i)) <= 122))
        {
            temp_largStr.push_back(larg_str.at(i));
            if (i + 1 == larg_str.length())
            {
                if (result.length() <= temp_largStr.length())
                {
                    result = temp_largStr;
                }
                temp_largStr.clear();  
            }
            
        } else {
            if (result.length() <= temp_largStr.length())
            {
                result = temp_largStr;
            }
            temp_largStr.clear();   
        }
    }
    cout << result << endl;

    //  Sort characters (numbers and punctuation symbols are not included) in a string.
    string sort_str = {"a-012-=fn pk12cn7sa asd'12;3"};
    string result_sort = {};
    bool flag = true;
    char temp = 'x';
    for (size_t i = 0; i < sort_str.length(); i++)
    {
        if (sort_str.at(i) != ' ')
        {
            result_sort.push_back(sort_str.at(i));
        }
    }
    
    do
    {
        flag = true;
        for (size_t i = 0; i < result_sort.length() - 1; i++)
        {
            if (int(result_sort.at(i)) > int(result_sort.at(i + 1)))
            {
                temp = result_sort.at(i);
                result_sort.at(i) = result_sort.at(i + 1);
                result_sort.at(i + 1) = temp;
                flag = false;
            }
        }

    } while (!flag);
    
    cout << result_sort << endl;

    return 0;
}

/*
    --------
    - std:istream::getline() or cin.getline(char[], 50)
    - + Works with raw C-style string, header file <iostream> (Doesn't work with "String Object")
    - + Reads a line of input into a fixed-size character array (char[])
    - + cin.getline() read input from the stream until delimiter (\n newline or the user hit "enter")
    -
    - std::getline() or getline(cin, str)
    - + Works with "string object", header file <string>
    - + getline() read input from the stream until delimiter (\n newline or the user hit "enter")
    - + Designed for modern C++ and works with std::string, which provides dynamic memory management.
    --------

*/