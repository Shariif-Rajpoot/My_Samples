#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class market
{
private:
    string pName;
    int price;
    int pCode;
    float dis; // discount
    void administrator();
    void add();
    void edit();
    void rem();
    void buyer();
    void list();
    void recipt();
public:
    void menu();
};
// first function
void market::menu()
{
label:
    cout << "\t\t\t|____________________________________|\n";
    cout << "\t\t\t|                                    |\n";
    cout << "\t\t\t|                                    |\n";
    cout << "\t\t\t|      SUPER_MARKET WELCOME PAGE     |\n";
    cout << "\t\t\t|                                    |\n";
    cout << "\t\t\t!____________________________________!\n";
    cout << "\t\t\t|____________________________________|\n";
    cout << endl
         << endl;
    int choice;
    cout << "\n\t\t|Enter 1 For Administrator |==> ";
    cout << "\n\t\t|Enter 2 For Buyer         |==> ";
    cout << "\n\t\t|Enter 3 For Exit          |==> ";
    cout << "\n\t\tEnter your Choice           ==> ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        string email;
        string password;
        cout << "\n\n\t\t\tEnter The Password And Email\n\n";
        cout << "\t\tEnter The Email    ==> ";
        cin >> email;
        cout << "\t\tEnter The Password ==> ";
        cin >> password;
        if (email == "super@email.com" && password == "raja123")
        {
            administrator();
            break;
        }
        else
        {
            system("cls");
            cout << "\t\t\tInvalid Password Or Email \n\n";
            break;
        }
    }
    case 2:
    {
        buyer();
        break;
    }
    case 3:
    {
        exit(0);
    }
    default:
    {
        system("cls");
        cout << "\t\t\t Invalid option , Enter the Correct Option ";
        break;
    }
    }
    goto label; // menu
}
// second function
void market ::administrator()
{
    system("cls");
label:
    int choice;
    cout << "\n\n\t\t\t|Enter 1 To Add Items    |";
    cout << "\n\n\t\t\t|Enter 2 To Edit Items   |";
    cout << "\n\n\t\t\t|Enter 3 To Delete Items |";
    cout << "\n\n\t\t\t|Enter 4 To Go Main Menu |";
    cout << "\n\n\t\t\t\tEnter Your Choice ==> ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        add();
        break;
    }
    case 2:
    {
        edit();
        break;
    }
    case 3:
    {
        rem();
        break;
    }
    case 4:
    {
        menu();
        break;
    }
    default:
    {
        system("cls");
        cout << "\t\t\t Invalid option , Enter the Correct Option ";
        break;
    }
    }
    goto label;
}
// third function
void market::add()
{
    int choice;
    ofstream ofs;
    ofs.open("DataBase.txt", ios::app);
    do
    {
        cout << "\n\t\t\t|Enter The Name OF Product    == > ";
        cin >> pName;
        cout << "\n\t\t\t|Enter The Code OF Product     == > ";
        cin >> pCode;
        cout << "\n\t\t\t|Enter The Price OF Product   == > ";
        cin >> price;
        cout << "\n\t\t\t|Enter The Discount OF Product == > ";
        cin >> dis;
        system("cls");
        if (ofs.is_open())
        {
            ofs << pCode << " " << pName << " " << price << " " << dis << endl;
        }
        else
        {
            cout << "\n\n\n\t\t\tDataBase Error\n\n";
        }
        cout << "\n\t\t\tTo Insert More Items press 1 Else 2 For Not ==> ";
        cin >> choice;
    } while (choice == 1);
    ofs.close();
    // administrator menu();
    administrator();
}
void market::rem()
{
    int choice;
    ofstream ofs;
    ifstream ifs;
    ifs.open("DataBase.txt");
    ofs.open("data.txt", ios::app);
    ifs >> pCode >> pName >> price >> dis;
    int c;
    cout << "\n\n\t\t\tEnter The Prduct Code => ";
    cin >> c;
    while (!ifs.eof())
    {

        if (c == pCode)
        {
            cout << pCode << " " << pName << " " << price << " " << dis << endl;
            cout << "\t\tRecord Deleted \n";
        }
        else
        {
            ofs << pCode << " " << pName << " " << price << " " << dis << endl;
        }
        ifs >> pCode >> pName >> price >> dis;
    }
    ifs.close();
    ofs.close();
    remove("DataBase.txt");
    rename("data.txt", "DataBase.txt");
    // adminstrator menu
    administrator();
}
// fifth function
void market::edit()
{
    string n;
    int c;
    int p;
    float d;
    ifstream ifs;
    ifs.open("DataBase.txt");
    ifs >> c >> n >> p >> d;
    ofstream ofs;
    ofs.open("data.txt", ios::app);
    int code;
    cout << "\n\t\tEnter the code of the product ==> ";
    cin >> code;
    while (!ifs.eof())
    {
        if (code == c)
        {
            cout << endl;
            cout << c << " " << n << " " << p << " " << d << endl;
            cout << "\n\t\t\tEdit this ==> \n\n";
            cout << "\n\t\t\t|Enter The Name OF Product    == > ";
            cin >> pName;
            cout << "\n\t\t\t|Enter The Code OF Product     == > ";
            cin >> pCode;
            cout << "\n\t\t\t|Enter The Price OF Product   == > ";
            cin >> price;
            cout << "\n\t\t\t|Enter The Discount OF Product == > ";
            cin >> dis;
            ofs << pCode << " " << pName << " " << price << " " << dis << endl;
        }
        else
        {
            ofs << c << " " << n << " " << p << " " << d << endl;
            // cout<<"\n\n\t\t\tRecord Not Found";
        }
        ifs >> c >> n >> p >> d;
    }
    ifs.close();
    ofs.close();
    remove("DataBase.txt");
    rename("data.txt", "DataBase.txt");
}
// administrator clear
/* Sixth Function buyer start */
void market::buyer()
{
label:
    int choice;
    cout << endl
         << endl
         << endl;
    cout << "\t\t|---------------------------|\n";
    cout << "\t\t|___________________________|\n";
    cout << "\t\t|                           |\n";
    cout << "\t\t   Enter 1 To Buy Products   \n";
    cout << "\t\t   Enter 2 To Main Menu      \n";
    cout << "\t\t|___________________________|\n";
    cout << "\t\t|---------------------------|\n";
    cout << "\t\tEnter Your Choice ==> ";
    cin >> choice;
    cout << endl
         << endl;
    switch (choice)
    {
    case 1:
    {
        recipt();
        break;
    }
    case 2:
    {
        menu();
        break;
    }
    default:
    {
        system("cls");
        cout << "\n\t\t\tKindly Select From The Given Options ";
        break;
    }
    }
    goto label;
}
// Seventh function
void market ::list()
{
    cout << endl
         << endl;
    cout << "\n\n\t\t!                         !";
    cout << "\n\n\t\t!_________________________!";
    cout << "\n\n\t\t!                         !";
    cout << "\n\n\t\t!      List Of Items      !";
    cout << "\n\n\t\t!_________________________!";
    cout << endl
         << endl;
    ifstream ifs;
    ifs.open("DataBase.txt");
    ifs >> pCode >> pName >> price >> dis;
    cout << "\n\n\t\t\t"
            "Code"
         << "\t\t"
         << "Name"
         << "\t\t"
         << "Price"
         << "\t\t"
         << "Discount" << endl;
    while (!ifs.eof())
    {
        cout << "\n\t\t\t" << pCode << "\t\t" << pName << "\t\t" << price << "\t\t" << dis << endl;
        cout << endl
             << endl;
        ifs >> pCode >> pName >> price >> dis;
    }
    ifs.close();
}
// Eighth Function
void market ::recipt()
{
    cout << endl
         << endl;
    cout << "\n\t\t|====================================|";
    cout << "\n\t\t|       Kindly Place Your Order      |";
    cout << "\n\t\t|====================================|";
    list();
    int *array_items = new int[100];
    int *array_quant = new int[100];
    int i = 0;
    int choice;
    do
    {
    /* code */
    label:
        cout << "\n\n\t\tEnter The Id Of The Item         ==> ";
        cin >> array_items[i];
        cout << "\n\n\t\tEnter The Quantity of The Item   ==> ";
        cin >> array_quant[i];
        for (int j = 0; j < i; j++)
        {
            if (array_items[j] == array_items[i])
            {
                cout << "\n\n\n\t\tAlready Order \n\n \t\t\tDuplicate Order \n";
                goto label;
            }
        }
        i++;
        cout << "\n\t\tTo Buy More Items Press 1 Else 2 For Not ==> ";
        cin >> choice;
    } while (choice == 1);
    // calculation variables
    float amount = 0;
    float discount = 0;
    float total = 0;
    cout << "\n\t\t\t_______________Recipt_______________\n";
    cout << "\n\n\t"
        << "Code"
        << "\t"
        << "Name"
        << "\t"
        << "Price"
        << "\t"
        << "Quantity"
        << "\t"
        << "Amount"
        << "\t"
        << "Amount With Discount" << endl;
    for (int c = 0; c < i; c++)
    {
        fstream ifs;
        ifs.open("DataBase.txt");
        ifs >> pCode >> pName >> price >> dis;
        while (!ifs.eof())
        {
            if (array_items[c] == pCode)
            {
                amount = price * array_quant[c];
                discount = amount - (amount * dis / 100);
                total = total + discount;
                cout << "\n\t" << pCode << "\t" << pName << "\t" << price << "\t" ;
                cout << array_quant[c] ;
                cout <<"\t\t   "<<amount ; 
                cout <<"\t\t   "<<discount ; 
            }
            ifs >> pCode >> pName >> price >> dis;
        }
        ifs.close();
    }
    cout << endl;
    cout << "\n\n\t++++++++++++++++++++++++++++++++++++++++";
    cout << "\n\n\tTotal Bill is              " << total << endl;
    cout << "\n\n\t++++++++++++++++++++++++++++++++++++++++";
    // emptying memeory.......
    delete[] array_items;
    // delete[] array_quant;
}
int main()
{
    market m1;
    m1.menu();
    return 0;
}