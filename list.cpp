//Brennan Kirschner
//Program 1 - due 9/19/2019
/*This program uses a set of functions to complete several tasks
on data from a linked list. It recieves the initial data from a file
and allows the user to add and remove items from the list invarius ways,
print the first 30 items, and search for salon */
//REMEMBER TO REMOVE EXTRA COMMENTS YA DUNCE
#include <iostream>
#include <fstream>
#include<iomanip>

using namespace std;

//create the stuct that we will be using 
struct Employee {
	string emp_id;
	string first_name;
	string last_name;
	string gender;
	string email;
	double hourly_pay;
	Employee *Next;

	Employee() {
		emp_id = "";
		first_name = "";
		last_name = "";
		gender = "";
		email = "";
		hourly_pay = 0.0;
		Next = NULL;
	}

	Employee(string id, string first, string last, string sex, string mail, double pay) {
		emp_id = id;
		first_name = first;
		last_name = last;
		gender = sex;
		email = mail;
		hourly_pay = pay;
	}
};
//the linked list, i think
//holds all of the functions ecsept menu
class LinkedList
{
private:
	Employee * Head;

public:
	LinkedList() {
		Head = NULL;
	}

	void frontSert(string id, string first, string last, string sex, string mail, double pay) {
		Employee* Temp = new Employee(id, first, last, sex, mail, pay);

		if (Head == NULL) {
			Head = Temp;
		}
		else {
			Temp->Next = Head;
			Head = Temp;
		}
	}

	//this function allows the user to add a new employee the top of the list
	//asks for one piece of data at a time, long but easier to use
	void newemp()
	{
		string id;
		string first;
		string last;
		string sex;
		string mail;
		double pay = 0;

		cout << "Please Enter the following information:\n" << "ID number:";
		cin >> id;
		cout << "First Name:";
		cin >> first;
		cout << "Last Name:";
		cin >> last;
		cout << "Gender:";
		cin >> sex;
		cout << "Email:";
		cin >> mail;
		cout << "Hourly Pay:";
		cin >> pay;

		Employee* Temp = new Employee(id, first, last, sex, mail, pay);

		if (Head == NULL) {
			Head = Temp;
		}
		else {
			Temp->Next = Head;
			Head = Temp;
		}
	}

	//NOT WORKING - cause either it or i have no brain
	//function that searches the list for substring "salon"
	// and writes the email adresses
	/*bool searchlist(string micro) {
		Employee* Temp = Head;
		while (Temp != NULL) {
			return (Temp->email.find(micro) != std::string::npos);
		}
		Temp = Temp->Next;
	}*/


	//Funtion to remove the first employee in the list
	void removefirst() {
		if (Head != NULL) {
			if (Head->Next != NULL) {
				Employee *tmp = Head->Next;
				delete Head;
				Head = tmp;
			}
			else { delete Head; Head = NULL; }
		}
	}

	//fuction that prints the first 30 items in the list
	//trying to print to file but not working
	void print() {
		Employee* Temp = Head;
		int count = 0;

		while (Temp != NULL && count < 30) {
			cout << Temp->emp_id << ", " << Temp->first_name << ", " << Temp->last_name << ", " << Temp->gender << ", " << Temp->email << ", " << Temp->hourly_pay;
			if (Temp->Next) {
				cout << "\n";
			}
			Temp = Temp->Next;
			count++;
		}
	}

	//Not Working
	//function to remove an item from the list based on email 
	void RemoveEmp() {
		//kill me
	}
};

//provides a menu for easier testing/user understanding
//not sure if really necessary, but hey its kinda nice
int menu() {
	int choice = 0;
	while (choice <= 0 || choice > 5) {

		cout << "\nMain Menu\n" << "Please Choose an Option\n";
		cout << "1: Print first 30 Employies in List to file\n" << "2: Add Employee\n"
			<< "3: Remove first Employee\n" << "4: Delete Employee from list\n"
			<< "5: Quit\n";
		cin >> choice;
	}
	return choice;
}

int main()
{
	//create the outfile to print to and mark it as mine, my precious
	ofstream outfile;
	outfile.open("output.txt");
	outfile << "Brennan Kirschner\n\n";

	LinkedList EmpList;

	string empid;
	string first;
	string last;
	string email;
	string gender;
	double pay;

	string line;
	string *tokens;
	ifstream fin("employees.dat");

	while (!fin.eof()) {

		fin >> empid >> first >> last >> email >> gender >> pay;

		EmpList.frontSert(empid, first, last, email, gender, pay);
	}

	int choice = 0;

	//give the user the menu and process their choice into the right function
	while (choice != 5)
	{
		choice = menu();

		if (choice == 1)
		{
			EmpList.print();
		}
		if (choice == 2)
		{
			EmpList.newemp();
		}
		if (choice == 3)
		{
			EmpList.removefirst();
		}
		if (choice == 4)
		{
			EmpList.RemoveEmp();
		}

	}
	//cout << EmpList.searchlist("salon") << endl;
	//EmpList.searchlist();
	//Why wont you work!? am i stupid or blind

	outfile.close();
	return 0;
	//REMEMBER TO REMOVE EXTRA COMMENTS YA DUNCE
}
