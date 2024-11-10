#pragma once
#include <iostream>
using namespace std;
class User
{
private:
    string name;
    int age;
    int id;
    string password;
    string email;
public:
    static int count;  // the same data member for any object 
    User();
    User(string, int, string, string);   // constructor overloading 
    User(const User&);
    bool operator==(const User&);
    void setName(string);
    string getName() const;
    void setPassword(string);
    string getPassword()const;
    void setEmail(string);
    string getEmail()const;
    void setAge(int);
    int getAge() const;
    void setId(int);
    int getId() const;
    void operator=(const User&);
    void Display();
    friend ostream& operator<<(ostream&, const User&);  // function from class ostream => cout 
    friend istream& operator>>(istream&, User&);        // function from class istream => cin
};
