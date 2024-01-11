#include <iostream>
#include <fstream>
#include <string.h>
// functions prototypes
void login();
void registration();
void forget();
// main function
using namespace std;
int main()
{
    cout << "\t\t\t____________________________________________________________\n\n\n";
    cout << "\t\t\t___________________WELCOME TO THE LOGIN PAGE_________________\n\n\n";
    cout << "\t\t\t_____________________          MENU        ___________________\n\n";
    int choice;
    cout << "|Enter 1 to Login               |" << endl;
    cout << "|Enter 2 to registration        |" << endl;
    cout << "|Enter 3 if you forget password |" << endl;
    cout << "|Enter 4 to exit                |" << endl;
    cout << "Enter your choice => ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        login();
        break;

    case 2:
        registration();
        break;

    case 3:
        forget();
        break;

    case 4:
        cout << "\t\t\tTHANK YOU!!!\n";
        break;

    default:
        cout << "\t\t\tPlease Select from the menu option \n\n"
             << endl;
        main();
        break;
    }
    return 0;
}
// functions definition
void registration()
{
    cout << "\t\t\t(((!****REGISTER NOW!****)))\n\n"
         << endl;
    string name, password;
    cout << "Enter user name ===> ";
    cin >> name;
    cout << "Enter your password ===> ";
    cin >> password;
    // making file
    ofstream ofs;
    ofs.open("record.txt", ios::app);
    ofs << name << " " << password << endl;
    ofs.close();
    // goto main page;
    system("cls");
    cout<<"\t\t\tYOU ARE REGISTER NOW!!!\n\n";
    main();
}
void login()
{
    string password, name;
    cout << "\t\t\t(((!****WELOCME THE LOGIN PAGE!****)))\n\n";
    cout << "ENTER THE USER NAME \n\n";
    cin >> name;
    cout << "ENTER THE PASSWORD \n\n";
    cin >> password;
    ifstream ifs;
    int flag = 0;
    ifs.open("record.txt");
    // to read from the file
    string f_name, f_password;
    while (ifs >> f_name >> f_password)
    {
        if (f_name == name && f_password == password)
        {
            /* code */
            flag = 1;
            break;
        }
    }
    ifs.close();
    if (flag == 1)
    {
        system("cls");
        cout << "\t\t\tUSER NAME IS ===> " << f_name << endl;
        cout << "\t\t\tYOUR PASSWORD IS ===> " << f_password << endl;
        cout << "\t\t\tYOU ARE LOGGED IN\n\n"
             << endl;
        // goto function
        main();
    }
    else
    {
        system("cls");
        cout << "ACCOUT NOT FIND \n FIRST REGISTER YOUR ACCOUNT \n"
             << endl;
        // goto main function
        main();
    }
}

void forget()
{
    string name;
    cout << "\t\t\tOOP'S YOU FORGET YOUR PASSWORD\n \t\tRELAX ===>\n\n\n"
         << endl;
    cout << "ENTER THE USER NAME ==> ";
    cin >> name;
    // file reading
    ifstream ifs;
    string f_name, f_password;
    int flag = 0;
    ifs.open("record.txt");
    while (!(ifs.eof()))
    {
        ifs >> f_name; ifs >> f_password;
        if (f_name == name)
        {
            flag = 1;
            break;
        }
    }
    ifs.close();
    if (flag == 1)
    {
        system("cls");
        cout << "\t\tYOUR ACCOUT FIND \n\n"
             << endl;
        cout << "\t\t\tYOUR PASSWORD IS ===> " << f_password << endl;
        // goto main
        main();
    }
    else
    {
        system("cls");
        cout << "\t\t\tACCONT DOESN'T EXIST \n\n ";
        // goto main
        main();
    }
}