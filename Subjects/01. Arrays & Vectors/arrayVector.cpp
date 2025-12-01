#include <iostream>
#include <vector>


using namespace std;

/*
    Array & Vector

    --------
    - + C++ has three different array types that are commonly used: std::vector, 
    -std::array (modern C++), and C-style arrays.
    - + Use std::array for constexpr arrays, and std::vector for non-constexpr arrays.
    --------

    --------
    - When to use std::array (modern C++) vs C-styles array
    - + std::array is an object (same like vector) built in C++ 11
    --------

    --------
    - + C-style arrays don’t support assignment
    --------

*/

int main(){

    int arr1 [5] {0,1,2,3};
    char arr2 [2] {'s', 'a'};
    int leng = 5 ;
    int arr3 [leng] {}; // prevent garbages

    cout <<  arr3[0] << endl;
    
    int twoDarr [] {1, 2};

    vector <int> vector1 {1, 2};
    vector <int> vector2 (12, 0);

    vector1.push_back(1);
 
    return 0;
}









