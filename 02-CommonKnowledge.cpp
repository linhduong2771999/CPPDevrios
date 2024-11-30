// This file will contains important knowledge when learning C++
// Typically: common errors and bugs, how some specified function works...
// We separate into different files means specific knowledge are found at that lesson 

/************ Arrays & Vectors */
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


/************ Strings & Characters */
/*
    --------
    - std:istream::getline() or cin.getline(char[], 50)
    - + Works with raw C-style string, header file <iostream> (Doesn't work with "String Object")
    - + Reads a line of input into a fixed-size character array (char[])
    - + cin.getline() read input from the stream until delimiter (\n newline or the user hit "enter")
    -
    - std::getline() or getline(cin, str)
    - + Works with "string object", header file <string>
    - + getline() read input from the stream until delimiter (\n newline or the user hit "enter")
    - + Designed for modern C++ and works with std::string, which provides dynamic memory management.
    --------

    --------
    - When you pass string literal(const char[]) to function has string object parameter
    -(string str). Compiler will create temporary string object (it is called implicit 
    - conversion) holds the text of string literal.
    -
    - The compiler can convert from literal to object but not from object to literal
    --------

    --------
    - If you use cin before getline
    - it will leave \n in the buffer
    - getline will read what leftover on the buffer (in this case, it read \n as the 
    first character and skip the user input)
    - use cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' ); from the <limits> library
    --------

*/

/************ Function */
/*
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

/************ Pointers */

/*
    --------
    - Arithmetic
    - *arr_ptr_num++ => This code execute: dereference first, then increment
    -
    - + const int *score_ptr = {&score} (a score pointer that point to constant int value)
    - + int *const score_ptr = {&score} (a constant score pointer that point to int value)
    - + const int *const score_ptr = {&score} (a constant score pointer that point to constant int value)
    --------

    --------
    - r-value & l-value
    - l-value: 
    - + Have name and addressable  
    - + Modifiable if they are not constants
    - r-value:
    - + Non-addressable and non-assignable
    - + A literal numbers, texts, strings...
    - + A temporary which is intended to be non-modifiable
    --------
*/