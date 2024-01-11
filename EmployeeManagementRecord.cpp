#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class user
{
private:
    int id;
    string firstName;
    string lastName;
    int age;
    string eMail;
    void input();
    void write();
    void edit();
    void rem();
public:
    void menu();
};
void user :: menu()
{
    cout<<endl<<endl;
    cout<<"\t\t\t\t!____________________________!\n";
    cout<<"\t\t\t\t|                            |\n";
    cout<<"\t\t\t\t|                            |\n";
    cout<<"\t\t\t\t|      Main Menu --->        |\n";
    cout<<"\t\t\t\t|                            |\n";
    cout<<"\t\t\t\t!____________________________!\n";
    cout<<"\t\t\t\t|============================|\n";
    cout<<endl<<endl;
    m://label
    cout<<"\t\tEnter 1 To INPUT EMPLOYEE RECORD \n";
    cout<<"\t\tEnter 2 To  Read EMPLOYEE RECORD \n";
    cout<<"\t\tEnter 3 To  Edit EMPLOYEE RECORD \n";
    cout<<"\t\tEnter 4 To  Delete EMPLOYEE RECORD \n";
    cout<<"\t\tEnter 5 To EXIT \n";
    cout<<"\n\tEnter your choice ==> ";
    int choice; cin>>choice;
    switch(choice)
    {
        case 1:
        {
            input();
        }
        case 2:
        {
            write();
        }
        case 3:
        {
            edit();
        }
        case 4:
        {
            rem();
        }
        case 5:
        {
            exit(0);
        }
        default:
        {
            cout<<"\t\t\nPlease Select From The Given Options \n";
            break;
        }
    }
    goto m;
}
void user :: input()
{
    
    ofstream ofs;
    ofs.open("record.txt",ios::app);
    int i = 0;
    char choice;
    do
    {
        /* code */
        cout<<"\t\tID OF EMPLOYEE "<<i+1<<" ==> ";cin>>id;
        cout<<"\t\tFirst_Name OF EMPLOYEE "<<i+1<<" ==> ";cin>>firstName;
        cout<<"\t\tLast_Name OF EMPLOYEE "<<i+1<<" ==> ";cin>>lastName;
        cout<<"\t\tAge OF EMPLOYEE "<<i+1<<" ==> ";cin>>age;
        cout<<"\t\tEmail OF EMPLOYEE "<<i+1<<" ==> ";cin>>eMail;
        if(ofs.is_open())
        {
            ofs<<id<<" "<<firstName<<" "<<lastName<<" "<<age<<" "<<eMail<<endl;
        }
        else
        {
            ofs.open("record.txt",ios::app);
            ofs<<id<<firstName<<lastName<<age<<eMail<<endl;
        }
        cout<<"\tTo Enter Data For More Employees Press (y || Y) else N/n ==>";
        cin>>choice;
        i++;
    } while (choice == 'y'|| choice == 'Y');
    ofs.close();
    //main menu;
    menu();
}
//second func
void user ::write()
{
    ifstream ifs;
    ifs.open("record.txt");
    if(ifs.is_open())
    {
        int id;
        string fn;
        string ln;
        int age;
        string em;
        ifs>>id>>fn>>ln>>age>>em;
        while(!ifs.eof())
        {
            cout<<endl<<endl;
            cout<<"Employee Record \n\n";
            cout<<endl;
            cout<<"Employee ID IS "<<id<<endl;
            cout<<"Employee First_Name IS "<<fn<<endl;
            cout<<"Employee Last_Name IS "<<ln<<endl;
            cout<<"Employee Age IS "<<age<<endl;
            cout<<"Employee Email IS "<<em<<endl;
            ifs>>id>>fn>>ln>>age>>em;
        }
        ifs.close();
    }
    else
    {
        cout<<"Sorry Issue In DataBase\n\nTry again later == "<<endl;
    }
    ifs.close();
    //menu
    menu();
}
void user::edit()
{
    cout<<"\n\n\t\t<==========================>";
    cout<<"\n\n\t\t|        Edit Menu         |";
    cout<<"\n\n\t\t<==========================>";
    ifstream ifs;
    ifs.open("record.txt");
    ofstream ofs;
    ofs.open("copy.txt");
    if(ifs.is_open())
    {
        int idey,code;
        string fn;
        string ln;
        int a;//age
        string em;
        ifs>>id>>firstName>>lastName>>age>>eMail;
        cout<<"\n\n\t\tEnter the id of employee to edit => ";
        cin>>code;
        while(!ifs.eof())
        {
            if(code == id)
            {
                cout<<endl<<id<<" "<<firstName<<" "<<lastName<<" "<<age<<" "<<eMail<<endl;
                cout<<"\n\n\t\tEdit this ==> \n";
                cout<<"\t\tID OF EMPLOYEE  ==> ";cin>>idey;
                cout<<"\t\tFirst_Name OF EMPLOYEE  ==> ";cin>>fn;
                cout<<"\t\tLast_Name OF EMPLOYEE  ==> ";cin>>ln;
                cout<<"\t\tAge OF EMPLOYEE  ==> ";cin>>a;
                cout<<"\t\tEmail OF EMPLOYEE  ==> ";cin>>em;
                ofs<<idey<<" "<<fn<<" "<<ln<<" "<<a<<" "<<em<<endl;
            }
            else
            {
                ofs<<id<<" "<<firstName<<" "<<lastName<<" "<<age<<" "<<eMail<<endl;
            }
            ifs>>id>>firstName>>lastName>>age>>eMail;
        }
    }
    else
    {
        cout<<"\n\n\t\t\tDataBase Error"<<endl;
    }
    ifs.close();
    ofs.close();
    //
    remove("record.txt");
    rename("copy.txt","record.txt");
    //menu option
    menu();
}
void user :: rem()
{
    cout<<"\n\n\t\t<==========================>";
    cout<<"\n\n\t\t|        Delete Menu         |";
    cout<<"\n\n\t\t<==========================>";
    int code;
    cout<<"\n\n\n\t\t\tEnter The Id Of The Employee To Delete ==>  ";
    cin>>code;
    ifstream ifs;
    ifs.open("record.txt");
    ofstream ofs;
    ofs.open("copy.txt");
    if(ifs.is_open())
    {
        ifs>>id>>firstName>>lastName>>age>>eMail;
        while(!ifs.eof())
        {
            if(code == id)
            {
                cout<<endl;
                cout<<endl<<id<<" "<<firstName<<" "<<lastName<<" "<<age<<" "<<eMail<<endl;
                cout<<"\n\n\t\tThis Record Is Deleted \n";
            }
            else
            {
                ofs<<id<<" "<<firstName<<" "<<lastName<<" "<<age<<" "<<eMail<<endl;
            }
            ifs>>id>>firstName>>lastName>>age>>eMail;
        } 
    }
    else
    {
        cout<<"\n\n\n\t\tDataBase Erro \n\t\t\t Try Again Later\n";
    }
    ifs.close();
    ofs.close();
    remove("record.txt");
    rename("copy.txt","record.txt");
    /*menu*/   menu();
}
int main()
{
    user u1;
    u1.menu();
    return 0;
}