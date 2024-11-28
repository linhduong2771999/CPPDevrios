#include <iostream>
#include <string>
#include <limits>

using namespace std;
    /*
        This is a one-way encrypted messages
        Code message standard:
        a = t  x = /  A = '   Q = <
        b = i  y = 9  B = 6   W = >
        c = 1  v = 2  C = m   Z = 1
        d = @  t = 6  D = 9   X = 7
        e = '  r = p  E = a   Y = 8
        f = m  u = j  F = 1   V = w
        g = +  1 = u  G = x   T = ;
        h = z  2 = 0  H = r   R = 2
        i = a  3 = s  I = p   U = 0
        j = /  4 = n  J = [   space = c
        k = v  5 = ]  L = 0
        l = 6  6 = 8  M = 7
        m = 9  7 = b  N = n
        n = ,  8 = z  O = -
        o = r  9 = 2  P = ]
        p = a         K = n  
        q = ;
        w = a
        z = v
    */

    int
    main()
{
    string alpha_str = {"abcdefghijklmnopqwzxyvtru123456789ABCDEFGHIJKLMNOPQWZXYVTRU "};
    string key_str = {"ti1@'m+za/v69,ra;av/926pju0sn]8bz2'6m9a1xrp[n07n-]<>178w;20c"};
    char num_exit = '1';
    while (num_exit != '0')
    { 
        string mess_str = {" "};
        string result = {};
        cout << "Type messages: "; 
        getline(cin, mess_str);
        // Prevent all special characters
        for (size_t i = 0; i < mess_str.length(); i++)
        {

            if ((int(mess_str.at(i)) >= 48 && int(mess_str.at(i)) <= 57) ||
                (int(mess_str.at(i)) >= 65 && int(mess_str.at(i)) <= 90) ||
                (int(mess_str.at(i)) >= 97 && int(mess_str.at(i)) <= 122) ||
                mess_str.at(i) == ' ')
            {
                for (size_t j = 0; j < alpha_str.length(); j++)
                    {
                        if (mess_str.at(i) == alpha_str.at(j))
                        {
                            result.push_back(key_str.at(j));
                        } 
                    }
            } else {
                result = "Please do not enter special characters";
                // cout <<  << endl;
                break;
            }
        }
        cout << "Your encrypted message in the database: " << result << endl;
        cout << "To exit hit 0 - to continue hit any letters: ";
        cin >> num_exit;
        cin.ignore( numeric_limits<streamsize>::max() , '\n');
    }

    
    return 0;
}

/*
    if you use cin before getline
    it will leave \n in the buffer
    getline will read what leftover on the buffer (in this case, it read \n as the 
    first character and skip the user input)
    use cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' ); from the <limits> library


*/