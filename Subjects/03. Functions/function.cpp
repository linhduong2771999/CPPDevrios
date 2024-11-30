#include <iostream>

using namespace std;

/*
    --------
    - Definition and Declaration functions
    - + Compiler must know the function details before it is called.
    - + Function declaration: introduces the function's name, return type, and parameters to the compiler.
    -   it simply tells: "This function exists, and here's how to call it."
    -   it does not include the function's body (i.e., the code that performs the task).
    - + Function definition: A function definition provides the full implementation of the function, 
    -including the body (the code block that specifies what the function does).
    -   it implements the behavior of the function.
    ----------

    ---------
    - Function prototype
    - + It gives the compiler all information about the function before it is called (usually
    -it has to check the number of parameters passed in and types are correct )
    ----------

    ----------
    - Function parameter
    - + In definition func: It's called parameters
    - + In function called (or when you call the function): It's called arguments ( sayhello(); )
    - + Parameter: are variables in a function's definition
    - + Argument:  are the values passed to the function when it's called
    ----------

    ----------
    - Pass by value
    - When you pass a value(int, string, double...) to a function, compile makes a copy of the data
    -in order to not change the original data.
    ----------

     ----------
    - Pass by reference
    - Reference is an alias to actual parameters. Suppose you pass "number" variables to a reference
    -parameters function, behind the scene you actual pass the location of the "number" to it.
    -
    ----------

    ----------
    - Default parameters
    - + Always specify default parameters in the declaration(prototype), not in the definition function.  
    -This ensures clarity and prevents unexpected behaviors.
    - + If you put parameters to definition function but not in the declaration. The compiler will only read
    -parameters in declaration and ignore all the parameters in the definition function.
    ----------

    ----------
    - Inline function
    - Link: https://www.geeksforgeeks.org/inline-functions-cpp/ (for easy reading)
    -
    - + If a function is inline, the compiler will places a copy of the specified's code at each point where the 
    -function is called (The function is placed in the code, rather than being actually called).
    - + Only use when you know the transfer control of the function timing is less than the execution of the 
    -function called.
    - + The compiler will evaluate the function to determine whether it places inline keyword or not. You do not need
    -to use "inline" in cpp file. Use in "header file" to prevent linker errors.
    - + When you call a function, the compiler will move to the definition to look for the code to execute, with 
    -inline function, the compiler place a copy of that code and execute immediately.
    - + Instead of calling stack, heap or activation record. The compiler will place all the code where the
    - called function called.
    -
    - The compiler may not perform inlining in such circumstances as: Looping, static variables, recursive, void function
    + Usage: frequency of the calls, size of the function
    ----------



*/

// function prototype
void say_hello();

// function parameters
void display_numbers(int num);

// function default parameters
void display_default_numbers(int num_1 = 12, double num_2 = 3.45);

// function overloading
void display_everything(int num);
void display_everything(double num);
void display_everything(string str);

// passing array to function
void display_array(const int arr[], size_t size);

// Pass by reference
void display_ref_numbers(int &num);

// Inline function


int main(){

    say_hello();
    display_default_numbers();
    display_everything(1);
    display_everything(1.12);
    display_everything("nguyen linh duong");

    int arr[10] = {1,2,3,4,5,6,7,8,9,10}    ;
    int size = sizeof(arr)/sizeof(int);
    display_array(arr, size);
    cout << endl;

    int numbers = 0;
    display_ref_numbers(numbers);

    return 0;
}

void say_hello(){
    cout << "Hello" << endl;
}

void display_numbers(int num){
    cout << num << endl;
}

void display_default_numbers(int num_1 , double num_2 ){
    cout << num_1 << num_2 << endl;
}

void display_everything(int num){
    cout << num << endl;
}
void display_everything(double num){
    cout << num << endl;
}void display_everything(string str){
    cout << str << endl;
}

void display_array(const int arr[], size_t size){
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i];
    }
}

void display_ref_numbers(int &num){
    cout << num << endl;
}
