#include <iostream>
using namespace std;

int choice; // for choice enter by user
int quant;  // for quantity enter by user.
// quantity of items in hotel
int Q_rooms = 0, Q_pasta = 0, Q_burger = 0, Q_noodles = 0, Q_shakes = 0, Q_chicken = 0;
// Price of items sold from hotel
int T_rooms = 0, T_pasta = 0, T_burger = 0, T_noodles = 0, T_shakes = 0, T_chicken = 0;
// quantity of food each item..
int S_rooms = 0, S_pasta = 0, S_burger = 0, S_noodles = 0, S_shakes = 0, S_chicken = 0;

// function prototypes
void enter_quantity();
void main_menu();
void orders_and_details();
void sales_and_collections();
// driver function
int main()
{
    // main part
    // functions definitions
    enter_quantity();
    main_menu();
    return 0;
}
void enter_quantity()
{
    cout << "}======================================{" << endl;
    cout << "}===Enter the quantity for hotel======={" << endl;
    cout << "}Enter the rooms available{=============";
    cin >> Q_rooms;
    cout << "}Enter the pasta available{=============";
    cin >> Q_pasta;
    cout << "}Enter the burgers available{===========";
    cin >> Q_burger;
    cout << "}Enter the noodles available{===========";
    cin >> Q_noodles;
    cout << "}Enter the shake available{=============";
    cin >> Q_shakes;
    cout << "}Enter the chicken-rolls available{======";
    cin >> Q_chicken;
    cout << "}======================================={" << endl;
    system("cls");
}
void main_menu()
{
    cout << endl
         << endl;
    cout << "\t\t\t(@)=============>  Welcome to the menu page   <============(@)" << endl;
    cout << "\t\t\t1)==> }====================Rooms===================={" << endl;
    cout << "\t\t\t2)==> }===================Pasta====================={" << endl;
    cout << "\t\t\t3)==> }====================Burger==================={" << endl;
    cout << "\t\t\t4)==> }==================Noodles===================={" << endl;
    cout << "\t\t\t5)==> }====================Shake===================={" << endl;
    cout << "\t\t\t6)==> }================Chicken_Roll================={" << endl;
    cout << "\t\t\t7)==> }=Information regarding sales and collection=={" << endl;
    cout << "\t\t\t8)==> }======================Exit==================={" << endl;
    cout << "\t\t\tEnter your choice ==> ";
    cin >> choice;
    // to place order
    orders_and_details();
}
void orders_and_details()
{
    switch (choice)
    {
    case 1:
    {
        cout << "\t\t\tEnter the number of room/rooms --> ";
        cin >> quant;
        if (Q_rooms - S_rooms >= quant)
        {
            S_rooms += quant;
            T_rooms += quant * 1200;
            cout << "\t\tDear Customer\n\t\t\t" << quant << " room/rooms have alloted to you " << endl;
        }
        else
        {
            cout << "\t\tDear Customer Sorry\n\t\t\t Only " << Q_rooms - S_rooms << "room/rooms remain in hotel" << endl;
        }
        break;
    }
    case 2:
    {
        cout << "\t\t\tEnter the quantity of pasta --> ";
        cin >> quant;
        if (Q_pasta - S_pasta >= quant)
        {
            S_pasta += quant;
            T_pasta += quant * 250;
            cout << "\t\tDear Customer\n\t\t\t" << quant << " pastas/pasta is your order" << endl;
        }
        else
        {
            cout << "\t\tDear Customer Sorry\n\t\t\t Only " << Q_pasta - S_pasta << "pasta/pastas remain in hotel" << endl;
        }
        break;
    }
    case 3:
    {
        cout << "\t\t\tEnter the quantity of burger/burgers --> ";
        cin >> quant;
        if (Q_burger - S_burger >= quant)
        {
            S_burger += quant;
            T_burger += quant * 120;
            cout << "\t\tDear Customer\n\t\t\t" << quant << " burgers/burger is your order" << endl;
        }
        else
        {
            cout << "\t\tDear Customer Sorry\n\t\t\t Only " << Q_burger - S_burger << "burger/burgers remain in hotel" << endl;
        }
        break;
    }
    case 4:
    {
        cout << "\t\t\tEnter the quantity of noodle mugs--> ";
        cin >> quant;
        if (Q_noodles - S_noodles >= quant)
        {
            S_noodles += quant;
            T_noodles += quant * 140;
            cout << "\t\tDear Customer\n\t\t\t" << quant << " noodles/noodle mugs are your order" << endl;
        }
        else
        {
            cout << "\t\tDear Customer Sorry\n\t\t\t Only " << Q_noodles - S_noodles << "noodle/noodles mugs remain in hotel" << endl;
        }
        break;
    }
    case 5:
    {
        cout << "\t\t\tEnter the quantity of snakes --> ";
        cin >> quant;
        if (Q_shakes - S_shakes >= quant)
        {
            S_shakes += quant;
            T_shakes += quant * 120;
            cout << "\t\tDear Customer\n\t\t\t" << quant << " shake/shakes are your order" << endl;
        }
        else
        {
            cout << "\t\tDear Customer Sorry\n\t\t\t Only " << Q_shakes - S_shakes << "shake/shakess mugs remain in hotel" << endl;
        }
        break;
    }
    case 6:
    {
        cout << "\t\t\tEnter the quantity of chicken_Rolls --> ";
        cin >> quant;
        if (Q_chicken - S_chicken >= quant)
        {
            S_chicken += quant;
            T_chicken += quant * 150;
            cout << "\t\tDear Customer\n\t\t\t" << quant << " chicken roll/rolls are your order" << endl;
        }
        else
        {
            cout << "\t\tDear Customer Sorry\n\t\t\t Only " << Q_chicken - S_chicken << "roll/rolls remain in hotel" << endl;
        }
        break;
    }
    case 7:
    {
        sales_and_collections();
        break;
    }
    case 8:
    {
        cout << "\n\t\tThanks for visiting owr hotel " << endl
             << endl;
        exit(0);
        break;
    }
    default:
    {
        cout << "\n\t\t}====Please select the numbers that are mention above===={" << endl;
        break;
    }
    }
    // switch ends
    //  go to main menu
    main_menu();
}
void sales_and_collections()
{
    cout << "\n\n\t\t<===The detail of sales and collection is as follow===>" << endl;
    cout << "\n\t\t\t<==============Details for room/rooms=================>" << endl;
    cout << "\t\t Number of room/rooms we had                >====> " << Q_rooms << endl;
    cout << "\t\t Number of room/rooms we gave for rent      >====> " << S_rooms << endl;
    cout << "\t\t Number of room/rooms remained              >====> " << Q_rooms - S_rooms << endl;
    cout << "\t\t Total collection for the day               >====> " << T_rooms << endl;

    cout << "\n\t\t\t<==============Details for pasta/pastas=================>" << endl;
    cout << "\t\t Number of pasta/pastas we had              >====> " << Q_pasta << endl;
    cout << "\t\t Number of pasta/pastas sold                >====> " << S_pasta << endl;
    cout << "\t\t Number of pasta remained                   >====> " << Q_pasta - S_pasta << endl;
    cout << "\t\t Total collection for the day               >====> " << T_pasta << endl;

    cout << "\n\t\t\t<==============Details for burger/burgers=================>" << endl;
    cout << "\t\t Number of burger/burgers we had            >====> " << Q_burger << endl;
    cout << "\t\t Number of burger/burgers sold              >====> " << S_burger << endl;
    cout << "\t\t Number of burger remained                  >====> " << Q_burger - S_burger << endl;
    cout << "\t\t Total collection for the day               >====>  " << T_burger << endl;

    cout << "\n\t\t\t<==============Details for shake/shakes=================>" << endl;
    cout << "\t\t Number of shake/shakes we had              >====> " << Q_shakes << endl;
    cout << "\t\t Number of shakes/shakes sold               >====> " << S_shakes << endl;
    cout << "\t\t Number of shakes remained                  >====> " << Q_shakes - S_shakes << endl;
    cout << "\t\t Total collection for the day               >====> " << T_shakes << endl;

    cout << "\n\t\t\t<==============Details for noodle mug/mugs=================>" << endl;
    cout << "\t\t Number of noodle mug/mugs we had           >====> " << Q_noodles << endl;
    cout << "\t\t Number of noodle mug/mugs sold             >====> " << S_noodles << endl;
    cout << "\t\t Number of noodle mug/mugs remained         >====> " << Q_noodles - S_noodles << endl;
    cout << "\t\t Total collection for the day               >====> " << T_noodles << endl;

    cout << "\n\t\t\t<==============Details for chicken-roll/rolls=================>" << endl;
    cout << "\t\t Number of chicken-roll/rolls we had        >====> " << Q_chicken << endl;
    cout << "\t\t Number of chicken-roll/rolls sold          >====> " << S_chicken << endl;
    cout << "\t\t Number of chicken-roll/rolls remained      >====> " << Q_chicken - S_chicken << endl;
    cout << "\t\t Total collection for the day               >====> " << T_chicken << endl;

    cout << "\n\t\t\t<=============Total Cash Of Day=================>" << endl;
    int total = T_burger + T_chicken + T_noodles + T_pasta + T_rooms + T_shakes;
    cout << "\t\t Full collection for the day               >====> " << total << endl;
}
