#include <iostream>
#include <fstream>
using namespace std;
// Class
class shopping
{
private:
    int pcode;
    float price;
    float dis; // discount
    string pname;
    // methods
    void administrator();
    void add();
    void buyer();
    void edit();
    void receipt();
    void rem();
    void list();

public:
    void menu();
};
// first definition
void shopping::menu()
{
    int choice;
label:
    cout << endl
         << endl;
    cout << "\t\t\t\t$_________________________________$\n";
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t       $uperM@rket M@in Menu       \n";
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t$_________________________________$\n";
    cout << endl
         << endl;
    cout << "\t\t\t\t      @=====================@" << endl;
    cout << "\t\t\t\t      | 1==>) Administrator |" << endl;
    cout << "\t\t\t\t                             " << endl;
    cout << "\t\t\t\t      | 2==>) Buyer         |" << endl;
    cout << "\t\t\t\t                             " << endl;
    cout << "\t\t\t\t      | 3==>) Exit          |" << endl;
    cout << "\t\t\t\t      @=====================@" << endl;
    cout << endl;
    cout << "\t\t\t\tEnter your choice ==> ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        string email, password;
        cout << "\t\t\tPlease Login ==> " << endl;
        cout << "\n\t\tEnter the email    ==> ";
        cin >> email;
        cout << "\n\t\tEnter the password ==> ";
        cin >> password;
        if (email == "mr@email" && password == "raja123")
        {
            // cout << "You are administrator " << endl;
            administrator();
        }
        else
        {
            cout << endl;
            cout << "\t\t\tInvalid email and password " << endl;
        }
        break;
    }
    case 2:
    {
        buyer();
        break;
    }
    case 3:
    {
        exit(0);
        break;
    }
    default:
    {
        cout << "\t\tInvalid choice dear (Read carefully) " << endl;
        break;
    }
    }
    goto label;
}
// 2nd function
void shopping::administrator()
{
    int choice;
label:
    cout << endl
         << endl;
    cout << "\t\t\t\t+==========================+" << endl;
    cout << "\t\t\t\t|    Administrator Menu    |" << endl;
    cout << "\t\t\t\t+==========================+" << endl;
    cout << endl;
    cout << "\t\t@=======================@" << endl;
    cout << "\t\t| 1==>) Add Product     |" << endl;
    cout << "\t\t                         " << endl;
    cout << "\t\t| 2==>) Modify Product  |" << endl;
    cout << "\t\t                         " << endl;
    cout << "\t\t| 3==>) Delete Product  |" << endl;
    cout << "\t\t                         " << endl;
    cout << "\t\t| 4==>) Go To Menu      |" << endl;
    cout << "\t\t@=======================@" << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\tEnter your choice ";
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
        cout << "\t\tInvalid choice dear (Read carefully) " << endl;
        break;
    }
    }
    goto label;
}
// Third function
void shopping::buyer()
{
    int choice;
label:
    cout << endl
         << endl;
    cout << "\t\t\t\t+==========================+" << endl;
    cout << "\t\t\t\t|        Buyer Menu        |" << endl;
    cout << "\t\t\t\t+==========================+" << endl;
    cout << endl;
    cout << "\t\t@=======================@" << endl;
    cout << "\t\t                         " << endl;
    cout << "\t\t| 1==>) Buy Product     |" << endl;
    cout << "\t\t                         " << endl;
    cout << "\t\t| 2==>) Go To Menu      |" << endl;
    cout << "\t\t                         " << endl;
    cout << "\t\t@=======================@" << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\tEnter your choice ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        receipt();
        break;
    }
    case 2:
    {
        menu();
        break;
    }
    default:
    {
        cout << "\t\tInvalid choice dear (Read carefully) " << endl;
        break;
    }
    }
    goto label;
}
// Forth Function
void shopping::add()
{
label:
    float d;
    float p;
    int c;
    string n;
    int token = 0;
    cout << endl
         << endl;
    cout << "\t\t\t\t+==========================+" << endl;
    cout << "\t\t\t\t|        Add Product       |" << endl;
    cout << "\t\t\t\t+==========================+" << endl;
    cout << endl;
    cout << "\t\tEnter the code of product     ==> ";
    cin >> pcode;
    cout << "\t\tEnter the name of product     ==> ";
    cin >> pname;
    cout << "\t\tEnter the Price of product    ==> ";
    cin >> price;
    cout << "\t\tEnter the discount of product ==> ";
    cin >> dis;
    // opening the file
    ifstream ifs("database.txt");
    if (ifs.is_open())
    {
        ifs >> c >> n >> p >> d;
        while (!ifs.eof())
        {
            if (c == pcode)
            {
                token = 1;
            }
            ifs >> c >> n >> p >> d;
        }
        ifs.close();
    }
    else
    {
        cout << endl
             << endl;
        cout << "\t\tDataBase Error " << endl;
    }
    if (token == 1)
    {
        cout << "Duplicate Entry" << endl;
        goto label;
    }
    else
    {
        ofstream ofs;
        ofs.open("database.txt", ios::app);
        ofs << pcode << " " << pname << " " << price << " " << dis << endl;
        ofs.close();
    }
}
// fifth function
void shopping::edit()
{
    float d;
    float p;
    int c;
    string n;
    int token = 0;
    cout << endl
         << endl;
    cout << "\t\t\t\t+==========================+" << endl;
    cout << "\t\t\t\t|        Edit Product      |" << endl;
    cout << "\t\t\t\t+==========================+" << endl;
    cout << endl;
    int pkey;
    cout << "\t\t\tEnter the code of product ==> ";
    cin >> pkey;
    ifstream ifs;
    ifs.open("database.txt");
    ofstream ofs;
    ofs.open("database1.txt", ios::app);
    if (ifs.is_open())
    {
        ifs >> pcode >> pname >> price >> dis;
        while (!ifs.eof())
        {
            if (pkey == pcode)
            {
                cout << endl;
                cout << "Edit that record " << endl;
                cout << pcode << " " << pname << " " << price << " " << dis << endl;
                cout << endl
                     << endl;
                cout << "\t\tEnter the code of product     ==> ";
                cin >> c;
                cout << "\t\tEnter the name of product     ==> ";
                cin >> n;
                cout << "\t\tEnter the Price of product    ==> ";
                cin >> p;
                cout << "\t\tEnter the discount of product ==> ";
                cin >> d;
                token = 1;
                ofs << c << " " << n << " " << p << " " << d << endl;
            }
            else
            {
                ofs << pcode << " " << pname << " " << price << " " << dis << endl;
            }
            ifs >> pcode >> pname >> price >> dis;
        }
        ifs.close();
        ofs.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
    }
    if (token == 1)
    {
        cout << endl;
        cout << "Record Edited " << endl;
    }
    else
    {
        cout << endl;
        cout << "\t\t\tRecord not found " << endl;
    }
}
// Sixth function
void shopping::rem()
{
    int token = 0;
    cout << endl
         << endl;
    cout << "\t\t\t\t+============================+" << endl;
    cout << "\t\t\t\t|        Delete Product      |" << endl;
    cout << "\t\t\t\t+============================+" << endl;
    cout << endl;
    int pkey;
    cout << "\t\t\tEnter the code of product ==> ";
    cin >> pkey;
    ifstream ifs;
    ifs.open("database.txt");
    ofstream ofs;
    ofs.open("database1.txt");
    if (ifs.is_open())
    {
        ifs >> pcode >> pname >> price >> dis;
        while (!ifs.eof())
        {
            if (pkey == pcode)
            {
                cout << endl
                     << endl;
                cout << "Record is deleted " << endl;
                cout << "\t\t" << pcode << " " << pname << " " << price << " " << dis << endl;
                cout << endl
                     << endl;
                token = 1;
            }
            else
            {
                ofs << pcode << " " << pname << " " << price << " " << dis << endl;
            }
            ifs >> pcode >> pname >> price >> dis;
        }
        ifs.close();
        ofs.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
    }
    if (token == 1)
    {
        cout << endl
             << endl;
        cout << "\t\tRecord is deleted Successfully " << endl;
    }
    else
    {
        cout << endl
             << endl;
        cout << "Record not found " << endl;
    }
}
// seventh function
void shopping::list()
{
    cout << endl
         << endl;
    cout << "\t\t\t\t+==========================+" << endl;
    cout << "\t\t\t\t|        List Items's      |" << endl;
    cout << "\t\t\t\t+==========================+" << endl;
    cout << endl;
    cout << "\t\tItem Code\t\tItem Name\t\tItem Price" << endl;
    ifstream ifs;
    ifs.open("database.txt");
    if (ifs.is_open())
    {
        ifs >> pcode >> pname >> price >> dis;
        while (!ifs.eof())
        {
            cout << "\t\t" << pcode << "\t\t\t" << pname << "\t\t\t" << price << endl;
            ifs >> pcode >> pname >> price >> dis;
        }
        ifs.close();
        cout << endl
             << endl;
    }
    else
    {
        cout << endl;
        cout << "\t\tOOP's DataBase Error \n";
    }
}
// eight function
void shopping::receipt()
{
    int *arrq = new int[100];
    int *arrc = new int[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;
    ifstream ifs;
    ifs.open("database.txt");
    if (ifs.is_open())
    {
        ifs.close();
        list();
        cout << endl
             << endl;
        cout << "\t\t\t\t+==========================+" << endl;
        cout << "\t\t\t\t|         Place Order      |" << endl;
        cout << "\t\t\t\t+==========================+" << endl;
        cout << endl;
        do
        {
        /* code */
        label:
            cout << "Enter the product code     ===> ";
            cin >> arrc[c];
            cout << "Enter the product quantity ===> ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[i] == arrc[c])
                {
                    cout << "\t\tDuplicate Product Code. Please try again \n";
                    goto label;
                }
            }
            c++;
            cout << "To continue Press Y else N ==> ";
            cin >> choice;
        } while (choice == 'Y' || choice == 'y');
        cout << endl
             << endl;
        cout << "\t\t\t\t+==========================+" << endl;
        cout << "\t\t\t\t|         Receipt          |" << endl;
        cout << "\t\t\t\t+==========================+" << endl;
        cout << endl;
        cout << "\nProduct Name \tProduct Name\tProduct Quantity\tPrice\tAmount\tAmount After Discount";
        cout << endl;
        for (int i = 0; i < c; i++)
        {
            ifs.open("database.txt");
            ifs >> pcode >> pname >> price >> dis;
            while (!ifs.eof())
            {
                if (arrc[i] == pcode)
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total += dis;
                    cout << endl;
                    cout << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t\t" << price << "\t" << amount << "\t\t" << dis << endl;
                }
                ifs >> pcode >> pname >> price >> dis;
            }
            ifs.close();
        }
        // deallocating the memory
        delete[] arrq;
        delete[] arrc;
    }
    else
    {
        cout << endl
             << endl;
        cout << "\t\t\tDatabase error" << endl;
    }
}
// driver function
int main()
{
    shopping s;
    s.menu();
    return 0;
}
