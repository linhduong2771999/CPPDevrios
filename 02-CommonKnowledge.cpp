// This file will contains important knowledge when learning C++
// Typically: common errors and bugs, how some specified function works...
// We separate into different files means specific knowledge are found at that lesson 


/************ Operators */
/*
    --------
    - + Pre-decremented (--num): the value of num is decremented first, then its value is used in an
    -expression.
    - + Post-decremented (num--): the value of num is used first, then its value is decremented in an
    -expression.
    -
    --------

    --------
    - Narrowing Conversion & Braces Initialization
    - + A narrowing conversion happens when you try to convert a larger type to a smaller type (or a 
    -type with less precision), and the value might not fit in the destination type
    -   - double d = 3.14;
    -   - int i = d; // Narrowing conversion: loss of decimal part
    -
    - + Some bad results of Narrowing Conversion:
    -   - Data Loss
    -   - Harder to debug: When narrowing conversions are allowed, it can be difficult to detect 
    -issues with data loss until runtime. This can lead to bugs that are hard to trace.
    -
    --------
*/

/************ Linking & Compiling */
/* (zoom out for easy reading)
    Great question! When you have files like main.cpp, account.cpp, and account.h, and you include account.h 
    in main.cpp, the compiler doesn't directly "know" about the existence of account.cpp when it processes 
    main.cpp. Here's how the build process works and how the compiler and linker handle it:

    1. Role of Header Files
    When you include account.h in main.cpp, you're telling the compiler that main.cpp will use the functions, 
    classes, or variables declared in account.h. The header file contains declarations (like function prototypes 
    or class definitions), which allows the compiler to check for proper usage in the source file (main.cpp).

    For example:

    cpp
    Copy code
    // account.h
    #ifndef ACCOUNT_H
    #define ACCOUNT_H

    class Account {
    public:
        void deposit(double amount);
        void withdraw(double amount);
    private:
        double balance;
    };

    #endif
    In main.cpp, you include account.h, and the compiler sees that Account is a class with certain functions, 
    but it doesn't know how these functions are implemented yet:

    cpp
    Copy code
    // main.cpp
    #include "account.h"

    int main() {
        Account myAccount;
        myAccount.deposit(100.0);
        myAccount.withdraw(50.0);
        return 0;
    }
    2. Compilation Process
    At this stage, the compiler only cares about the declarations in the header file. The compiler will check if 
    main.cpp correctly uses the Account class, and whether the functions deposit and withdraw are called properly. 
    However, it doesn't care yet about their implementations.

    The actual implementation of the functions (the code for deposit, withdraw, etc.) is found in account.cpp. The 
    compiler doesn't automatically know about account.cpp, because it only processes one source file at a time.

    3. Linking Process
    The key part is the linking step, which happens after all source files are compiled. The linker is responsible 
    for combining all the compiled object files (e.g., main.o, account.o) into a final executable.

    Here’s what happens:

    The compiler compiles main.cpp into an object file (main.o) using the declarations from account.h.
    The compiler also compiles account.cpp into another object file (account.o), which contains the definitions 
    (implementations) of the Account class functions.
    The linker then combines main.o and account.o to resolve any references to functions or variables. It links 
    the call to myAccount.deposit(100.0) in main.cpp to the actual definition of deposit in account.cpp.
    4. How the Linker Finds account.cpp
    In practice, the linker finds account.cpp because it is included in the build process. When you compile your 
    program (for example, using g++ or through a build system like make or CMake), you explicitly tell the compiler
    and linker which .cpp files to include.

    For example, when using a command like:

    bash
    Copy code
    g++ main.cpp account.cpp -o myProgram
    The compiler compiles main.cpp and account.cpp into object files (main.o and account.o).
    The linker then combines the object files into the final executable myProgram.
    If you're using a build system like make, the system will handle this for you by specifying which source files 
    to compile and link.

    In summary:
    The compiler knows about account.cpp because it's included in the build process (compiled separately and linked later).
    The linker resolves the references between the declarations in account.h (included in main.cpp) and the implementations 
    in account.cpp.
    You don't need to include account.cpp in main.cpp because account.h provides the necessary declarations, and the actual 
    linking happens during the linking stage when you compile and link both main.cpp and account.cpp.
    This separation ensures that your code is modular and can be compiled in parts, making the build process more efficient
    and manageable.

*/

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

    --------
    - link for more read: https://en.cppreference.com/w/cpp/language/string_literal
    - String literals can be used to initialize character arrays. If an array is initialized like char 
    -str[] = "foo";, str will contain a copy of the string "foo".
    -
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

    Return Value Optimization (RVO) & Copy Elision
    --------
    - When the compiler applies RVO, it constructs the returned object directly in the memory location of 
    the receiving variable (e.g., varus). This eliminates the need for:

    + Creating a temporary object for the return value.
    + Moving the temporary object to the target.
    - By skipping these steps, the compiler avoids both the construction and the move, leading to fewer 
    operations and faster execution.

    Without RVO:
    + Temporary Champion("Varus", 3000, 2) is created.
    + Champion::Champion(Champion &&) (move constructor) is called to transfer the temporary to varus.
    + Temporary is destroyed.
    With RVO:
    + Champion("Varus", 3000, 2) is constructed directly into varus's memory.
    + No move or temporary object destruction is needed.
*/

/************ OOP */
/*
    --------
    - Destructor, Copy Constructor, Copy Assignment Operator
    - There are two different way to do Deep Copy:
    -   + In Copy Constructor: Use for initialization object
    -   + In Copy Assignment Operator: Use when assign one already exited object to another object
    -
    --------

    --------
    - Rule of three
    -   + This rule basically states that if a class defines one (or more) of the following (destructor, 
    -copy constructor, copy assignment operator), it should explicitly define all three. 
    -   + link for more read: https://www.geeksforgeeks.org/rule-of-three-in-cpp/
    - 
    - Rule of Five
    -   + This rule ensure that the memory is properly handled i.e. memory allocation and deallocation 
    -is done properly and also resource management
    -   +  link for more read: https://www.geeksforgeeks.org/rule-of-five-in-cpp/
    --------
*/



/*
    Update 1: 6:27 pm December 2, 2024
        + Add OOP, Operator, Link & Compiling
*/ 

/*
    Update 1.1: 7:11 pm December 4, 2024
        + Update Strings & Characters: string literal vs char arr[]
        + Update Operator: Narrowing Conversion
*/ 

/*
    Update 1.2: 2:30 pm December 6, 2024
        + Update Pointers: RVO & Copy Elision
*/ 