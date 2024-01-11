#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
// Main Function Prototype
void mainMenu();
class Management
{
public:
    Management()
    {
        mainMenu();
    }
};
class details
{
    // protected:
    // private:
public:
    static int cid;
    int age;
    int phoneNo;
    static string name, gender;
    string add; // address
    char *arr = new char[100];
    void information()
    {
        cout << "\n\t\tEnter Customer Id      ==> ";
        cin >> cid;
        cout << "\n\t\tName                   ==> ";
        cin >> name;
        cout << "\n\t\tAge                    ==> ";
        cin >> age;
        cout << "\n\t\tAddress                ==> ";
        cin >> add;
        cout << "\n\t\tGender                 ==> ";
        cin >> gender;
        cout << "\n\n\t\t\tYour Details are save with us\n";
    }
};

int details ::cid;
string details ::name;
string details ::gender;

class registration
{
public:
    static int choice;
    int choice1;
    int back;
    static float charges;
    void flights()
    {
        string flightN[] = {"Dubai", "Canada", "UK", "USA", "Austrolia", "Europe"};
        for (int i = 0; i < 6; i++)
        {
            cout << (i + 1) << " ==> " << flightN[i] << endl;
        }
        cout << "\n\t\tWelcome To Airline's " << endl;
        cout << "\n\n\tPress The Number Of The Country For Which you Want To Book The Flight =: ";
        cin >> choice;
        //
        switch (choice)
        {
        case 1:
        {
            cout << "\n\t\t___________________Welcome to the Dubai Emirates____________________\n";
            cout << "\n\n\t\tYour confort is our priority, Enjoy the journey\n";
            cout << "\n\t\tFollowing are the flights\n";
            cout << "\n\t:==1 DUB--498\n";
            cout << "\n\t\t08-10-2023  8:00 Am Rs.14000" << endl;
            cout << "\n\t:==2 DUB--468\n";
            cout << "\n\t\t10-10-2023  12:00 Am Rs.10000" << endl;
            cout << "\n\t:==3 DUB--458\n";
            cout << "\n\t\t18-10-2023  5:00 Pm Rs.9000" << endl;
            cout << "\n\n\t\tSelect the flight you want to book ==> ";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 14000;
                cout << "\n\n\tYou have successfully book the flight DUB--498\n";
                cout << "\nYou can go back to the main menu to take the ticket\n";
            }
            else if (choice1 == 2)
            {
                charges = 10000;
                cout << "\n\n\tYou have successfully book the flight DUB--468\n";
                cout << "\nYou can go back to the main menu to take the ticket\n";
            }
            else if (choice1 == 3)
            {
                charges = 9000;
                cout << "\n\n\tYou have successfully book the flight DUB--458\n";
                cout << "\nYou can go back to the main menu to take the ticket\n";
            }
            else
            {
                cout << "\n\t\tInvalid Input \n";
                flights();
            }
            cout << "\n\t\tPress Any Key To Go To Main Menu ==> ";
            cin >> back;
            (back == 1) ? mainMenu() : mainMenu();
            break;
        }
        case 2:
        {
            cout << "\n\t\t___________________Welcome to the Candian Airlines____________________\n";
            cout << "\n\n\t\tYour confort is our priority, Enjoy the journey\n";
            cout << "\n\t\tFollowing are the flights\n";
            cout << "\n\t:==1 CA--498\n";
            cout << "\n\t\t08-10-2023  8:00 Am Rs.14000" << endl;
            cout << "\n\t:==2 CA--468\n";
            cout << "\n\t\t10-10-2023  12:00 Am Rs.10000" << endl;
            cout << "\n\t:==3 CA--458\n";
            cout << "\n\t\t18-10-2023  5:00 Pm Rs.9000" << endl;
            cout << "\n\n\t\tSelect the flight you want to book ==> ";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 14000;
                cout << "\n\n\tYou have successfully book the flight CA--498\n";
                cout << "\nYou can go back to the main menu to take the ticket\n";
            }
            else if (choice1 == 2)
            {
                charges = 10000;
                cout << "\n\n\tYou have successfully book the flight CA--468\n";
                cout << "\nYou can go back to the main menu to take the ticket\n";
            }
            else if (choice1 == 3)
            {
                charges = 9000;
                cout << "\n\n\tYou have successfully book the flight CA--458\n";
                cout << "\nYou can go back to the main menu to take the ticket\n";
            }
            else
            {
                cout << "\n\t\tInvalid Input \n";
                flights();
            }
            cout << "\n\t\tPress Any Key To Go To Main Menu ==> ";
            cin >> back;
            (back == 1) ? mainMenu() : mainMenu();
            break;
        }
        case 3:
        {
            cout << "\n\t\t___________________Welcome to the UNITED KINGDOM Airlines____________________\n";
            cout << "\n\n\t\tYour confort is our priority, Enjoy the journey\n";
            cout << "\n\t\tFollowing are the flights\n";
            cout << "\n\t:==1 UK--498\n";
            cout << "\n\t\t28-10-2023  8:00 Am Rs.44000" << endl;
            cout << "\n\n\t\tSelect the flight you want to book ==> ";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 44000;
                cout << "\n\n\tYou have successfully book the flight UK--498\n";
                cout << "\nYou can go back to the main menu to take the ticket\n";
            }
            else
            {
                cout << "\n\t\tInvalid Input \n";
                flights();
            }
            cout << "\n\t\tPress Any Key To Go To Main Menu ==> ";
            cin >> back;
            (back == 1) ? mainMenu() : mainMenu();
            break;
        }
        case 4:
        {
            cout << "\n\t\t___________________Welcome to the UNITED STATES Airlines____________________\n";
            cout << "\n\n\t\tYour confort is our priority, Enjoy the journey\n";
            cout << "\n\t\tFollowing are the flights\n";
            cout << "\n\t:==1 US--498\n";
            cout << "\n\t\t08-10-2023  8:00 Am Rs.14000" << endl;
            cout << "\n\t:==2 US--468\n";
            cout << "\n\t\t10-10-2023  12:00 Am Rs.10000" << endl;
            cout << "\n\t:==3 US--458\n";
            cout << "\n\t\t18-10-2023  5:00 Pm Rs.9000" << endl;
            cout << "\n\n\t\tSelect the flight you want to book ==> ";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 14000;
                cout << "\n\n\tYou have successfully book the flight US--498\n";
                cout << "\nYou can go back to the main menu to take the ticket\n";
            }
            else if (choice1 == 2)
            {
                charges = 10000;
                cout << "\n\n\tYou have successfully book the flight US--468\n";
                cout << "\nYou can go back to the main menu to take the ticket\n";
            }
            else if (choice1 == 3)
            {
                charges = 9000;
                cout << "\n\n\tYou have successfully book the flight US--458\n";
                cout << "\nYou can go back to the main menu to take the ticket\n";
            }
            else
            {
                cout << "\n\t\tInvalid Input \n";
                flights();
            }
            cout << "\n\t\tPress Any Key To Go To Main Menu ==> ";
            cin >> back;
            (back == 1) ? mainMenu() : mainMenu();
            break;
        }
        case 5:
        {
            cout << "\n\t\t___________________Welcome to the AUSTRALIAN Airlines____________________\n";
            cout << "\n\n\t\tYour confort is our priority, Enjoy the journey\n";
            cout << "\n\t\tFollowing are the flights\n";
            cout << "\n\t:==1 AUS--498\n";
            cout << "\n\t\t08-10-2023  8:00 Am Rs.14000" << endl;
            cout << "\n\t:==2 AUS--468\n";
            cout << "\n\t\t10-10-2023  12:00 Am Rs.10000" << endl;
            cout << "\n\t:==3 AUS--458\n";
            cout << "\n\t\t18-10-2023  5:00 Pm Rs.9000" << endl;
            cout << "\n\n\t\tSelect the flight you want to book ==> ";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 14000;
                cout << "\n\n\tYou have successfully book the flight AUS--498\n";
                cout << "\nYou can go back to the main menu to take the ticket\n";
            }
            else if (choice1 == 2)
            {
                charges = 10000;
                cout << "\n\n\tYou have successfully book the flight AUS--468\n";
                cout << "\nYou can go back to the main menu to take the ticket\n";
            }
            else if (choice1 == 3)
            {
                charges = 9000;
                cout << "\n\n\tYou have successfully book the flight AUS--458\n";
                cout << "\nYou can go back to the main menu to take the ticket\n";
            }
            else
            {
                cout << "\n\t\tInvalid Input \n";
                flights();
            }
            cout << "\n\t\tPress Any Key To Go To Main Menu ==> ";
            cin >> back;
            (back == 1) ? mainMenu() : mainMenu();
            break;
        }
        case 6:
        {
            cout << "\n\t\t___________________Welcome to the EUROPEAN Airlines____________________\n";
            cout << "\n\n\t\tYour confort is our priority, Enjoy the journey\n";
            cout << "\n\t\tFollowing are the flights\n";
            cout << "\n\t:==1 EU--498\n";
            cout << "\n\t\t08-10-2023  12:00 Am Rs.14000" << endl;
            cout << "\n\t:==2 EU--468\n";
            cout << "\n\t\t10-10-2023  4:00 Am Rs.10000" << endl;
            cout << "\n\t:==3 EU--458\n";
            cout << "\n\t\t18-10-2023  8:00 Pm Rs.9000" << endl;
            cout << "\n\n\t\tSelect the flight you want to book ==> ";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 14000;
                cout << "\n\n\tYou have successfully book the flight EU--498\n";
                cout << "\nYou can go back to the main menu to take the ticket\n";
            }
            else if (choice1 == 2)
            {
                charges = 10000;
                cout << "\n\n\tYou have successfully book the flight EU--468\n";
                cout << "\nYou can go back to the main menu to take the ticket\n";
            }
            else if (choice1 == 3)
            {
                charges = 9000;
                cout << "\n\n\tYou have successfully book the flight EU--458\n";
                cout << "\nYou can go back to the main menu to take the ticket\n";
            }
            else
            {
                cout << "\n\t\tInvalid Input \n";
                flights();
            }
            cout << "\n\t\tPress Any Key To Go To Main Menu ==> ";
            cin >> back;
            (back == 1) ? mainMenu() : mainMenu();
            break;
        }
        default:
        {
            cout << "\n\n\t\tInvalid Input \n";
            mainMenu();
            break;
        }
            // switch ends;
        }
        // functions ends
    }
    // class ends
};
float registration::charges;
int registration::choice;
class ticket : public registration, public details
{
public:
    void bill()
    {
        string destination = " ";
        ofstream ofs("flights.txt");
        {
            ofs << "=========================================" << endl;
            ofs << "==============PAK_AIRLINES===============" << endl;
            ofs << "================Tickets==================" << endl;
            ofs << "=========================================" << endl;
            ofs << "Customes ID     ==> " << details::cid << endl;
            ofs << "Customes NAME   ==> " << details::name << endl;
            ofs << "Customes GENDER ==> " << details::gender << endl;
            if (registration::choice == 1)
            {
                destination = "Dubai";
            }
            else if (registration::choice == 2)
            {
                destination = "Canada";
            }
            else if (registration::choice == 3)
            {
                destination = "United Kingdom";
            }
            else if (registration::choice == 4)
            {
                destination = "United States";
            }
            else if (registration::choice == 5)
            {
                destination = "Australia";
            }
            else if (registration::choice == 6)
            {
                destination = "Europe";
            }
            ofs << "Destination \t\t" << destination << endl;
            ofs << "Flight cost \t\t" << registration::charges << endl;
        }
        ofs.close();
    }
    void display()
    {
        ifstream ifs("flights.txt");
        {
            if (!ifs)
            {
                cout << "\n\n\n\t\tDataBase Error\n";
            }
            else
            {
                while (!ifs.eof())
                {
                    ifs.getline(arr, 100);
                    cout << arr << endl;
                }
            }
            ifs.close();
        }
        delete [] arr;//heap memory free
    }
};
void mainMenu()
{
    int choice;
    int back;
    cout << "\t\t\t          Pakistan Airline's        \n\n";
    cout << "\t\t\t              Main Menu             \n\n";
    cout << "\t\t===============================================" << endl;
    cout << "\t\t|\t  Press 1 to add the customer detail  |\n";
    cout << "\t\t|\t  Press 2 for add flight resgistration|\n";
    cout << "\t\t|\t  Press 3 for tickets and charges     |\n";
    cout << "\t\t|\t  Press 4 to exit                     |\n";
    cout << "\t\t===============================================" << endl;
    cout << "\n\n\t\t\tEnter your choice ===> ";
    cin >> choice;
    // classes
    details d;
    registration r;
    ticket t;
    switch (choice)
    {
    case 1:
    {
        cout << "\n\n\n\t\t_____________CUSTOMER____________\n"
             << endl;
        d.information();
        cout << "\n\n\t\tPress any key to go to Main Menu ===> " << endl;
        cin >> back;
        // ternay operator
        (back == 1) ? mainMenu() : mainMenu();
        break;
    }
    case 2:
    {
        cout << "\n\n\t\t_______Book a flight using this system_________\n"
             << endl;
        r.flights();
        break;
    }
    case 3:
    {
        cout << "\n\n\t\t______Get Your Ticket________\n"
             << endl;
        t.bill();
        cout << "\n\n\t\tYour ticket is ready, kindly collect it \n";
        cout << "\n\n\t\tPress 1 to collect the ticket         ==> ";
        cin >> back;
        if (back == 1)
        {
            t.display();
            cout << "\n\n\t\tPress any key to go to Main Menu       ==> ";
            cin >> back;
            (back == 1) ? mainMenu() : mainMenu();
        }
        else
        {
            mainMenu();
        }
        break;
    }
    case 4:
    {
        cout << "\n\n\t\t____________Thank-You____________\n"
             << endl;
        exit(0);
        break;
    }
    default:
    {
        cout << "\n\n\t\tInvalid Input \n \t\t\t kindly try again " << endl;
        mainMenu();
        break;
    }
    }
}
int main()
{
    Management m;
    return 0;
}