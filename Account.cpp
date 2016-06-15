#include "Header.h"
#include <cmath>

using namespace std;

Account::Account() {
	int ID = 0;
	float balance = 0.00;
};

Account::Account(string name, int ID, double balance) {
	newUser = name;
};
Account::~Account() {

};
string Account::getUser() const {
	return newUser;
}
string Account::setUser(string newUser) {
	newUser = name;
	return 0;
}
int Account::getID() const {
	return ID;
}
void Account::setBalance(int option_4) {
	int amountCharged;

	while (option_4 <= 0.00)
	{
		cout << "Error: Try again: ";
		cin >> option_4;
	}

		if (option_4 <= 10.00 && option_4 > 0.00)
		{
			amountCharged = (option_4)*(.50);
		}
		else if (option_4 > 10.00 && option_4 < 20.00)
		{
			amountCharged = (option_4)-5.00;
		}
		else
		{
			amountCharged = 15.00;
		};
	
	newBalance = Account::getBalance() - amountCharged;
	balance = newBalance;
}
double Account::getBalance() {
	return balance;
}