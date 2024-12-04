#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

/*
    --------
    - + Operator cannot be overloaded: ::, :?, .*, ., sizeof
    -
    --------

    --------
    - Overload (Copy assignment)
    - + If you dont create your own assignment operator. Compiler will do a default 
    -for you, but it will do a shallow copy.
    - + Write your own assignment operator when you want a deep copy.
    - - Steps to do:
    -       + The AO must be overloaded as a member function (Type &Type::operator=(const Type &rhs))
    --------

    --------
    - Overload (Move assignment)
    - + If you dont create your own move assignment operator. Compiler will do a default 
    -copy assignment by default.
    - - Steps to do:
    -       + The AO must be overloaded as a member function (Type &Type::operator=(Type &&rhs))
    --------

    --------
    - + When you have overloaded Mystring::operator=(const MyString &rhs)
    -   - And you do: MyString nguyen = "asd"; You are try to pass "string literal" to the parameter
    -Mystring object
    -   - The Compiler will do a "implicit conversion" to convert "asd" to an temporary MyString Object 
    -if you have the appropriate Constructor which is MyString::MyString(const char *str)
    -   - Once the temporary MyString object is created, the compiler uses your copy assignment operator 
    -(operator=(const MyString &rhs)) to assign the temporary MyString object to nguyen.
    - 
    - + If you dont want your compiler do the implicit conversion, you should define two specify overloaded
    -assignment operator
    -   - MyString &MyString::operator=(const MyString &rhs)
    -   - MyString &MyString::operator=(const char *str)
    --------
*/

class MyString{
    private:
    char *str;

    public:
    MyString();
    MyString(const char *s);
    MyString(const MyString &source);
    MyString &operator=(const MyString &rhs);

    MyString(MyString &&rhs);
    MyString &operator=(MyString &&rhs);
    MyString &operator=(const char *s);

    friend MyString operator-(const MyString &lhs);
    friend ostream &operator<<(ostream &os,const MyString &lhs);
    friend istream &operator>>(istream &is, MyString &lhs);
    MyString operator+(const MyString &rhs) const;
    MyString operator+(const char *s) const;
    bool operator==(const MyString &rhs) const;
    bool operator==(const char *s) const;

    void display_string() const;
    ~MyString();
};

MyString::MyString()
: str{nullptr} {
    str = new char[1];
    *str = '\0';
    cout << "Constructor called" << endl;
}

MyString::MyString(const char *s)
: str{nullptr} {
    if (s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    cout << "Parameter Constructor called" << endl;
}

MyString::MyString(const MyString &source)
: str{nullptr} {
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
    cout << "Copy Constructor called" << endl;
}

MyString &MyString::operator=(const MyString &rhs){
    if (this == &rhs)
    {
        return *this; 
    } 

    delete [] this->str;
    this->str = new char[strlen(rhs.str) + 1];
    strcpy(this-> str, rhs.str);
    cout << "Copy Assignment Operator called" << endl;
    return *this;
}

MyString &MyString::operator=(const char *s){
    if (strcmp(this->str, s) == 0)
    {
        return *this;
    }
    delete [] this->str;
    this->str = new char[strlen(s) + 1];
    strcpy(this->str, s);
    cout << "Copy Assignment Operator on char called" << endl;
    
    return *this;
}

MyString::MyString(MyString &&rhs)
: str{rhs.str} {
    rhs.str = nullptr;
    cout << "Move Constructor called" << endl;
}

MyString &MyString::operator=(MyString &&rhs){
    if (this == &rhs)
    {
        return *this;
    }

    delete [] str; 
    this->str = rhs.str;
    rhs.str = nullptr;
    cout << "Move Assignment Operator called" << endl;
    return *this;
}

MyString MyString::operator+(const MyString &rhs) const{
    char *temp_ptr = new char[strlen(this->str) + strlen(rhs.str) + 1];
    strcpy(temp_ptr, this->str);
    strcat(temp_ptr, rhs.str);

    MyString temp_obj {temp_ptr};
    delete [] temp_ptr;

    return temp_obj;
}

MyString MyString::operator+(const char *s) const{
    char *temp_ptr = new char[strlen(this->str) + strlen(s) + 1];
    strcpy(temp_ptr, this->str);
    strcat(temp_ptr, s);

    MyString temp_obj {temp_ptr};
    delete [] temp_ptr; 
    return temp_obj;
}

MyString::~MyString(){
    delete [] str;
}

bool MyString::operator==(const MyString &rhs) const{
    cout << "Operator == object" << endl;
    return (strcmp(this->str, rhs.str) == 0);
}

bool MyString::operator==(const char *s) const{
    cout << "Operator == char" << endl;
    return (strcmp(this->str, s) == 0);
}

MyString operator-(const MyString &lhs){
    char *ptr = new char[strlen(lhs.str) + 1];
    strcpy(ptr, lhs.str);

    for (size_t i = 0; i < strlen(ptr); i++)
    {
        ptr[i] = towupper(ptr[i]);
    }
    MyString temp_obj {ptr};
    delete [] ptr;

    return temp_obj;
}

ostream &operator<<(ostream &os,const MyString &lhs){
    os << lhs.str;
    return os;
}

istream &operator>>(istream &is, MyString &lhs){
    char *ptr = new char[1000];
    is >> ptr;

    lhs = MyString {ptr};
    delete ptr;

    return is;
}

void MyString::display_string() const {
    cout << str << endl;
}

int main(){

    MyString nguyen {"Nguyen "}; // overloaded cons
    MyString linh {"Linh "}; // overloaded cons
    MyString duong = nguyen + linh;
    duong = duong + "Duong";

    MyString full_name {"Nguyen Linh Duong"};
    full_name = -duong;
    full_name.display_string();

    MyString another_name;
    another_name = nguyen = linh;
    // another_name.display_string();
    // nguyen.display_string();
    // MyString dinh("dinh"); // parameter cons

    // nguyen = dinh; // copy assign operator  
    // dinh = MyString("linh"); // move assign operator
    cout << another_name << endl;
    cin >> another_name;
    cout << another_name << endl;


    // nguyen.display_string();
    // dinh.display_string();


    return 0;
}