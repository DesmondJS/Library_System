#include<iostream>
#include<iomanip>
#include<cmath>
#include<cctype>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;

void showOptions(string& ADMIN_name)
{
	system("cls");
	cout << "Welcome back admin " << ADMIN_name << " !\nWhat would you like to do today?\n" << endl;
	cout << "*************************************************" << endl;
	cout << " _____  _____  _____  _____  _____  _____  _____ " << endl;
	cout << "|     ||  _  ||_   _||     ||     ||   | ||   __|" << endl;
	cout << "|  |  ||   __|  | |  |-   -||  |  || | | ||__   |" << endl;
	cout << "|_____||__|     |_|  |_____||_____||_|___||_____|" << endl;
	cout << "*************************************************" << endl;
	cout << "*1. SEARCH BOOKS                                *" << endl;
	cout << "*2. VIEW BOOKS                                  *" << endl;
	cout << "*3. ADD BOOKS                                   *" << endl;
	cout << "*4. DELETE BOOKS                                *" << endl;
	cout << "*5. LOGOUT                                      *" << endl;
	cout << "*************************************************" << endl;
}

void view_books()
{
	system("cls");
	cout << "*****************************************************************************************************" << endl;
	cout << " _   _   _____   _____   _    _     _____   _____   _____   _   __    _       _____   _____   _____  " << endl;
	cout << "| | | | |_   _| |  ___| | |  | |   | ___ | |  _  | |  _  | | | / /   | |     |_   _| /  ___| |_   _| " << endl;
	cout << "| | | |   | |   | |__   | |  | |   | |_/ / | | | | | | | | | |/ /    | |       | |   | `--.    | |   " << endl;
	cout << "| | | |   | |   |  __|  | |/|| |   | ___ | | | | | | | | | |    |    | |       | |    `--. |   | |   " << endl;
	cout << "| |_/ /  _| |_  | |___  |  /|  /   | |_/ / | |_/ / | |_/ / | ||  |   | |____  _| |_  /|__/ /   | |   " << endl;
	cout << "|____/   |___/  |____/  |/  |/     |____/  |___ /  |___ /  |_| |_/   |_____/  |___/  |____/    |_/   " << endl;
	cout << "*****************************************************************************************************" << endl;
}

int main()
{
	char login;
	int noADMIN = 0, noBOOKS = 0; //Initialize counter to 0
	bool loginSuccessful = false;
	string ADMIN_name, NAME_check;
	string ADMIN_pass, PASS_check;
	string BOOK_name,BOOK_check;
	string BOOKadd, BOOKdel;
	ifstream inFile;
	ofstream outFile;
	ofstream temp;

	do
	{
		cout << "***********************************************************************" << endl;
		cout << " _ _ _       _                          _                              " << endl;
		cout << "| | | | ___ | | ___  ___  _____  ___   | |_  ___                       " << endl;
		cout << "| | | || -_|| ||  _|| . ||     || -_|  |  _|| . |                      " << endl;
		cout << "|_____||___||_||___||___||_|_|_||___|  |_|  |___|                      " << endl;
		cout << " _____  _____  _____  _____  _____  _____  _____  _____  _____         " << endl;
		cout << "|  _  ||     || __  ||  _  ||_   _||  |  || __  ||  |  ||   __|        " << endl;
		cout << "|     || | | || __ -||     |  | |  |  |  || __ -||  |  ||__   |        " << endl;
		cout << "|__|__||_|_|_||_____||__|__|  |_|  |_____||_____||_____||_____|        " << endl;
		cout << " __     _  _                          _____            _               " << endl;
		cout << "|  |   |_|| |_  ___  ___  ___  _ _   |   __| _ _  ___ | |_  ___  _____ " << endl;
		cout << "|  |__ | || . ||  _|| .'||  _|| | |  |__   || | ||_ -||  _|| -_||     |" << endl;
		cout << "|_____||_||___||_|  |__,||_|  |_  |  |_____||_  ||___||_|  |___||_|_|_|" << endl;
		cout << "                              |___|         |___|                      " << endl;
		cout << "***********************************************************************" << endl;

		cout <<
			"Login\n\n";
		cout <<
			"1. Administrator\n\n";
		cout <<
			"2. Member\n\n";
		cout <<
			"***********************************************************************\n" << endl;
		cout <<
			"Please choose login method: ";
		cin >> login;
		cout << endl;

		if (login != '1' && login != '2')
		{
			cout << "---------------------------------------------------------" << endl;
			cout << "Please enter a required number according to the menu!" << endl;
			cout << "---------------------------------------------------------" << endl;
		}
	} while (login != '1' && login != '2'); //To loop again if there is error

	if (login == '1')
	{
		while (!loginSuccessful)
		{
			inFile.open("ADMIN.txt"); //Call Admin List file out
			if (inFile.fail())
			{
				cout << "Error opening file" << endl;
				exit(1);
			}

			cout <<
				"********************************************\n";
			cout << "\nUsername: ";
			cin.clear();
			getline(cin >> std::ws, ADMIN_name);//discard whitespace char before reading input 
			cout << endl;
			cout << "\nPassword: ";
			getline(cin >> std::ws, ADMIN_pass);
			cout << endl;
			cout << "\n********************************************\n";


			while (getline(inFile, NAME_check) && inFile >> PASS_check)//check every line of the ADMIN.txt with input
			{
				noADMIN++;
				if (ADMIN_name == NAME_check && ADMIN_pass == PASS_check)
				{
					loginSuccessful = true;
					break; //Exit the while loop if correct info 
				}
				inFile.ignore(); //discard any leftover characters in the input buffer
			}
			if (noADMIN == 0 || ADMIN_name != NAME_check || ADMIN_pass != PASS_check)
			{
				cout << "Invalid username or password!" << endl;
				loginSuccessful = false;
			}
			inFile.close(); //Close txt file
		}

		char options;
		do
		{
			showOptions(ADMIN_name);

			cout << "Please enter options: ";
			cin >> options;
			cout << endl;

			if (options != '1' && options != '2' && options != '3' && options != '4' && options != '5')
			{
				cout << "Please chooose an available options!" << endl;
				system("pause");
			}

			else if (options == '1')
			{
				inFile.open("BookList.txt");
				if (!inFile.is_open())
				{
					cout << "Error opening file" << endl;
					system("pause");
				}
				char choice;
				do
				{
					system("cls");
					cout << "********************************************************************************" << endl;
					cout << " _____  _____  _____  _____  _____  _____    _____  _____  _____  _____  _____ " << endl;
					cout << "|   __||   __||  _  || __  ||     ||  |  |  | __  ||     ||     ||  |  ||   __|" << endl;
					cout << "|__   ||   __||     ||    -||   --||     |  | __ -||  |  ||  |  ||    -||__   |" << endl;
					cout << "|_____||_____||__|__||__|__||_____||__|__|  |_____||_____||_____||__|__||_____|" << endl;
					cout << "********************************************************************************" << endl;
					bool foundBOOK = false;
					cout << "What book would you like to search for?" << endl;
					cout << "Enter book name : ";
					cin.ignore();//discard the newline character left in the input buffer
					getline(cin >> std::ws, BOOK_name);
					cout << endl;

					inFile.seekg(0, ios::beg); //reset file pointer to beginning of file
					while (getline(inFile,BOOK_check))//check every books registered in the system
					{
						if (BOOK_name==BOOK_check)
						{
							cout << "The book: " << BOOK_name << " is registered in the libray system." << endl;
							foundBOOK = true;
							break;
						}
					}
					if (!foundBOOK)//return false if there is no such books in system
					{
						cout << "The book: " << BOOK_name << " is not registered in the library system." << endl;
					}
					
					cout << "\nContinue searching? (y/n): " << endl;//prompt for continue search or no
					cin >> choice;

					while (tolower(choice) != 'y' && tolower(choice) != 'n')//to validate value
					{
						cout << "Please enter y or n: " << endl;
						cin >> choice;
					}

					if (tolower(choice) == 'n')
					{
						break;
					}

				} while (tolower(choice) == 'y');//loop if yes
				inFile.close();
			}
			else if (options == '2')
			{
				view_books(); //call function for view books options
				inFile.open("BookList.txt");
				if (!inFile.is_open())
				{
					cout << "Error opening file" << endl;
					system("pause");
				}
				string line;
				while (!inFile.eof())
				{
					int x = 0;
					while (getline(inFile, line))
					{
						cout << x + 1 << ". " << line << endl;
						x++;
					}
				}
				inFile.close();
				cout << "\n**********************************************" << endl;
				cout << "Press Enter to return to Options Menu. " << endl;
				system("pause");
			}
			else if (options == '3')
			{
				char choice;
				do
				{
					system("cls");
					cout << "**********************************************************" << endl;
					cout << " _____  ____   ____     _____  _____  _____  _____  _____ " << endl;
					cout << "|  _  ||    \ |    \   | __  ||     ||     ||  |  ||   __|" << endl;
					cout << "|     ||  |  ||  |  |  | __ -||  |  ||  |  ||    -||__   |" << endl;
					cout << "|__|__||____/ |____/   |_____||_____||_____||__|__||_____|" << endl;
					cout << "**********************************************************" << endl;
					outFile.open("BookList.txt", ios_base::app);
					if (!outFile.is_open())
					{
						cout << "Error: failed to open file for appending" << endl;
						system("pause");
					}
					cout << "What books would you like to add into the system: ";
					cin.ignore();
					getline(cin, BOOKadd);
					cout << endl;

					outFile <<BOOKadd << endl;
					cout << "Book successfully added to the library system. " << endl;
					outFile.close();

					cout << "\nContinue adding? (y/n): " << endl;//prompt for continue search or no
					cin >> choice;

					while (tolower(choice) != 'y' && tolower(choice) != 'n')//to validate value
					{
						cout << "Please enter y or n: " << endl;
						cin >> choice;
					}

					if (tolower(choice) == 'n')
					{
						break;
					}
				} while (tolower(choice) == 'y');
			}
			else if (options == '4')
			{
				char choice;
				do
				{
					system("cls");
					cout << "*******************************************************************************" << endl;
					cout << " ____   _____  __     _____  _____  _____    _____  _____  _____  _____  _____ " << endl;
					cout << "|    \ |   __||  |   |   __||_   _||   __|  | __  ||     ||     ||  |  ||   __|" << endl;
					cout << "|  |  ||   __||  |__ |   __|  | |  |   __|  | __ -||  |  ||  |  ||    -||__   |" << endl;
					cout << "|____/ |_____||_____||_____|  |_|  |_____|  |_____||_____||_____||__|__||_____|" << endl;
					cout << "*******************************************************************************" << endl;
					inFile.open("BookList.txt");
					temp.open("temp.txt");
					string line;
					string bookToDelete;
					cout << "Please enter the name of the book you want to delete: ";
					getline(cin >> ws, bookToDelete);
					bool found = false;
					while (getline(inFile, line))
					{
						if (bookToDelete != line)
						{
							temp << line << endl;
						}
						else
						{
							found = true; // set found to true when book is found
						}
						
					}
					inFile.close();
					temp.close();
					remove("BookList.txt");
					rename("temp.txt", "BookList.txt");

					if (found)
					{
						cout << bookToDelete << " has been deleted." << endl;
					}
					else
					{
						cout << bookToDelete << " was not found in the book list." << endl;
					}
					cout << "\nContinue deleting? (y/n): " << endl;//prompt for continue search or no
					cin >> choice;

					while (tolower(choice) != 'y' && tolower(choice) != 'n')//to validate value
					{
						cout << "Please enter y or n: " << endl;
						cin >> choice;
					}

					if (tolower(choice) == 'n')
					{
						break;
					}
					
					
				} while (tolower(choice) == 'y');
			}
		} while (options != '5');
		cout << "Goodbye and have a nice day!" << endl;
		cout << "Looking forward for your next visit admin " << ADMIN_name << "." << endl;
		cout << ":D " << endl;
	}
	return 0;
}