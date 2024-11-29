#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*
    --------
    - Pointers
    - + If you dont initialize pointer to null or some value. It contains garbages like variables.
    - + You should not dereferencing a pointer poiting to nulltr. It causes the program crash.
    --------

    --------
    - Dynamic memory allocation   
    --------

    --------
    - Arithmetic
    - *arr_ptr_num++ => This code execute: dereference first, then increment
    -
    - + const int *score_ptr = {&score} (a score pointer that point to constant int value)
    - + int *const score_ptr = {&score} (a constant score pointer that point to int value)
    - + const int *const score_ptr = {&score} (a constant score pointer that point to constant int value)
    --------

     --------
    - Passing pointer to function   
    -
    --------
*/

// Passing pointer to function
void caculate_num(int *a, int *b){
    cout << *a + *b << endl;
}

// returning pointer to function
int *caculate_numbers(int *a, int *b){
    int temp = *a + *b;
    int *c = {&temp};
    return c;
}
int *return_ptr(int size){
    int *new_array = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        new_array[i] = 100;
    }
    return new_array;
}


int main(){

    int inter = 0;
    int *int_ptr = {&inter};
    double *double_ptr = {nullptr};
    char *char_ptr = {nullptr};
    string *str_ptr = {nullptr};
    vector <int> vec_int = {0,1,2};
    vector <int> *vector_ptr = {&vec_int};
    cout << int_ptr << endl; // call the address of what the pointer is pointing to
    cout << &int_ptr << endl; // call the address of pointer
    cout << *int_ptr << endl; // get the data of what the pointer is pointing to
    cout << (*vector_ptr).at(0) << endl;

    int *dynamic_ptr = new int;
    *dynamic_ptr = 100;
    cout << dynamic_ptr << endl;
    cout << &dynamic_ptr << endl;
    cout << *dynamic_ptr << endl;
    delete dynamic_ptr;
    cout << endl;

    int num_size = 0;
    // cin >> num_size;
    int *dynaArr_ptr = new int[num_size];
    for (size_t i = 0; i < num_size; i++)
    {
        dynaArr_ptr[i] = 0;
        cout << dynaArr_ptr[i];
    }
    delete [] dynaArr_ptr;
    
    // Arithmetic
    int a = 100, b = 200, c = 0;
    int *a_ptr = {&a};
    int *b_ptr = {&b};
    c = b_ptr - a_ptr;
    cout << "c: " << c << endl;
    cout << endl;

    int arr_1 [] = {1,2,3,4,5,6};
    int *arr_ptr = {arr_1};
    while (*arr_ptr != 6)
    {
        cout << *arr_ptr++ << " ";
    }
    cout << endl;

    // Passing pointer to function
    int int1 = 10, int2 = 10;
    int *int1_ptr =  {&int1};
    int *int2_ptr =  {&int2};
    caculate_num(int1_ptr, int2_ptr);
    
    // Returning pointer to function
    cout << *caculate_numbers(int1_ptr, int2_ptr) << endl;
    int *return_arr = return_ptr(10);
    cout << return_arr << endl;

    for (size_t i = 0; i < 10; i++)
    {
        cout << *(return_arr + i);  
    }

    delete [] return_arr;

    cout << return_arr << endl;
    
    return 0;
}