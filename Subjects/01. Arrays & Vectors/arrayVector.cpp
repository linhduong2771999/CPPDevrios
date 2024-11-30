#include <iostream>
#include <vector>


using namespace std;

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









