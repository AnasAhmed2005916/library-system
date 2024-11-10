#include "BookList.h"
#include <iostream>
#include "Book.h"
using namespace std;

BookList::BookList()
{
	capacity = 0;
	booksCount = 0;
}

BookList::BookList(int capacity)
{
	this->capacity = capacity;
	books = new Book[capacity];      // dynamic allocation          // array books 
	booksCount = 0;

}

void BookList::addBook(const Book& book)
{
	if (booksCount < capacity)
	{
		books[booksCount] = book;
		books[booksCount].setId(booksCount + 1);
		booksCount++;
	}
	else
	{
		cout << " the array of books is filled " << endl;
	}
}

Book* BookList::searchBook(string title)
{
	for (int i = 0; i < booksCount; i++)
	{
		if (books[i].getTitle() == title)
		{
			return &books[i];
			break;
		}
	}
	return nullptr;

}

Book* BookList::searchBook(int id)
{
	for (int i = 0; i < booksCount; i++)
	{
		if (books[i].getId() == id)
		{
			return &books[i];
			break;
		}
	}
	return nullptr;

}

void BookList::deleteBook(int id)
{
	for (int i = 0; i < booksCount; i++)
	{
		if (books[i].getId() == id)
		{
			while (i < booksCount - 1)
			{
				books[i] = books[i + 1];
				books[i].setId(i + 1);
				i++;
			}
			booksCount--;
			capacity--;
			break;
		}
	}
}

Book BookList::getTheHighestRatedBook()    // the heighst rating 
{
	double Heighest_Rate = -10.0;           // the rate from 1 to 6 
	int index = 0;
	for (int i = 0; i < booksCount; i++)
	{
		// return the first book if 2 book are equal 
		if (books[i].getAverageRating() > Heighest_Rate)
		{
			Heighest_Rate = books[i].getAverageRating();
			index = i;
		}
	}
	return books[index];             // return the heighst rate 
}

void BookList::getBooksForUser(const User& user)
{
	// if more than one book has the same author 
	bool found = false;
	for (int i = 0; i < booksCount; i++)
	{
		if (books[i].getAuthor() == user)  // operator(==)overloading  
		{
			found = true;
			cout << books[i] << endl;
		}
	}
	if (!found)    // !found => found=false
	{
		cout << " no book has author that you input ! " << endl;

	}


}

Book& BookList::operator[](int position)     // return the reference value 
{
	// deal with object of class booklist as an array of class book => b1[0]
	bool cond = false;
	if (position < 0 || position >= booksCount)
	{
		cond = true;
		cout << " position Error " << endl;
	}
	if (cond == false)
	{
		return books[position];
	}
}

BookList::~BookList()
{
	delete[] books;
}

ostream& operator<<(ostream& output, const BookList& booklist)
{
	for (int i = 0; i < booklist.booksCount; i++)
	{
		output << booklist.books[i] << endl;
	}
	return output;
}
