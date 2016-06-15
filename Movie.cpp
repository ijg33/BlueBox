#include "Header.h"

using namespace std;

//defiintions

Movie::Movie()
{
	int year = 0;
}

Movie::Movie(string newTitle, int newYear, string newGenre, bool status)
{
	title = newTitle;
	genre = newGenre;
	year = newYear;
}

Movie::~Movie()
{

}

string Movie::getName() const
{
	return title;
};

int Movie::getYear() const
{
	return year;
};

string Movie::getGenre() const
{
	return genre;
};
void Movie::setRented(bool option)
{
	rented = option;
};
bool Movie::getStatus()const
{
	return rented;
};