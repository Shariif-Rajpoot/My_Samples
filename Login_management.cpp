
#include <iostream> //for input and output
#include <fstream>	//for file operation's
#include <string.h>
#include <vector> //stl standard template library
using namespace std;
int checkUser();		  // prototype( to check the user, admin or regular by giving choice)
int adminMenu();		  // prototype( if user is admin, some access will be provided to it)
int regularUserMenu();	  // prototype( if user is regular, some access will be provided to it)
void adminRights();		  // prototype (to specify all the operation for admin to perform)
void regularUserRights(); // prototype (to specify all the operations for regular user to perform)
// first class
class User
{
private:
	string userName;
	string password;

public:
	User();
	User(string, string);
	string getUserName();
	string getUserPassword();
};
User::User() {}
User::User(string userName, string password)
{
	this->userName = userName;
	this->password = password;
}
string User::getUserName()
{
	return userName;
}
string User::getUserPassword()
{
	return password;
}
// second class an abstract class
// we have here hierarchical inheritance.
class UserManager
{
protected:
	vector<User> user;

public:
	void registerUser();
	void loginUser(string, string);
	virtual void showUserList() = 0; // pure virtual function
	void searchUser(string);
};
// third class
class AdminUser : public UserManager
{
public:
	void addNewUser();
	void showUserList(); // function overriding
	void deleteUser(string);
};
// fourth class
class RegularUser : public UserManager
{
public:
	void logout(string);
	void showUserList(); // function overriding
};
// classes end
void UserManager::registerUser()
{
label: // jump statement
	cout << endl
		 << endl;
	cout << "\t\t\t|==============================================|" << endl;
	cout << "\t\t\t|===========}Welcome For Registration{=========|" << endl;
	cout << "\t\t\t|==============================================|" << endl;
	cout << endl
		 << endl;
	string userName;
	string password;
	cout << "\tEnter the user name => ";
	cin >> userName;
	cout << "\tEnter the password  => ";
	cin >> password;
	ifstream ifs;				   // for writing data from file
	ifs.open("registerUsers.txt"); // to open the file
	string name, pass;
	for (; !ifs.eof();)
	{
		ifs >> name >> pass;
		if (name == userName || password == pass)
		{
			cout << "\t\t\tAlready User exits with same name or  password try another" << endl;
			goto label;
		}
	}
	ifs.close(); // closing the file
	// creating the file for reading data init
	ofstream ofs;
	ofs.open("registerUsers.txt", ios::app); // in append mode
	if (ofs.is_open())
	{
		// ofs << "\t\t\tData of register user is below " << endl
		//     << endl;
		// ofs << "User "
		//     << " Password" << endl;
		ofs << userName << " " << password << endl;
		cout << endl;
	}
	else
	{
		cout << "\t\t\tOOPs Dear DataBase Error, try again later" << endl;
	}
	ofs.close(); // closing the file
	User newUser_1;
	newUser_1 = User(userName, password);
	user.push_back(newUser_1); // build in function to store data in array of selected type
	cout << endl;
	cout << "\t\tUser registered successfully " << endl
		 << endl;
}
void UserManager::loginUser(string name, string pass)
{
	cout << endl
		 << endl;
	cout << "\t\t\t|==============================================|" << endl;
	cout << "\t\t\t|===========}Welcome For Logging___IN{=========|" << endl;
	cout << "\t\t\t|==============================================|" << endl;
	cout << endl
		 << endl;
	for (int i = 0; i < user.size(); i++)
	{
		if (user[i].getUserName() == name && user[i].getUserPassword() == pass)
		{
			cout << endl;
			cout << "\t\t\t|===============================|" << endl;
			cout << "\t\t\t|======Login Successfully=======|" << endl;
			cout << "\t\t\t|===============================|" << endl;
			cout << endl;
			break;
		}
	}
}
void UserManager::searchUser(string userName)
{
	for (int i = 0; i < user.size(); i++)
	{
		if (user[i].getUserName() == userName)
		{
			cout << "\t\t\tUser " << userName << " Is Founded " << endl;
			break;
		}
	}
}
// third class object
void AdminUser::deleteUser(string name)
{
	ofstream ofs;
	ofs.open("Total_Users.txt", ios::app);
	string Name, password;
	ifstream ifs;
	ifs.open("registerUsers.txt");
	ifs >> Name >> password;
	for (; !ifs.eof();)
	{
		if (Name == name)
		{
			cout << "\t\t\tUser " << Name << " is deleted successfully " << endl;
		}
		else
		{
			ofs << Name << " " << password << endl;
		}
		ifs >> Name >> password;
	}
	ifs.close();
	ofs.close();
	remove("registerUsers.txt");
	rename("Total_Users.txt", "registerUsers.txt");
}

void AdminUser::addNewUser()
{
label:
	cout << endl
		 << endl;
	cout << "\t\t\t|==============================================|" << endl;
	cout << "\t\t\t|===============}Adding New User{==============|" << endl;
	cout << "\t\t\t|==============================================|" << endl;
	cout << endl
		 << endl;
	string userName;
	string password;
	cout << "\tEnter the user name => ";
	cin >> userName;
	cout << "\tEnter the password  => ";
	cin >> password;
	ifstream ifs;
	ifs.open("registerUsers.txt");
	string name, pass;
	for (; !ifs.eof();)
	{
		ifs >> name >> pass;
		if (name == userName || password == pass)
		{
			cout << "\t\t\tAlready User exits with same name or  password try another" << endl;
			goto label;
		}
	}
	ifs.close();
	ofstream ofs;
	ofs.open("registerUsers.txt", ios::app);
	ofs << userName << " " << password << endl;
	ofs.close();
	User newUser_1;
	newUser_1 = User(userName, password);
	user.push_back(newUser_1);
	cout << endl;
	cout << "\t\tUser added successfully " << endl
		 << endl;
}
void AdminUser::showUserList()
{
	cout << endl;
	cout << "\t\t\t|===============================|" << endl;
	cout << "\t\t\t|==========Login User's=========|" << endl;
	cout << "\t\t\t|===============================|" << endl;
	cout << endl;
	string name, password;
	ifstream ifs("registerUsers.txt");
	ifs >> name >> password;
	int i = 0;
	for (; !ifs.eof(); i++)
	{
		cout << "\t\t\t| === User Number = = = => " << i + 1 << " => "
			 << "\n\t\tName =>" << name << "\n\t\tPassword => " << password << endl;
		ifs >> name >> password;
	}
	ifs.close();
}
// fourth class
void RegularUser::logout(string name)
{
	ofstream ofs;
	ofs.open("Total_Users.txt", ios::app);
	string Name, password;
	ifstream ifs;
	ifs.open("registerUsers.txt");
	ifs >> Name >> password;
	for (; !ifs.eof();)
	{
		if (Name == name)
		{
			cout << "\t\t\tUser " << Name << " is logout successfully " << endl;
		}
		else
		{
			ofs << Name << " " << password << endl;
		}
		ifs >> Name >> password;
	}
	ifs.close();
	ofs.close();
	remove("registerUsers.txt");
	rename("Total_Users.txt", "registerUsers.txt");
}

void RegularUser::showUserList()
{
	cout << endl;
	cout << "\t\t\t|===============================|" << endl;
	cout << "\t\t\t|==========Login User's=========|" << endl;
	cout << "\t\t\t|===============================|" << endl;
	cout << endl;
	for (int i = 0; i < user.size(); i++)
	{
		cout << "\t\t\t| === User Number = = = => " << i + 1 << " => " << user[i].getUserName() << endl;
	}
}
// main function
int main()
{
	int getUser = checkUser();
	if (getUser == 1)
	{
		adminRights();
	}
	else if (getUser == 2)
	{
		regularUserRights();
	}
	else if (getUser == 3)
	{
		cout << endl;
		cout << "\t\t\tThanks Dear!!!!" << endl;
		exit(0);
	}
	else
	{
		cout << endl
			 << endl;
		cout << "\t\t\tInvalid Input Dear User " << endl;
		main();
	}

	return 0;
}

// function definitions
int checkUser()
{
	int choice;
	cout << endl
		 << endl;
	cout << "\t\t\t\t|}==========================={|" << endl;
	cout << "\t\t\t\t|==Hello You Beautiful User===|" << endl;
	cout << "\t\t\t\t|==Enter 1 if Admin User======|" << endl;
	cout << "\t\t\t\t|==Enter 2 if regular User ===|" << endl;
	cout << "\t\t\t\t|==Enter 3 To Exit============|" << endl;
	cout << "\t\t\t\t|}==========================={|" << endl;
	cout << endl;
	cout << "\t\t\tLet us know by entering your choice => ";
	cin >> choice;
	return choice;
}
int regularUserMenu()
{
	int choice;
	cout << endl
		 << endl;
	cout << "\t\t\t\t|}==========================={|" << endl;
	cout << "\t\t\t\t|==Enter 1 To Register =======|" << endl;
	cout << "\t\t\t\t|==Enter 2 To Login ==========|" << endl;
	cout << "\t\t\t\t|==Enter 3 To Show User list==|" << endl;
	cout << "\t\t\t\t|==Enter 4 To Search =========|" << endl;
	cout << "\t\t\t\t|==Enter 5 To Logout =========|" << endl;
	cout << "\t\t\t\t|==Enter 6 To Back============|" << endl;
	cout << "\t\t\t\t|}==========================={|" << endl;
	cout << "\n\n\t\t\tKindly Dear, Enter your choice, what you want => ";
	cin >> choice;
	cout << endl;
	return choice;
}
int adminMenu()
{
	int choice;
	cout << endl
		 << endl;
	cout << "\t\t\t\t|}================================{|" << endl;
	cout << "\t\t\t\t|==Enter 1 To Register User========|" << endl;
	cout << "\t\t\t\t|==Enter 2 To Login User===========|" << endl;
	cout << "\t\t\t\t|==Enter 3 To Show User list=======|" << endl;
	cout << "\t\t\t\t|==Enter 4 To Search User==========|" << endl;
	cout << "\t\t\t\t|==Enter 5 To Delete User =========|" << endl;
	cout << "\t\t\t\t|==Enter 6 To Add User ============|" << endl;
	cout << "\t\t\t\t|==Enter 7 To Back=================|" << endl;
	cout << "\t\t\t\t|}================================{|" << endl;
	cout << "\n\n\t\t\tKindly Dear, Enter your choice, what you want => ";
	cin >> choice;
	cout << endl;
	return choice;
}
void adminRights()
{
	UserManager *userManager; // an abstract class pointer
	AdminUser newUser;
	userManager = &newUser; // pointing to the address of child class
	string password;
	string email;
	cout << endl
		 << endl;
	cout << "\t\t|========Dear Admin, Enter The Login Email And Password=========|" << endl;
	cout << endl;
	cout << "\t\tEnter Email => ";
	cin >> email;
	cout << "\t\tEnter Password => ";
	cin >> password;
	if ((email == "admin@email") && (password == "admin"))
	{
		// operations for admin
	label:
		int option;
		option = adminMenu();
		switch (option)
		{
		case 1:
		{
			newUser.registerUser();
			break;
		}
		case 2:
		{
			string userName;
			string password;
			cout << "\t\tEnter your user name => ";
			cin >> userName;
			cout << "\t\tEnter your password  => ";
			cin >> password;
			newUser.loginUser(userName, password);
			break;
		}
		case 3:
		{
			userManager->showUserList(); // achieving runtime polymorphism
			break;
		}
		case 4:
		{
			string userName;
			cout << "\t\t\tEnter your user name => ";
			cin >> userName;
			newUser.searchUser(userName);
			break;
		}
		case 5:
		{
			string userName;
			cout << "\t\t\tEnter your user name => ";
			cin >> userName;
			newUser.deleteUser(userName);
			break;
		}
		case 6:
		{
			newUser.addNewUser();
			break;
		}
		case 7:
		{
			cout << "\t\t\tThanks You!!!!!" << endl;
			main();
		}
		default:
		{
			cout << endl;
			cout << "\t\t\tInvalid Input" << endl;
			break;
		}
		}
		goto label;
	}
	else
	{
		cout << "\t\tDear Invalid, Email or password " << endl;
		main();
	}
}
void regularUserRights()
{
	UserManager *userManager; // base class pointer
	RegularUser newUser;
	userManager = &newUser; // pointing to the address of child class
label:
	int option = regularUserMenu();
	switch (option)
	{
	case 1:
	{
		newUser.registerUser();
		break;
	}
	case 2:
	{
		string userName;
		string password;
		cout << "\t\tEnter your user name => ";
		cin >> userName;
		cout << "\t\tEnter your password  => ";
		cin >> password;
		newUser.loginUser(userName, password);
		break;
	}
	case 3:
	{
		userManager->showUserList(); // achieving runtime polymorphism
		break;
	}
	case 4:
	{
		string userName;
		cout << "\t\t\tEnter your user name => ";
		cin >> userName;
		newUser.searchUser(userName);
		break;
	}
	case 5:
	{
		string userName;
		cout << "\t\t\tEnter your user name => ";
		cin >> userName;
		newUser.logout(userName);
		break;
	}
	case 6:
	{
		cout << "\t\t\tThanks You!!!!!" << endl;
		main();
	}
	default:
	{
		cout << endl;
		cout << "\t\t\tInvalid Input" << endl;
	}
	}
	goto label;
}