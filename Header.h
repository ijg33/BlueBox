#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

class Movie 
{
	//access specifier
public:

	Movie(); //default constructor
	Movie(string title, int year, string genre, bool status); //overloaded constructor
	~Movie();//destructor

	 //accessor functions
	string getName() const;
	int getYear() const;
	string getGenre() const;
	void setRented(bool option_4);
	bool getStatus()const;

private:

	//member variables
	string title, genre;
	int year;
	bool rented;
};
class Account 
{
public:
	Account();
	Account(string, int, double);
	~Account();

	string setUser(string);
	string getUser() const;
	int getID() const;
	void setBalance(int);
	double getBalance();

private:
	string name;
	int ID = 249205;
	double balance = 100.00;
	string newUser;
	double newBalance;
};