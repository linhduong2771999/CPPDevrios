#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

int main()
{
    int numbers[10] {21,1,4,12,55,36,98,33,0,77};
    // int numbers[] = {7, 12, 9, 15, 19, 32, 56, 70};
    int array_size = sizeof(numbers) / sizeof(int);

    // // Find the largest element of the array
    // int largest_element{0};
    // for (size_t i = 0; i < array_size; i++)
    // {
    //     if (largest_element < numbers[i])
    //     {
    //         largest_element = numbers[i];
    //     }
    // }

    // // Find the three largest element of the array
    // int largestElement,
    //     secondLargestElement,
    //     thirdLargestElement {0};
    // for (size_t i = 0; i < array_size; i++)
    // {
    //     if (largestElement < numbers[i])
    //     {
    //         thirdLargestElement = secondLargestElement;
    //         secondLargestElement = largestElement;
    //         largestElement = numbers[i];
    //     }
    //     else if (secondLargestElement < numbers[i])
    //     {
    //         thirdLargestElement = secondLargestElement;
    //         secondLargestElement = numbers[i];
    //     }
    //     else
    //     {
    //         thirdLargestElement = numbers[i];
    //     }
    // }

    // Find the n largest numbers in the array

    // int n {0};
    // int largestElement {0};
    // int tempArray[array_size] {0}; // initialize the first element in temporary array is 0 
    // cin >> n;
    // if (cin.fail())
    // {
    //     cin.clear();
    //     cin.ignore(100, '\n');
    //     cout << "Invalid number" << endl;
    // } else if (n > array_size){
    //     cout << "The number must smaller than the array's size" << endl;
    // } else {
    //     for (size_t i = 0; i < n; i++)
    //     {
    //         for (size_t j = 0; j < array_size; j++)
    //         {
    //             if (largestElement < numbers[j])
    //             {
    //                 largestElement = numbers[j];
    //             }
    //         }
    //         for (size_t k = 0; k < array_size; k++)
    //         {
    //             if (largestElement == numbers[k])
    //             {
    //                 numbers[k] = 0;
    //             }
    //         }
    //         tempArray[i] = largestElement;
    //         largestElement = 0;
    //     }
    // }
    
    // for (size_t k = 0; k < n; k++)
    // {
    //     cout << tempArray[k] << endl;
    // }

    // Elements at least two greater neighbors

    // int tempArray[array_size] {0}; 
    // if (array_size < 2)
    // {
    //     cout << "Invalid array" << endl;
    // } else {
    //     for (size_t i = 0; i < array_size; i++)
    //     {
    //         int count {0};
    //         for (size_t j = 0; j < array_size; j++)
    //         {
    //             if (numbers[i] < numbers[j])
    //             {
    //                 count++;
    //             }
    //         }
    //         if (count >= 2)
    //         {
    //             cout << numbers[i] << endl;
    //         }
    //     }
    // }

    // Most frequent elements in the array

    // int frequentArray[] {1,23,52,1,4,22,52,77,91,77,52};
    // int frequentArray_size = sizeof(frequentArray) / sizeof(int);
    // int tempArray[] {0};
    // int mostCount {1};
    // for (size_t i = 0; i < frequentArray_size; i++)
    // {
    //     int currentCount {1};
    //     for (size_t j = 1; j < frequentArray_size; j++)
    //     {
    //         if (frequentArray[i] == frequentArray[j])
    //         {
    //             currentCount++;
    //         }
    //     }

    //     if (currentCount > mostCount)
    //     {
    //         mostCount = currentCount;
    //     }
    // }
    // for (size_t i = 0; i < frequentArray_size; i++)
    // {
    //     int currentCount {1};
    //     for (size_t j = 1; j < frequentArray_size; j++)
    //     {
    //         if (frequentArray[i] == frequentArray[j])
    //         {
    //             currentCount++;
    //         }
    //     }
    //     if (currentCount == mostCount)
    //     {
    //         cout << frequentArray[i] << endl;
    //     }
    // }

    // Elements smaller than adjacent neighbors   

    // vector <int> vectorNums {21,1,4,12,55,36,98,33,0,77};
    // for (size_t i = 1; i < vectorNums.size() - 1; i++)
    // {
    //     if (vectorNums.at(i - 1) > vectorNums.at(i) && vectorNums.at(i + 1) > vectorNums.at(i) )
    //     {
    //         cout << vectorNums.at(i) << endl;
    //     }
    // }
    
    // Create an n x n Matrix from Input
    // char exitProgram {'n'};
    // int columns {0};
    // int rows {0};
    
    // while (exitProgram != 'y')
    // {
    //     cout << "Create a matrix (limit 10X10)" << endl;
    //     cout << "Enter columns: ";
    //     cin >> columns;
    //     cout << "Enter rows: ";
    //     cin >> rows;
    //     if (cin.fail())
    //     {
    //         cin.clear();
    //         cin.ignore(100,'\n');
    //     } else if (columns > 10){
    //         cout << "The limited columns of matrix is 10" << endl;
    //     } else if (rows > 10) {
    //         cout << "The limited rows of matrix is 10" << endl;
    //     } else {
    //         vector <vector<int>> vectorNums (rows, vector<int> (columns, 0));
    //         for (size_t i = 0; i < rows; i++)
    //         {
    //             for (size_t j = 0; j < columns; j++)
    //             {
    //                 cout << vectorNums.at(i).at(j);
    //             }
    //             cout << endl;
    //         }
    //     }

    //     exitProgram = 'y';
    // }

    // Implement project tic-tac-toe
    char exitProgram {'n'}; 
    int rows {0};
    int columns {0};
    bool switchTurn {true}; // true is x's turn to play, false is o's turn
    int count {0}; // if the game's turn is exceeded 9 and still not have a winner, the game draws
    vector <vector<char>> ticTacToe {{'*','*','*'},{'*','*','*'},{'*','*','*'}};

    cout << "Welcome to Tic Tac Toe game" << endl;
    cout << "Rules are simple, get three of your marks in a row by enter respectively 0, 1, 2 of rows and columns" << endl;
    cout << endl;
    cout << "  " << "0 " << "1 " << "2" << endl;
    for (size_t i = 0; i < ticTacToe.size(); i++)
    {
        cout << i << " ";
        for (size_t j = 0; j < ticTacToe.size(); j++)
        {
            cout << ticTacToe.at(i).at(j) << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "X moves first" << endl;
    while ( exitProgram != 'y')
    {
        cout << "Rows: ";
        cin >> rows;
        cout << "Columns: ";
        cin >> columns;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid number" << endl;
        } else if (rows >= 3 || columns >= 3){
            cout << "The number of row and column must be smaller than 3 (0,1,2)" << endl;
        } else{
            if (ticTacToe.at(rows).at(columns) == '*')
            {
                count++;
                if (switchTurn)
                {
                    ticTacToe.at(rows).at(columns) = 'x';
                    switchTurn = false;
                } else {
                    ticTacToe.at(rows).at(columns) = 'o';
                    switchTurn = true;
                }
                for (size_t i = 0; i < ticTacToe.size(); i++)
                {
                    for (size_t j = 0; j < ticTacToe.size(); j++)
                    {
                        cout << ticTacToe.at(i).at(j) << " ";
                    }
                    cout << endl;
                }
                // Verify the game whether end or not, win or draw or lose
                // Following ordered row 0, 1, 2, column 0, 1, 2, diagnose 1, 2
                if (
                    (ticTacToe.at(0).at(0) != '*') && (ticTacToe.at(0).at(0) == ticTacToe.at(0).at(1)) && (ticTacToe.at(0).at(1) == ticTacToe.at(0).at(2)) ||
                    (ticTacToe.at(1).at(0) != '*') && (ticTacToe.at(1).at(0) == ticTacToe.at(1).at(1)) && (ticTacToe.at(1).at(1) == ticTacToe.at(1).at(2)) ||
                    (ticTacToe.at(2).at(0) != '*') && (ticTacToe.at(2).at(0) == ticTacToe.at(2).at(1)) && (ticTacToe.at(2).at(1) == ticTacToe.at(2).at(2)) ||
                    (ticTacToe.at(0).at(0) != '*') && (ticTacToe.at(0).at(0) == ticTacToe.at(1).at(0)) && (ticTacToe.at(1).at(0) == ticTacToe.at(2).at(0)) ||
                    (ticTacToe.at(0).at(1) != '*') && (ticTacToe.at(0).at(1) == ticTacToe.at(1).at(1)) && (ticTacToe.at(1).at(1) == ticTacToe.at(2).at(1)) ||
                    (ticTacToe.at(0).at(2) != '*') && (ticTacToe.at(0).at(2) == ticTacToe.at(1).at(2)) && (ticTacToe.at(1).at(2) == ticTacToe.at(2).at(2)) || 
                    (ticTacToe.at(0).at(0) != '*') && (ticTacToe.at(0).at(0) == ticTacToe.at(1).at(1)) && (ticTacToe.at(1).at(1) == ticTacToe.at(2).at(2)) || 
                    (ticTacToe.at(0).at(2) != '*') && (ticTacToe.at(0).at(2) == ticTacToe.at(1).at(1)) && (ticTacToe.at(1).at(1) == ticTacToe.at(2).at(0))
                ) {
                    if (switchTurn)
                    {
                        cout << "-> O win" << endl;
                        exitProgram = 'y';
                    } else {
                        cout << "-> X win" << endl;
                        exitProgram = 'y';
                    }
                }
                if (count >= 9)
                {
                    cout << "-> Draw" << endl;
                    exitProgram = 'y';
                }
                
            } else {
                cout << "Slot has already been placed" << endl;
            }
        }   
    }
    
    return 0;
}