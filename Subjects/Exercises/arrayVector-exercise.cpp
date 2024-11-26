#include <iostream>
#include <vector>

using namespace std;

int main(){

    // find the largest number in array 
    int arr_1[7] = {12,1,5,24,6,24,9};
    int temp_num = 0;
    for (int num : arr_1)
    {
        if (num >= temp_num)
        {
            temp_num = num;
        }   
    }
    cout << "The largest number is: " << temp_num << endl;

    // find the largest three number in array 
    int arr_2[7] = {12,1,5,24,6,24,9};
    int first = 0, second = 0, third = 0;
    int loop_num = 0;
    while (loop_num < 3)
    {
        for (size_t i = 0; i < 7; i++)
        {
            if (arr_2[i] > first && loop_num == 0)
            {
                first = arr_2[i];
            }
            if (arr_2[i] > second && arr_2[i] < first && loop_num == 1 )
            {
                second = arr_2[i];
            }
            if (arr_2[i] > third && arr_2[i] < second && loop_num == 2 )
            {
                third = arr_2[i];
            }
        }
        loop_num++;
    }
    cout << "The largest three number is: " << first << " " << second << " " << third << endl;

    // find the second largest number in array
    int arr_3[7] = {12,1,5,32,6,24,9};
    int first1 = 0, second1 = 0;

    for (size_t i = 0; i < 7; i++)
    {
        if (arr_3[i] > first1)
        {
            second1 = first1;
            first1 = arr_3[i];
        } else if (arr_3[i] > second1){
            second1 = arr_3[i];
        }
    }
    cout << "The second largest number is: " << second1 << endl;
    
    // find the N largest number in array
    int arr_4[7] = {12,1,5,32,6,24,9};
    int arrSize = sizeof(arr_4)/sizeof(int);
    int temp_arr[] = {};
    int n = 1;
    int firstLrg = 0, secondLrg = 0;
    while (n != 0)
    {
        cout << "How many largest number you want to find (enter 0 to exit): ";
        cin >> n;  
        temp_arr[n] = {0};
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid number" << endl;
        } else if (n > arrSize) {
            cout << "Please enter valid numbers smaller than array's size(7) " << endl;
        } else {
            for (size_t i = 0; i < n; i++)
            {
                for (size_t j = 0; j < arrSize; j++)
                {
                    if (arr_4[j] > firstLrg && arr_4[j] < temp_arr[i])
                    {
                        secondLrg = firstLrg;
                        firstLrg = arr_4[j];
                    } else if (arr_4[j] > secondLrg){
                        secondLrg = arr_4[j];
                    }
                    // firstLrg = secondLrg;
                }
                temp_arr[i] = firstLrg;
                firstLrg = 0;
            }
        }
    cout <<  temp_arr[0] << temp_arr[1] << temp_arr[2] << endl;
    }
    

    return 0;
}

/*
Best Practices
Always Validate Input:
Check std::cin.fail() after reading input to detect errors.
Clear the Input Buffer:
Use std::cin.ignore() to discard unwanted characters.
Use std::getline() for Mixed Input:
Combine std::getline() and std::cin for more predictable behavior when handling strings and numbers together.
Reset Error States:
If std::cin enters a failure state, call std::cin.clear() to restore normal functionality.


*/