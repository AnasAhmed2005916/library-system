#pragma once
#include <iostream>
#include "User.h"
using namespace std;
class Book    // Book has a User ==> aggregation 
{
	string title;
	string isbn;
	int id;
	string category;
	double averagerating;
	User author;
	int numrates;
	double sumrates;
	bool condition = false;
public:
	static int count;
	Book();
	Book(string, string, string);
	Book(const Book&);
	void setTitle(string);
	string getTitle() const;
	void setIsbn(string);
	string getIsbn() const;
	void setId(int);
	int getId() const;
	void setCategory(string);
	string getCategory() const;
	void setAuthor(const User&);
	User getAuthor() const;
	void rateBook(double);
	double getAverageRating() const;
	bool operator== (const Book&);
	void operator= (const Book&);
	void display();
	friend ostream& operator<<(ostream&, const Book&);
	friend istream& operator>>(istream&, Book&);








};
