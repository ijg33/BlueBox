#include "Header.h"
#include <cmath>

using namespace std;

/* BlueBOX ver 0.03

BlueBOX is a project that got its inspiration from a recent final exam of mine 
this past semester. The task was to work with a team towards the development of 
a C++ console application. The design was in reference to a provided example, similar 
to the Redbox rental system. Below is my iteration of the project; it is far 
from done, although I think you could be insightful about my experience. Thanks!

-Isaiah Gaspar

*/



int main()
{
	system("color 1F");
	cout << setiosflags(ios::fixed) << setprecision(2);

	string name;
	
	int i = 0;
	int option_1 = NULL, option_2 = NULL, option_3 = NULL, option_4 = NULL;

	// movie objects
	Movie movie1("Guardians of the Galaxy", 2014, "Action/Sci-Fi     ",false);
	Movie movie2("Star Wars: The Force Awakens", 2015, "Action/Fantasy    ",false);
	Movie movie3("Zootopia", 2016, "Anime/Action      ",false);
	Movie movie4("Interstellar", 2014, "Adveture/Sci-Fi   ",false);
	Movie movie5("Alien", 1979, "Horror/Sci-Fi     ",false);
	Movie movie6("The Martian", 2015, "Action/Sci-Fi     ",false);
	Movie movie7("Star Trek Into Darkness", 2013, "Action/Adventure  ",false);
	Movie movie8("Back to the Future", 1985, "Comedy/Sci-Fi     ",false);
	Movie movie9("Jurassic Park", 1996, "Adventure/Thriller",false);
	Movie movie10("Warcraft", 2016, "Action/Fantasy    ",false);

	//array of movie data
	Movie inventory[10] = { movie1, movie2, movie3, movie4, movie5, movie6,
		movie7, movie8, movie9, movie10 };

	//intro and sign in to input userName
	cout << "Welcome to BlueBOX!\n" << "Username: ";
	cin >> name;

	//Update Account with userName, ID number,and starting balance of $100.00
	Account name1(name, 249205, 100.00);

	//table display

	cout << setfill('~') << setw(73) << "" << endl << setfill(' ');
	cout << left << setw(37) << "Name" << "Genre" << right << setw(31) << "Year Produced" << endl;
	cout << setfill('~') << setw(73) << "" << endl << setfill(' ');

	for (int i = 0; i < 10; i++) 
		{
			cout << right << setw(2) << i + 1 << ".)" << setw(2)
				<< "" << left << setw(31) << inventory[i].getName()
				<< inventory[i].getGenre() << left << setw(5) << "" << inventory[i].getYear() << endl;
		}

	cout << setfill('~') << setw(73) << "" << endl << setfill(' ');
	 


	while (option_1 != 4) 
	{
				
		//user options
				cout << "\nWhat would you like to do, " << name1.getUser() << "?";

				cout << "\n\n0.)Show Movies\n1.)Rent\n2.)Return\n3.)Check Account\n4.)Sign-Out\n" << "\nOption(0-4): ";

				cin >> option_1;

			

				switch (option_1) {
				case 0://redisplay inventory

					cout << setfill('~') << setw(73) << "" << endl << setfill(' ');
					cout << left << setw(37) << "Name" << "Genre" << right << setw(31) << "Year Produced" << endl;
					cout << setfill('~') << setw(73) << "" << endl << setfill(' ');

					for (int i = 0; i < 10; i++)
					{
						cout << right << setw(2) << i + 1 << ".)" << setw(2)
							<< "" << left << setw(31) << inventory[i].getName()
							<< inventory[i].getGenre() << left << setw(5) << "" << inventory[i].getYear() << endl;
					}

					cout << setfill('~') << setw(73) << "" << endl << setfill(' ');

					break;
				case 1://rent a movie+-

					if (name1.getBalance() <= 0)
					{
						cout << "Insufficient Funds\n";
					}
					else
					{
						cout << "Which movie would you like to rent (1-10)? ";
						cin >> option_2;
						while (option_2 < 0 || option_2 > 11)
						{
							cout << setfill('~') << setw(73) << "" << endl << setfill(' ');
							cout << "Movie not available, try again: ";
							cin >> option_2;
						}
						if (inventory[option_2 - 1].getStatus() == true)
						{
							cout << setfill('~') << setw(73) << "" << endl << setfill(' ');//line border
							cout << "\nThis movie is not available\n";
						}
						else
						{
							cout << setfill('~') << setw(73) << "" << endl << setfill(' ');
							inventory[option_2 - 1].setRented(true);
							cout << "\nYou rented: " << inventory[option_2 - 1].getName();
						}
						cout << "\n\nThank you!" << endl;
					}

					cout << setfill('~') << setw(73) << "" << endl << setfill(' ') << endl;
					break;

				case 2://return a movie and set newbalance
					cout << "Enter movie to return (0 to see your movies): ";
					cin >> option_3;
					while (option_3 < 0 || option_3 > 11)
						{
							cout << "Movie not available, try again: ";
							cin >> option_3;
						}

					if (inventory[option_3 - 1].getStatus() == false)
						{
							cout << setfill('~') << setw(73) << "" << endl << setfill(' ');//line border
							cout << "You have not rented that movie\n";
						}
					else 
						{
							if (option_3 == 0)
								{
									cout << setfill('~') << setw(73) << "" << endl << setfill(' ');//line border
									for (int i = 0; i < 10; i++)

										if (inventory[i].getStatus() == true)
										{
											cout << endl << i + 1 << ".) " << inventory[i].getName() << endl;
										}

									cout << setfill('~') << setw(73) << "" << endl << setfill(' ');//line border

									cout << "Enter movie to return (0 to see your movies): ";
									cin >> option_3;
								}

							if (inventory[option_3 - 1].getStatus() == true)
								{	//set the movie as returned
									inventory[option_3 - 1].setRented(false);
									//determine days the movie was rented
									cout << "How many days has the movie been rented for? ";
									cin >> option_4;
									//charge and set balance
									name1.setBalance(option_4);
									cout << setfill('~') << setw(73) << "" << endl << setfill(' ');
									cout << "\nYour balance is $" << name1.getBalance() << endl;
									cout << "You have successfully returned: " << inventory[option_3 - 1].getName() << endl;
								}
							}
					cout << setfill('~') << setw(73) << "" << endl << setfill(' ') << endl;//line border
					break;
		case 3://check account

					cout << setfill('~') << setw(73) << "" << endl << setfill(' ');//line border
					cout << name1.getUser() << " (ID: " << name1.getID() << ") " << " is renting:\n";
					
					//movie check
						for (int i = 0; i < 10; i++) 
						{
							if (inventory[i].getStatus() == true ) 
							{
								cout <<endl << i+1 << ".) " <<inventory[i].getName();
							}
						}
			
						cout << "\n\nYour balance is: $" << name1.getBalance() << endl;
			
					cout << setfill('~') << setw(73) << "" << endl << setfill(' ') << endl;
					break;
		case 4://sign out

					break;
		default:
			cout << "Error 404 - option '"  << option_1 << "' not found!\n";
		
						}
					}

	

	return 0;
}