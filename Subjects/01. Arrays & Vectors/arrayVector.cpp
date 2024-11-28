#include <iostream>
#include <vector>


using namespace std;


/*
    If you use the [] to access vector's element. Vector will not do bound checking. 

    --------
    - If you type texts into integer: cin >> number || input: abc
    - "abc" will be put into the "input buffer" [a,b,c]
    - "cin" reads the texts from the buffer   
    - Since the input is a texts "cin" cannot parse its into an integer variable.
    - "cin" enters a fail stage, the input buffer will not be consumes and the 
    -remain texts will stay in the buffer. 
    - "cin" will skip any next cin function unless it clears the buffer by "cin.clear() & cin.ignore()".
    -
    - If you type into integer: cin >> number || input: 123abc
    - "123abc" will be put into the "input buffer" [1,2,3,a,b,c]
    - "cin" will extract and parse 123 into the integer, but not "abc", so the buffer
    -now still contains "abc" [a,b,c] 
    - If the next cin is integer: it enters a fail stage
    - If the next cin is strings: it extracts "abc" from the buffer into variable
    --------

    
    ---------
    - Compile time and Runtime
    - Compile time: The phase where the code is compiled into machined code(1 & 0) by compiler, then
    -it creates executable file for the operating system can run.  
    -   Purposes: Syntax checking, type checking, error detection, linking errors...   
    - Runtime: The phase where the compiled program is executed (the executable file is executed).
    -   Common errors: Math problems 
    ---------
*/
int main(){

    int arr1 [5] {0,1,2,3};
    char arr2 [2] {'s', 'a'};
    int arr3 [] {}; // prevent garbages

    cout <<  arr3[0] << endl;
    
    int twoDarr [] {1, 2};

    vector <int> vector1 {1, 2};
    vector <int> vector2 (12, 0);

    vector1.push_back(1);
 
    return 0;
}









/*
    why use initialize list
    how vector works behind    
    using namespace
*/