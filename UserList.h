#pragma once
#include <iostream>
#include "User.h"
using namespace std;
class UserList       // an array of class user 
{
	User* users;     // a pointer of class User
	int capacity;
	int usersCount;
public:
	UserList();
	UserList(int);
	void addUser(const User&);
	User* searchUser(string);
	User* searchUser(int);
	void DeleteUser(int);
	User& operator[](int);
	friend ostream& operator<<(ostream&, const UserList&);
	~UserList();







};


