#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// function prototype
void menu();
void chooseOption(int);
// class
class loggingIn
{
private:
    string userId;
    string password;

public:
    void login();
    void registration();
    void forget();
} logIn;
// derived function
int main()
{
    menu();
    return 0;
}
// function defintions
void menu()
{
    int c;
    cout << "\t\t\t_____________________  Menu  _________________\n\n";
    cout << "                                                    \n\n";
    cout << "\t| Press 1 to LOGIN                    |" << endl;
    cout << "\t| Press 2 to REGISTER                 |" << endl;
    cout << "\t| Press 3 if you forgot your PASSWORD |" << endl;
    cout << "\t| Press 4 to EXIT                     |" << endl;
    cout << "\n\n\t\t\t Please enter your choice ===>";
    cin >> c;
    // function
    chooseOption(c);
}
void chooseOption(int choice)
{
    switch (choice)
    {
    case 1:
    {
        logIn.login();
        break;
    }
    case 2:
    {
        logIn.registration();
        break;
    }
    case 3:
    {
        logIn.forget();
        break;
    }
    case 4:
    {
        cout << "\t\t____ThankYou____\n"
             << endl;
        exit(0);
    }
    default:
    {
        cout << "\t\t\t Please select from the options given above \n";
    }
    }
    // go to menu function
    menu();
}
void loggingIn::registration()
{
    cout << endl
         << endl;
    cout << "===============================" << endl;
    cout << "    Welcome For Registration   " << endl;
    cout << "===============================" << endl;
    cout << endl;
    cout << "Enter the userName  ==> ";
    cin >> userId;
    cout << "Enter the password  ==> ";
    cin >> password;
    ofstream ofs;
    ofs.open("loginRecord.txt", ios::app);
    if (ofs.is_open())
    {
        ofs << userId << " " << password << endl;
        cout << "\t\t\tRegistration is successful !" << endl;
    }
    else
    {
        cout << "\t\t\tOops! DataBase Error\n"
             << endl;
        cout << "\t\tTry Again Later        \n"
             << endl;
    }
    ofs.close();
    // going back to the menu function
    menu();
}
// function of classes...
void loggingIn ::login()
{
    system("cls");
    cout << endl
         << endl;
    cout << "===============================" << endl;
    cout << "     Welcome For Logging_In    " << endl;
    cout << "===============================" << endl;
    cout << endl;
    int flag = 0;
    string id, pass;
    cout << "\t\t\t Please Enter The UserName and Password " << endl;
    cout << "\t\tUSERNAME  ==> ";
    cin >> userId;
    cout << "\t\tPASSWORD ==> ";
    cin >> password;

    // fileOpening for reading.....
    ifstream ifs;
    ifs.open("loginRecord.txt");
    if (ifs.is_open())
    {
        while (ifs.eof())
        {
            ifs >> id;
            ifs >> pass;
            if (userId == id && password == pass)
            {
                flag = 1;
                system("cls");
            }
        }
    }
    {
        cout << "\t\t Dear file not open" << endl;
    }
    ifs.close();
    // condition for conformation
    if (flag == 1)
        cout << userId << " Your LOGIN is successful \n\n Thanks for logging in !\n";
    else
        cout << "\n LOGIN ERROR \n Please check your username and password\n";

    // moving to the menu function
    menu();
}

void loggingIn::forget()
{
    system("cls");
    cout << endl
         << endl;
    cout << "======================================" << endl;
    cout << "    Don't Have Worries We Are Here    " << endl;
    cout << "======================================" << endl;
    cout << endl;
    int option;
    cout << "\t\t\tYou Forget The Password? No worries \n";
    cout << "|    Press 1 to search your id by userName   |" << endl;
    cout << "|    Press 2 to go back to menu              |" << endl;
    cout << "\t\t\tEnter Your Choice ==>";
    cin >> option;
    switch (option)
    {
    case 1:
    {
        int flag = 0;
        string sId, sPass;
        cout << "\n\t\t\t Enter the username which you remembered ==> ";
        cin >> userId;
        // reading the file
        ifstream ifs;
        ifs.open("loginRecord.txt");
        while (ifs.eof())
        {
            ifs >> sId >> sPass;
            if (userId == sId)
            {
                flag = 1;
            }
        }
        ifs.close();
        if (flag == 1)
        {
            cout << "\n\n Your account is found !" << endl;
            cout << "\n\n Your password is ====> " << sPass;
        }
        else
        {
            cout << "\t\tSorry! we can't find your password " << endl;
        }
        // going back to menu ==>
        menu();
        break;
    }
    case 2:
    {
        menu();
        break;
    }
    default:
    {
        cout << "\t\t\t Wrong choice ! Please Try Again " << endl;
        // recursive==>
        forget();
    }
    }
}