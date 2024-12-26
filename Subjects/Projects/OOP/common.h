#ifndef COMMON_H_
#define COMMON_H_
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// helpers
 

// For displaying interface
void home();
void guest_shopping();

// For constructing interface
void cut_line();
void clear_buffer();
void display_text(const string &text, bool isEndl);
void display_banner(const string &heading);


#endif