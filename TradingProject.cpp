/*
    Shop of trading of home appliances....
*/
#include <iostream>
#include <ctime> //to display time
using namespace std;
int main()
{
    char start;
    float shop(void);
    char choice;
startL: // label
    cout << "Please press H or h to start shopping for Home Appliances ==> ";
start: // label
    cin >> start;

    if (start == 'H' || start == 'h')
    {
        float total = shop();
        time_t t = time(0); // it return the time with the current calender
        tm *tptr = localtime(&t);
        cout << "Bill Date : ";
        cout << tptr->tm_mday << "/";        // represents day
        cout << 1 + tptr->tm_mon << "/";     // months in year
        cout << 1900 + tptr->tm_year << "/"; // years since 1900
        cout << "Bill time: " << tptr->tm_hour << ":" << tptr->tm_min << ":" << tptr->tm_sec << endl;
        cout << "Total Bill Amount ==> " << total << endl;
        if (total > 50000 && total < 100000)
        {
            total -= (0.05 * total);
            cout << "Total discount : 5%" << endl;
        }
        else if (total > 100000 && total < 125000)
        {
            total -= (0.1 * total);
            cout << "Total discount : 10%" << endl;
        }
        else if (total > 125000 && total < 150000)
        {
            total -= (0.25 * total);
            cout << "Total discount :  25%" << endl;
        }
        else if (total > 150000)
        {
            total -= (0.5 * total);
            cout << "Total discount :  50%" << endl;
        }
        cout << "Total bill amount is " << total << endl;
    Again: // label
        cout << "Do you want shopping again y or n  " << endl;
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            goto startL;
        }
        else if (choice == 'n' || choice == 'N')
        {
            cout << "Thanks for shopping " << endl;
        }
        else
        {
            cout << "You have entered the wrong option, please press H" << endl;
            goto Again;
        }
    }
    else
    {
        cout << "You have entered wrong option, please press H to start again " << endl;
        goto start;
    }
    return 0;
}
float shop()
{
shop:
    char choice;
    char product;
    int quantity;
    float bill = 0;
itemLevel:
    cout << "**************************Welcome************************" << endl;
    cout << "__Please follow the instructions__" << endl;
    cout << "___1) Please Enter r to order Refrigerator" << endl;
    cout << "___2) Please Enter w to order Washing Machine" << endl;
    cout << "___3) Please Enter t to order Television" << endl;
    cout << "___4) Please Enter m to order Microwave" << endl;
    cout << "___5) Please Enter a to order Air conditioner" << endl;
    cin >> choice;
    if (choice == 'r' || choice == 'R' || choice == 'w' || choice == 'W' || choice == 't' || choice == 'T' || choice == 'm' || choice == 'M' || choice == 'a' || choice == 'A')
    {
        if (choice == 'r' || choice == 'R')
        {
        refrigerator:
            cout << "_____Refrigerator details______" << endl;
            cout << "}=> 1) Whirlpool    ==>  Price : 40000 " << endl;
            cout << "}=> 2) Samsung      ==>  Price : 25000 " << endl;
            cout << "}=> 3) Haier        ==>  Price : 20000 " << endl;
            cout << "}=> 4) Voltas       ==>  Price : 18000 " << endl;
            cout << "}=> 5) Godrej       ==>  Price : 30000 " << endl;
            cout << "}=> 6) Panasonic    ==>  Price : 35000 " << endl;
            cout << "Please Enter Your Choice ";
            cin >> product;
            if (product == '1')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 40000;
            }
            else if (product == '2')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 25000;
            }
            else if (product == '3')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 20000;
            }
            else if (product == '4')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 18000;
            }
            else if (product == '5')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 30000;
            }
            else if (product == '6')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 35000;
            }
            else
            {
                cout << "You have entered the wrong option " << endl;
                goto refrigerator;
            }
        }

        else if (choice == 'w' || choice == 'W')
        {
        machine:
            cout << "_____Washing Machine details______" << endl;
            cout << "}=> 1) Bosch      ==>  Price : 40000 " << endl;
            cout << "}=> 2) LG         ==>  Price : 25000 " << endl;
            cout << "}=> 3) IFB        ==>  Price : 20000 " << endl;
            cout << "}=> 4) Haier      ==>  Price : 10000 " << endl;
            cout << "}=> 5) Maytag     ==>  Price : 30000 " << endl;
            cout << "}=> 6) Samsung    ==>  Price : 35000 " << endl;
            cout << "Please Enter Your Choice " << endl;
            cin >> product;
            if (product == '1')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 40000;
            }
            else if (product == '2')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 25000;
            }
            else if (product == '3')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 20000;
            }
            else if (product == '4')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 10000;
            }
            else if (product == '5')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 30000;
            }
            else if (product == '6')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 35000;
            }
            else
            {
                cout << "You have entered the wrong option " << endl;
                goto machine;
            }
        }

        else if (choice == 't' || choice == 'T')
        {
        television:
            cout << "_____Television details______" << endl;
            cout << "}=> 1) Sony         ==>  Price : 40000 " << endl;
            cout << "}=> 2) Samsung      ==>  Price : 25000 " << endl;
            cout << "}=> 3) LG           ==>  Price : 20000 " << endl;
            cout << "}=> 4) TCL          ==>  Price : 10000 " << endl;
            cout << "}=> 5) Sharp        ==>  Price : 30000 " << endl;
            cout << "}=> 6) Panasonic    ==>  Price : 35000 " << endl;
            cout << "Please Enter Your Choice " << endl;
            cin >> product;
            if (product == '1')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 40000;
            }
            else if (product == '2')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 25000;
            }
            else if (product == '3')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 20000;
            }
            else if (product == '4')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 10000;
            }
            else if (product == '5')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 30000;
            }
            else if (product == '6')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 35000;
            }
            else
            {
                cout << "You have entered the wrong option " << endl;
                goto television;
            }
        }

        else if (choice == 'm' || choice == 'M')
        {
        microwave:
            cout << "_____Microwave details______" << endl;
            cout << "}=> 1) LG              ==>  Price : 40000 " << endl;
            cout << "}=> 2) IFB             ==>  Price : 25000 " << endl;
            cout << "}=> 3) Whirlpool       ==>  Price : 20000 " << endl;
            cout << "}=> 4) Panasonic       ==>  Price : 10000 " << endl;
            cout << "}=> 5) Bajaj           ==>  Price : 30000 " << endl;
            cout << "}=> 6) Samsung         ==>  Price : 35000 " << endl;
            cout << "Please Enter Your Choice " << endl;
            cin >> product;
            if (product == '1')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 40000;
            }
            else if (product == '2')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 25000;
            }
            else if (product == '3')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 20000;
            }
            else if (product == '4')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 10000;
            }
            else if (product == '5')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 30000;
            }
            else if (product == '6')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 35000;
            }
            else
            {
                cout << "You have entered the wrong option " << endl;
                goto microwave;
            }
        }

        else if (choice == 'a' || choice == 'A')
        {
        conditinor:
            cout << "_____Air Conditioner details______" << endl;
            cout << "}=> 1) Daikin      ==>  Price : 40000 " << endl;
            cout << "}=> 2) Voltas      ==>  Price : 25000 " << endl;
            cout << "}=> 3) Hitachi     ==>  Price : 20000 " << endl;
            cout << "}=> 4) O General   ==>  Price : 10000 " << endl;
            cout << "}=> 5) Lloyd       ==>  Price : 30000 " << endl;
            cout << "}=> 6) Samsung     ==>  Price : 35000 " << endl;
            cout << "Please Enter Your Choice " << endl;
            cin >> product;
            if (product == '1')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 40000;
            }
            else if (product == '2')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 25000;
            }
            else if (product == '3')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 20000;
            }
            else if (product == '4')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 10000;
            }
            else if (product == '5')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 30000;
            }
            else if (product == '6')
            {
                cout << "Enter the quantity of the product ";
                cin >> quantity;
                bill += quantity * 35000;
            }
        }
        else
        {
            cout << "You have entered the wrong option " << endl;
            goto conditinor;
        }
    }
    else
    {
        cout << "You have entered the wrong option please try again " << endl;
        goto shop;
    }
    return bill;
}