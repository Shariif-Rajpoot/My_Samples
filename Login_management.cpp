#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;
int checkUser();	   // prototype
int adminMenu();	   // prototype
int regularUserMenu(); // prototype
void adminRights();
void regularUserRights();
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
// second class
class UserManager
{
protected:
	vector<User> user;

public:
	void registerUser();
	void loginUser(string, string);
	void showUserList();
	void searchUser(string);
};
// third class
class AdminUser : public UserManager
{
public:
	void addNewUser();
	void deleteUser(string);
};
// fourth class
class RegularUser : public UserManager
{
public:
	void logout(string);
};
// classes end
void UserManager::registerUser()
{
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
	// creating the file
	ofstream ofs;
	ofs.open("registerUsers.txt", ios::app);
	if (ofs.is_open())
	{
		ofs << "\t\t\tData of all the enter user is below " << endl
			<< endl;
		ofs << "User "
			<< " Password" << endl;
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
	user.push_back(newUser_1);
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
		}
		else
		{
			cout << endl;
			cout << "\t\tDear Invalid Username or Password" << endl;
		}
	}
}
void UserManager::showUserList()
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
	for (int i = 0; i < user.size(); i++)
	{
		if (user[i].getUserName() == name)
		{
			user.erase(user.begin() + i);
			cout << "\t\t\tUser " << name << " is removed successfully " << endl;
			break;
		}
	}
}

void AdminUser::addNewUser()
{
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
	User newUser_1;
	newUser_1 = User(userName, password);
	user.push_back(newUser_1);
	cout << endl;
	cout << "\t\tUser added successfully " << endl
		 << endl;
}
// fourth class
void RegularUser::logout(string name)
{
	ofstream ofs;
	ofs.open("removedUser.txt", ios::app);
	for (int i = 0; i < user.size(); i++)
	{
		if (user[i].getUserName() == name)
		{
			user.erase(user.begin() + i);
			ofs << "\t\tList of logout users" << endl
				<< endl;
			ofs << "User ==="
				<< "Password" << endl;
			ofs << user[i].getUserName() << "==" << user[i].getUserPassword() << endl;
			cout << "\t\t\tUser " << name << " is logout successfully " << endl;
			break;
		}
	}
}
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

// functions
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
	AdminUser newUser;
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
			newUser.showUserList();
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
	RegularUser newUser;
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
		newUser.showUserList();
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