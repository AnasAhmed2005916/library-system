#include "User.h"
#include <iostream>
using namespace std;
int User::count = 0;  // initialize the counter(static member)
User::User()
{
	name = " ";
	age = 0;
	password = " ";
	email = " ";
	count++;
	id = count;
}
User::User(string name, int age, string password, string email)
{
	this->name = name;   // this->private member of the class = parameter of the constructor  
	this->age = age;
	this->password = password;
	this->email = email;
	count++;
	id = count;
}
User::User(const User& user)  // copy constructor 
{
	name = user.name;
	age = user.age;
	password = user.password;
	email = user.email;
	id = user.id;
}
// ---------------------------------------------------------
void User::setName(string n)    // setters and getters 
{
	name = n;
}
string User::getName() const
{
	return name;
}

void User::setPassword(string p)
{
	password = p;
}

string User::getPassword() const
{
	return password;
}

void User::setEmail(string e)
{
	email = e;
}

string User::getEmail() const
{
	return email;
}

void User::setAge(int a)
{
	age = a;
}

int User::getAge() const
{
	return age;
}

void User::setId(int id)
{
	this->id = id;
}

int User::getId() const
{
	return id;
}
void User::operator=(const User& user)    // operator (=) overloading 
{
	name = user.name;
	age = user.age;
	email = user.email;
	password = user.password;
	id = user.id;
}
void User::Display()
{
	cout << "************************************** " << endl;
	cout << " Email : " << email << endl;
	cout << " Name : " << name << endl;
	cout << " Age : " << age << endl;
	cout << " Id : " << id << endl;
	cout << "************************************** " << endl;

}
// ---------------------------------------------------------
bool User::operator==(const User& user)
{
	/* two objects are considered equal if they have
		the same email & name & age & id & password
	*/
	if (email == user.email && name == user.name &&
		age == user.age && password == user.password
		&& id == user.id
		)
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream& operator<<(ostream& output, const User& user)
{
	output << "============ User" << user.id << " info ==============" << endl;
	output << " Name : " << user.name << endl;
	output << " Age : " << user.age << endl;
	output << " id : " << user.id << endl;
	output << " Email : " << user.email << endl;
	output << " ======================================================= " << endl;
	return output;
}
istream& operator>>(istream& input, User& user)
{
	// cin>>user.name   ==> (cin = input)
	input >> user.name >> user.age >> user.email >> user.password;
	return input;
}

