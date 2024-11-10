#include "UserList.h"
#include <iostream>
using namespace std;

UserList::UserList()
{
	capacity = 0;
	usersCount = 0;
	// initialize the capacity and userscount for any object 
	// userscount => the number of items allready 
	// capacity => the size of array totally 
}

UserList::UserList(int capacity)        // users is array of class user
{
	this->capacity = capacity;
	users = new User[capacity];  // make an array of user && ( size of array = capacity )
	usersCount = 0;	              // the number of users allready 			
}

void UserList::addUser(const User& user)   // adding new user from class user 
{
	if (usersCount < capacity)
	{
		users[usersCount] = user;
		users[usersCount].setId(usersCount + 1);  // u1 id:1
		usersCount++;
	}
	else
	{
		cout << " the array is filled allready " << endl;
	}

}

User* UserList::searchUser(string name)       // search for user by name 
{
	for (int i = 0; i < usersCount; i++)
	{
		if (users[i].getName() == name)
		{
			return &users[i];    // the function return a pointer 
		}
	}
	return nullptr;
}
User* UserList::searchUser(int id)        // search for user by id 
{
	for (int i = 0; i < usersCount; i++)
	{
		if (users[i].getId() == id)
		{
			return &users[i];
		}
	}
	return nullptr;
}

void UserList::DeleteUser(int id)
{
	for (int i = 0; i < usersCount; i++)
	{
		if (users[i].getId() == id)
		{
			while (i < usersCount - 1)     // userscount - 1 => The penultimate element
			{
				users[i] = users[i + 1];
				users[i].setId(i + 1);
				i++;
			}
			usersCount--;
			capacity--;
			break;
		}
	}
}





User& UserList::operator[](int position)
{
	bool cond = true;
	if (position > 0 || position >= usersCount)
	{
		cond = false;
		cout << " position error " << endl;
	}
	if (cond == true)
	{
		return users[position];
	}


}





UserList::~UserList()
{
	delete[] users;

}

ostream& operator<<(ostream& output, const UserList& userlist)
{
	for (int i = 0; i < userlist.usersCount; i++)
	{
		output << userlist.users[i];
	}
	return output;
}
