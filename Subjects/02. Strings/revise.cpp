#include <iostream>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;

int main(){
    // char name[] {"Nguyen "};
    // strcat(name, "Linh ");
    // strcat(name, "Duong");

    // string str1 {"Nguyen"};
    // string str2 {"Linh"};
    // str1 =  "Duong" + str2; 

    // Reverse a Given String
        // string originalStr {"Nguyen Linh Duong"};
        // string reverseStr {};

        // for (int i = originalStr.length() - 1; i >= 0; i--)
        // {
        //     reverseStr.push_back(originalStr.at(i));
        // }
        // cout << reverseStr << endl;
    
    // Replace Each Letter with the Next in the Alphabet
        // string originalStr {"aNguyen Linh Duongz"};
        // string replacedStr;

        // for (size_t i = 0; i < originalStr.length(); i++)
        // {
        //     if (int(originalStr.at(i)) == 90)
        //     {
        //         replacedStr.push_back(char(65));
        //     }
        //     else if (int(originalStr.at(i)) == 122)
        //     {
        //         replacedStr.push_back(char(97));
        //     }
            
        //     else if ((int(originalStr.at(i)) >= 65 && int(originalStr.at(i)) <= 90) || (int(originalStr.at(i)) >= 97 && int(originalStr.at(i)) <= 122))
        //     {
        //         replacedStr.push_back(char(int(originalStr.at(i))+1));
        //     } else {
        //         replacedStr.push_back(char(int(originalStr.at(i))));
        //     }
            
        // }
        // cout << replacedStr << endl;

    // Capitalize the First Letter of Each Word
        // string originalStr {"nguyen linh duong"};
        // string capitalizedStr;

        // for (size_t i = 0; i < originalStr.length(); i++)
        // {
        //     if (i == 0)
        //     {
        //         capitalizedStr.push_back(toupper(originalStr.at(i)));
        //     } else if(int(originalStr.at(i-1)) == 32){
        //         capitalizedStr.push_back(toupper(originalStr.at(i)));
        //     } else {
        //         capitalizedStr.push_back(originalStr.at(i));
        //     }

        // }
        
        // cout << capitalizedStr << endl;

    // Find the Largest Word in a String
        // string originalStr {"The best way we learn anything is by practice and exercise questions"};
        // string longestWord, tempStr;
        // int count {0}; // keep track the number of char of the word

        // for (size_t i = 0; i < originalStr.length(); i++)
        // {
        //     if ( (int(originalStr.at(i)) >= 65 && int(originalStr.at(i)) <= 90) || (int(originalStr.at(i)) >= 97 && int(originalStr.at(i)) <= 122))
        //     {
        //         tempStr.push_back(originalStr.at(i));
        //         if (longestWord.length() < tempStr.length())
        //         {
        //             longestWord = tempStr;
        //         }
        //     } else {
        //         tempStr.clear();
        //     }
            
        // }
    // Sort Letters in a String
        // string originalStr {"python"};
        // string sortedStr;
        // char temp {' '};
        // bool isSwap {false};
        
        // do
        // {
        //     isSwap = false;
        //     for (size_t i = 0; i < originalStr.length() - 1; i++)
        //     {
        //         if (int(originalStr.at(i))  > int(originalStr.at(i + 1)))
        //         {
        //             temp = originalStr.at(i);
        //             originalStr.at(i) = originalStr.at(i + 1);
        //             originalStr.at(i + 1) = temp;
        //             isSwap = true;
        //         }
        //     }
        // } while (isSwap);

        // cout << originalStr << endl;
    // Strong password
        // have > 9 letters, at least 1 capitalize, 1 special, 1 number
    string currentPassword;
    string newPassword;
    bool hasUpper = false, hasSpecial = false, hasNumber = false;
    int number {1};
    cout << "Don't have a password, create one here! (press 1)" << endl;
    cout << "Enter your password (press 2)" << endl;

    while (number != 0)
    {
        cout << "Enter number (press 0 to exit the program): ";
        cin >> number; 
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid number" << endl;
            number = 1;
        } else if (number == 2) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Enter your password: ";
            getline(cin, currentPassword);
            if (newPassword.empty() < 0)
            {
                cout << "You don't have a password, to create one, press 1" << endl;
            } else {
                if (currentPassword == newPassword)
                {
                    cout << "Welcome!!!" << endl;
                    number = 0;
                } else {
                    cout << "Password is incorrect! Please enter again" << endl;
                }
            }
        } else if (number == 1) {
            // Clear user input before using getline
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Create new password: ";
            getline(cin, newPassword);
            if (newPassword.length() < 9 || newPassword.length() > 35)
            {
                cout << "Password must be less than 35 and greater than 9" << endl;
            } else {
                hasUpper = false, hasSpecial = false, hasNumber = false; // reset flag every time creating new password
                for (size_t i = 0; i < newPassword.length(); i++)
                {
                    if (int(newPassword.at(i)) >= 65 && int(newPassword.at(i)) <= 90 )
                    {
                        hasUpper = true;
                    } else if(int(newPassword.at(i)) >= 32 && int(newPassword.at(i)) <= 47 || int(newPassword.at(i)) >= 58 && int(newPassword.at(i)) <= 64){
                        hasSpecial = true;
                    } else if(int(newPassword.at(i)) >= 48 && int(newPassword.at(i)) <= 57){
                        hasNumber = true;
                    }
                }
                if (hasUpper && hasSpecial && hasNumber)
                {
                    currentPassword = newPassword;
                } else {
                    cout << "-X- Password must have at least 1 capitalize, 1 special, and 1 number" << endl;
                }
            }
        } else {
            cout << "Invalid number (only 1 and 2)" << endl;
        }
    }

    // Need to 
        // Incorrect variable initialization: bool hasUpper, hasSpecial, hasNumber {false};
        // Use isUpper, isNumber, isPunct
        // variable name: menuChoice, 
            
    return 0;
}