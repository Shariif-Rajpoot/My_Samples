#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
char choice;
class candidates
{
public:
	string name;
	string address;
	long long num;
	int age;
	float height;
	float per;
} can;
int counter = 1, j = 1, r_no = 1, vacinces;
/* the counter values is used to reach the limit fo vacineces and
	j is used to display candidate number which is applying and
	the r_no used to display the registration number of selected
	candidate.
*/
void input();
// for input data in file;
void display();
// for display from file;
void view();
// for view the result
// for womens but the process is same
void inputW();
void displayW();
void viewW();
int counterW = 1, jW = 1, r_noW = 1, vacincesW;
int main()
{
	cout << "\t\t\t********&&&((((((THANKS FOR TAKING INTEREST IN PAK-ARMY))))))&&&********\n"
		 << endl;
	cout << "((((((WE ARE GOING TO HAIRING THE NEW  CANDIDATES FOR PAK-ARMY, WE ARE VERY THANKFUL TO YOU FOR TAKING INTEREST IN PAK-ARMY AND VISITING OUR WEBSITE))))))" << endl
		 << endl;
	cout << "\t\t\t********&&&((((((IF YOU WANT TO APPLY THAN PLEASE PRESS <(****A OR a****)> AND FOR GENERAL INFORMATION ABOUT PAK-ARMY <(PRESS I OR i)>))))))&&&********\n"
		 << endl;
	cout << "ENTER NUMBER OF VACINCES FOR YOUNG BOYS SOLDIERWHICH GOVERNMENT WANT FOR PAKISTAN ARMY: ";
	cin >> vacinces;
	cout << "ENTER NUMBER OF VACINCES FOR YOUNG GIRLS SOLDIERWHICH GOVERNMENT WANT FOR PAKISTAN ARMY: ";
	cin >> vacincesW;

mainMenu: // lable
	//	mainMenu1;
	cout << "\t\t\t\n**&*&*&*&*&(((PLEASE APPLY(PRESS A OR a))))**&*&*&*&*&\n\n\n";
	cout << "\t\t\tDEAR READ THE CONTENT WHICH IS WRITTEN ABOVE AND START \n";
	cout << "Enter you choice: ";
	cin >> choice;
	char Choice;
	if (choice == 'A' || choice == 'a')
	{
		char newChoice;
		cout << "Are You MAN OR WOMEN IF MEN (PRESS M OR m) && IF WOMEN(PRESS W OR w): ";
		cin >> newChoice;
		if (newChoice == 'M' || newChoice == 'm')
		{
			cout << "\t\t\tTHE ELIGIBILITY CRITERIA FOR PAK-ARMY CANDIDATE IS GIVEN BELOW:\n\n";
			cout << "\t\t\tMatric With Maximum Marks More Than 50%" << endl;
			cout << "\t\t\tMinimum Height More Than 5.6 feet" << endl;
			cout << "\t\t\tMininum Age More Than OR Equal to 18 \n";
			cout << "\t\t\t and less than OR equal to 20\n\n"
				 << endl;

			int entry;
		label:
			cout << "Enter 1 for enter data in form\n";
			cout << "Enter 2 for read data which you enter in form\n";
			cout << "Enter 3 for go to main menu:\n";
			cout << "Enter 4 for exit\n";
			cout << "Result will be uploaded soon\n\n"
				 << endl;
			cout << "Enter your choice: ";
			cin >> entry;

			if (entry == 1)
			{
				input();
			}
			else if (entry == 2)
			{
				display();
			}
			else if (entry == 3)
			{
				goto mainMenu;
			}
			else if (entry == 4)
			{
				exit(0);
			}
			goto label;
		}
		// FOR WOMEN
		else if (newChoice == 'W' || newChoice == 'w')
		{
			cout << "\t\t\tTHE ELIGIBILITY CRITERIA FOR PAK-ARMY CANDIDATE IS GIVEN BELOW:\n\n";
			cout << "\t\t\tMatric With Maximum Marks More Than 65%" << endl;
			cout << "\t\t\tMinimum Height More Than 5.2 feet" << endl;
			cout << "\t\t\tMininum Age More Than OR Equal to 20\n";
			cout << "\t\t\t and less than OR equal to 22\n\n"
				 << endl;

			int entry;
		menu:
			cout << "Enter 1 for enter data in form\n";
			cout << "Enter 2 for read data which you enter in form\n";
			cout << "Enter 3 for go to main menu\n";
			cout << "Enter 4 for exit\n";
			cout << "Result will be uploaded soon\n\n"
				 << endl;
			cout << "Enter your choice: ";
			cin >> entry;

			if (entry == 1)
			{
				inputW();
			}
			else if (entry == 2)
			{
				displayW();
			}
			else if (entry == 3)
			{
				goto mainMenu;
			}
			else if (entry == 4)
			{
				exit(0);
			}
			goto menu;
		}
	}
	else if (choice == 'I' || choice == 'i')
	{
		cout << "\t\t\t*****&&((((((The Pakistan Army has a regimental system but is operationally and geographically divided into command zones, with its most basic fields being its various corps. The Pakistani constitution mandates the role of the president of Pakistan as the civilian commander-in-chief of the Pakistani military.))))))&&&*****\n"
			 << endl;
	}
	else
	{
		exit(0);
	}
}

// for input
void input()
{

	char choice;

	do
	{

		cout << "You are candidate number " << j << endl;
		cout << "Enter your name :";
		cin >> can.name;
		cout << "Enter your Address: ";
		cin >> can.address;
		cout << "Enter your Phone Number:+92-";
		cin >> can.num;
		cout << "Enter your age: ";
		cin >> can.age;
		cout << "Enter your Height: ";
		cin >> can.height;
		cout << "Enter your matriculation percentage: ";
		cin >> can.per;

		if (can.height > 5.6 && can.per >= 50 && can.per <= 100)
		{
			if (can.age >= 18 && can.age <= 20)
			{
				j++;
				ofstream ofs1, ofs2;
				ofs1.open("Pak-candidate.txt");
				ofs2.open("selected-candidates.txt", ios::app);

				ofs1 << r_no++ << " candidate is\t" << can.name << "\t" << can.address << "\t" << can.num << "\t" << can.age << "\t" << can.height << "\t" << can.per << endl;
				ofs2 << "Registration number of " << --r_no << " candidate is\t" << can.name << "\t" << can.address << "\t+92-" << can.num << "\t" << can.age << "\t" << can.height << "\t" << can.per << "\tselected" << endl;

				ofs1.close();
				ofs2.close();
				if (counter == vacinces)
				{
					cout << "REQUIRED SEATS FOR THE BATCH OF THIS SEACTION HAVE FILLED \n\n"
						 << endl;
					cout << "The Result is uploaded PRESS (r OR R) to see the selected candidates: ";
					char result;
					cin >> result;
					if (result == 'r' || result == 'R')
					{
						view();
						break;
					}
				}
				counter++;
			}
		}

		else
		{
			cout << "" << endl;
		}

		cout << "Do the next candidate want to apply press (Y or y) and press any alphabet key you want for more options:  ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');
}
// for view data to applied candidate;
void display()
{
	ifstream ifs;
	ifs.open("Pak-candidate.txt");
	char ch;
	while (!ifs.eof())
	{
		ifs.get(ch);
		cout << ch;
	}
	ifs.close();
}
// for view result ;
void view()
{

	cout << "The selected candidates for the batch 2023 are \n\n\n"
		 << endl;
	ifstream ifs;
	ifs.open("selected-candidates.txt");

	char ch;
	while (!ifs.eof())
	{
		ifs.get(ch);
		cout << ch;
	}
	cout << "\n\n\n DEAR REQUIRED VACINCES FOR 2023 ARE DONE PLEASE READ THE MENU AND PRESS REQUIRED KEY TO EXIT" << endl;
	ifs.close();
}

////////////// all about women

// for input
void inputW()
{

	char choice;

	do
	{

		cout << "You are candidate number " << jW << endl;
		cout << "Enter your name :";
		cin >> can.name;
		cout << "Enter your Address: ";
		cin >> can.address;
		cout << "Enter your Phone Number:+92-";
		cin >> can.num;
		cout << "Enter your age: ";
		cin >> can.age;
		cout << "Enter your Height: ";
		cin >> can.height;
		cout << "Enter your matriculation percentage: ";
		cin >> can.per;

		if (can.height > 5.2 && can.per >= 65 && can.per <= 100)
		{
			if (can.age >= 20 && can.age <= 22)
			{
				jW++;
				ofstream ofs1, ofs2;
				ofs1.open("Pakwomen-candidate.txt");
				ofs2.open("selectedwomen-candidates.txt", ios::app);

				ofs1 << r_noW++ << " candidate is\t" << can.name << "\t" << can.address << "\t" << can.num << "\t" << can.age << "\t" << can.height << "\t" << can.per << endl;
				ofs2 << "Registration number of " << --r_noW << " candidate is\t" << can.name << "\t" << can.address << "\t+92-" << can.num << "\t" << can.age << "\t" << can.height << "\t" << can.per << "\tselected" << endl;

				ofs1.close();
				ofs2.close();
			}

			if (counterW == vacincesW)
			{
				cout << "REQUIRED SEATS FOR THE BATCH OF THIS SEACTION HAVE FILLED \n\n"
					 << endl;
				cout << "The Result is uploaded PRESS (r OR R) to see the selected candidates: ";
				char result;
				cin >> result;
				if (result == 'r' || result == 'R')
				{
					viewW();
					break;
				}
			}
			counterW++;
		}
		else
		{
			cout << "YOU DON'T FULL FIL THE REQUIREMENT FOR THE PAK-ARMY CANDIDATES YOU ARE NOT HIRED" << endl;
		}

		cout << "Do the next candidate want to apply press (Y or y) and press any alphabet key you want for more options:   ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');
}
// for view data to applied candidate;
void displayW()
{
	ifstream ifs;
	ifs.open("Pakwomen-candidate.txt");
	char ch;
	while (!ifs.eof())
	{
		ifs.get(ch);
		cout << ch;
	}
	ifs.close();
}
// for view result ;
void viewW()
{

	cout << "The selected candidates for the batch 2023 are \n\n\n"
		 << endl;
	ifstream ifs;
	ifs.open("selectedwomen-candidates.txt");

	char ch;
	while (!ifs.eof())
	{
		ifs.get(ch);
		cout << ch;
	}
	cout << "\n\n\n DEAR REQUIRED VACINCES FOR 2023 ARE DONE PLEASE READ THE MENU AND PRESS REQUIRED KEY TO EXIT" << endl;
	ifs.close();
}
