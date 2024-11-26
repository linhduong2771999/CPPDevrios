#include <iostream>
#include <vector>


using namespace std;


/*
    If you use the [] to access vector's element. Vector will not do bound checking. 

*/
int main(){

    int arr1 [5] {0,1,2,3};
    char arr2 [2] {'s', 'a'};
    int arr3 [] {}; // prevent garbagess

    int twoDarr [] {1, 2};

    vector <int> vector1 {1, 2};
    vector <int> vector2 (12, 0);

    vector1.push_back(1);
 
    return 0;
}









/*
    understand variables
    compile time, compiler
    initialize list
    how vector works behind    

*/