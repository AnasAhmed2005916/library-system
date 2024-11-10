#include "User.h"
#include "Book.h"
#include "UserList.h"
#include "BookList.h"
#include <iostream>
using namespace std;
int main()
{
	
	cout << " Welcome in the online library project : " << endl;
	cout << " ======================================= " << endl;
	string check1;
	cout << " Enter (yes || no ) if you want add number of users " << endl;
	cin >> check1;
	if (check1 == "yes")
	{
		cout << " Enter the number of users you want " << endl;
		int numofusers;
		cin >> numofusers;
		UserList arrayofusers(numofusers);
		cout << " Enter the users information : " << endl;
		for (int i = 0; i < numofusers; i++)
		{
			string n, p, e;
			int ag;
			cout << " Enter in this order (name => age => password => email) user " << i + 1 << endl;
			cin >> n >> ag >> p >> e;
			User user(n, ag, p, e);
			arrayofusers.addUser(user);
		}
		string check2;
		cout << " Enter (yes || no) if you want to add books : " << endl;
		cin >> check2;
		if (check2 == "yes")
		{
			int numofbooks;
			cout << " Enter the number of books you want :" << endl;
			cin >> numofbooks;
			BookList arrayofbooks(numofbooks);
			cout << " Enter the information of every book : " << endl;
			for (int i = 0; i < numofbooks; i++)
			{
				string t, c, is;

				cout << " Enter info of book" << i + 1 << " in this order (title = > isbn = > category) " << endl;
				cin >> t >> is >> c;
				Book book(t, is, c);
				cout << " Enter (yes || no) if you want add author of book number " << i + 1 << endl;
				string check3;
				cin >> check3;
				if (check3 == "yes")
				{
					int i_d;
					cout << " Enter the id of author you want add to book " << i + 1 << endl;
					cin >> i_d;
					User* author = arrayofusers.searchUser(i_d);
					if (author != nullptr)
					{
						book.setAuthor(*author);
					}
					else
					{
						cout << " The user you input not found " << endl;
					}

				}
				arrayofbooks.addBook(book);
			}
			string check4;
			cout << " Enter rate if you want to rate any book " << endl;
			cin >> check4;
			if (check4 == "rate")
			{
				int id;
				cout << " Enter the Id of the book you want to rate : " << endl;
				cin >> id;
				for (int i = 0; i < numofbooks; i++)
				{
					Book* ptr = arrayofbooks.searchBook(id);
					if (ptr != nullptr)
					{
						double rating;
						cout << " Enter the rate from 1 to 5 " << endl;
						cin >> rating;
						arrayofbooks[i].rateBook(rating);
						break;
					}
				}
				cout << arrayofbooks << endl;
			}
			
		}
		

	}
	else
	{
		return 0;
	}



	

	















}















