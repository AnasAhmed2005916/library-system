#include "Book.h"
int Book::count = 0;
Book::Book()
{
	title = " ";
	isbn = " ";
	count++;
	id = count;
	category = " ";
	averagerating = 0.0;
	User author;   // calling the empty constructor in class User 
	numrates = 0;
	sumrates = 0.0;
}

Book::Book(string title, string isbn, string category)
{
	this->title = title;
	this->isbn = isbn;
	this->category = category;
	count++;
	id = count;
	averagerating = 0.0;
	User author;
	numrates = 0;
	sumrates = 0.0;
}

Book::Book(const Book& book)  // copy constructor 
{
	title = book.title;
	isbn = book.isbn;
	id = book.id;
	category = book.category;
	author = book.author;     // operator (=) overloading 
	averagerating = book.averagerating;
	numrates = book.numrates;
	sumrates = book.sumrates;
}

void Book::setTitle(string title)
{
	this->title = title;
}

string Book::getTitle() const
{
	return title;
}

void Book::setIsbn(string isbn)
{
	this->isbn = isbn;
}

string Book::getIsbn() const
{
	return isbn;
}

void Book::setId(int id)
{
	this->id = id;
}

int Book::getId() const
{
	return id;
}

void Book::setCategory(string category)
{
	this->category = category;
}

string Book::getCategory() const
{
	return category;
}

void Book::setAuthor(const User& user)     // operator(=) overloading 
{
	author = user;
}

User Book::getAuthor() const
{
	return author;
}

void Book::rateBook(double rating)
{
	if (rating > 0 && rating < 6)   // rating from 1 to 5 
	{
		numrates++;
		sumrates += rating;
	}
	averagerating = sumrates / numrates;
	condition = true;
}

double Book::getAverageRating() const
{
	if (condition == true)
	{
		return averagerating;
	}
	else
	{
		return 0;
	}
}

bool Book::operator==(const Book& book)
{
	return(title == book.title && isbn == book.isbn && id == book.id

		&& category == book.category && averagerating == book.averagerating

		&& author == book.author);   // if the condition true return true 
	// else return false 	

}

void Book::operator=(const Book& book)
{

	// User author;         // أنا عدلتها وأنا براجع 


	title = book.title;
	isbn = book.isbn;
	id = book.id;
	category = book.category;
	averagerating = book.averagerating;
	numrates = book.numrates;
	sumrates = book.sumrates;
	author = book.author;


}

void Book::display()
{
	

}


istream& operator>>(istream& input, Book& book)
{

	input >> book.title >> book.isbn >> book.category;
	return input;

}

ostream& operator<<(ostream& output, const Book& book)
{
	output << "============ Book " << book.id << "info============" << endl;
	output << " Title : " << book.title << endl;
	output << " isbn : " << book.isbn << endl;
	output << " id : " << book.id << endl;
	output << " category : " << book.category << endl;
	cout << " average rating : " << book.averagerating << endl;
	if (book.author.getName() != " ")
	{
		output << book.author << endl;
	}
	cout << " ========================================================= " << endl;
	return output;
}

