//FUNCTION showOptions(string& ADMIN_name)
//{
//	system clear screen;
//	print("Welcome back Admin", ADMIN_name, "What would you like to do today ? ");
//	print("options");//decorative design
//	print("1.Search Books");
//	print("2.View Books");
//	print("3.Add Books");
//	print("4.Delete Books");
//	print("5.Logout");
//}
//
//FUNCTION view()
//{
//	system clear screen;
//	print("VIEW BOOK LIST");//decorative design
//}
//
//int main()
//{
//	char login;
//	int noADMIN = 0, noBOOKS = 0;//initialize counter to 0
//	bool loginSuccessful = false;
//	string ADMIN_name, NAME_check;
//	string string ADMIN_pass, PASS_check;
//	string BOOK_name, BOOK_check;
//	string BOOKadd, BOOKdel;
//	ifstream inFile;
//	ofstream outFile;
//	ofstream temp;
//
//	do
//	{
//		print("Welcome to AMBATUBUS Library System");
//		print("Login");
//		print("1.Administrator");
//		print("2.Member");
//		print("Please choose login method: ");
//		input(login);
//
//		if (login not equal to '1' and '2')
//		{
//			print("Please enter a number according to the menu!");
//		}
//	} while (login not equal to '1' and '2');
//
//	if (login equal to '1')
//	{
//		while (not loginSuccessful)
//		{
//			inFile open("ADMIN.txt");
//			if (inFile open fail())
//			{
//				print("Error opening file");
//				exit(1);
//			}
//			print("Username: ");
//			input(ADMIN_name);
//			print("Password: ");
//			input(ADMIN_pass);
//
//			while (get line NAME_check from inFile and get line PASS_check from inFile)
//			{
//				noADMIN++;
//				if (ADMIN_name equal to NAME_check and ADMIN_pass equal to PASS_check)
//				{
//					loginSuccessful equal to true;
//					break; 
//				}
//				ignore inFile;
//			}
//			if (noADMIN equal to 0 or ADMIN_name not equal to NAME_check or ADMIN_pass not equal to PASS_check)
//			{
//				print("Invalid username or password!");
//				loginSuccessful equal to false;
//			}
//			close inFile;
//		}
//		char options;
//		do
//		{
//			showOptions(ADMIN_name);
//			print("Please enter options: ");
//			input(options);
//
//			if (options not equal to '1', '2', '3', '4', '5')
//			{
//				print("Please choose an available options!");
//				system(pause);
//			}
//
//			else if (options == '1')
//			{
//				open inFile("BookList.txt");
//				if (inFile.is_open is false)
//				{
//					print("Error opening file");
//					system(pause);
//				}
//				char choice;
//				do
//				{
//					system clear screen;
//					print("SEARCH BOOKS");//decorative design
//					bool foundBOOK = false;
//					print("What book would you like to search for?");
//					input(BOOK_name);
//					seek inFile for the beginning;
//					while (inFile get line for BOOK_check)
//					{
//						if (BOOK_name equal to BOOK_check)
//						{
//							print("The book is registered in the library system");
//							foundBOOK becomes true;
//							break;
//						}
//					}
//					if (not foundBOOK)
//					{
//						print("The book is not registered in the library system");
//					}
//					print("Continue Searching? (y/n)");
//					input(choice);
//
//					while (choice not equal to 'y' or 'n')
//					{
//						print("Please enter y or n: ");
//						input(choice);
//					}
//					if (choice equal to 'n')
//					{
//						break;
//					}
//				} while (choice equal to 'y');
//				close inFile;
//			}
//			else if (options equal to '2')
//			{
//				call view_books function;
//				inFile open("BookList.txt");
//				if (not inFile open())
//				{
//					print("Error opening file");
//					system(pause);
//				}
//				string line;
//				while (not inFile end of line())
//				{
//					int x = 0;
//					while (getline line from inFile)
//					{
//						print(x + 1. line);
//						x++;
//					}
//				}
//				close inFile;
//				print("Press enter to return to Options menu");
//				system(pause);
//			}
//			else if (options == '3')
//			{
//				char choice;
//				do
//				{
//					system clear screen;
//					print("ADD BOOKS");//decorative design
//					open outFile("BookList.txt", ios_base::app);
//					if (not outFile open())
//					{
//						print("Error opening file");
//						system(pause);
//					}
//					print("What books would you like to add into the system: ");
//					input(BOOKadd);
//
//					append BOOKadd into outFile;
//					print("Book successfully added into library");
//					close outFile();
//
//					print("Continue Adding? (y/n)");
//					input(choice);
//
//					while (choice not equal to 'y' or 'n')
//					{
//						print("Please enter y or n: ");
//						input(choice);
//					}
//					if (choice equal to 'n')
//					{
//						break;
//					}
//				} while (choice equal to 'y');
//			}
//			else if (options == '4')
//			{
//				char choice;
//				do
//				{
//					system clear screen;
//					print("DELETE BOOKS");//decorative design
//					open inFile("BookList.txt");
//					open temp("temp.txt");
//					string line;
//					string bookToDelete;
//					print("Please enter the name of the book you want to delete: ");
//					input(bookToDelete);
//					bool found = false;
//					while (getline(inFile, line))
//					{
//						if (bookToDelete != line)
//						{
//							temp << line << endl;
//						}
//						else
//						{
//							found = true; //set found to true when book is found
//						}
//					}
//					close inFile();
//					close temp();
//					remove("BookList.txt");
//					rename("temp.txt", "BookList.txt");
//					if (found)
//					{
//						print(bookToDelete, "has been deleted.");
//					}
//					else
//					{
//						print(bookToDelete, "was not found in Book List.");
//					}
//					print("Continue deleting? (y/n):");
//					input(choice);
//					while (choice not equal to 'y' or 'n')
//					{
//						print("Please enter y or n: ");
//						input(choice);
//					}
//					if (choice equal to 'n')
//					{
//						break;
//					}
//				} while (choice equal to 'y');
//			}
//		}while (options not equal to '5');
//		print("Goodbye and have a nice day!");
//		print("Looking forward to your next visit admin", ADMIN_name);
//		print(":D"):
//	}
//	return 0;
//}