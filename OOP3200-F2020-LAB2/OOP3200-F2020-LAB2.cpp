//**************************************
//OOP3200-F2020-LAB1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Group 2: Najeebulla Hussaini (100596841) , Andre Agrippa(100756090)
// Purpose: The purpose of this lab is to create a class called WorkTicket which 
//		    will be used to support an IT support tracking application to store information about
//          client requests.
//Date: 2020-09-18
//**************************************

//#include "pch.h"
#include <iostream> 		// cin, cout
#include <iomanip>			// fixed, setprecision()
#include <sstream> 			// stringstream
#include <cmath>			// sqrt()
#include <limits>			// INT_MAX
#include <stdexcept>		// out_of_range
#include "MyConsoleInput.h"
using namespace std;

class WorkTicket {
	//Attributes
private:
	//private data members
	int workTicketNumber;
	string clientID;
	int workTicketDateDay;
	int workTicketDateMonth;
	int workTicketDateYear;
	string issueDescription;

public:
	//Mutators
	//Declarations
	void SetWorkTicketNumber(int workTicektNumber);
	void SetClientID(string clientID);
	void SetWorkTicketDateDay(int day);
	void SetWorkTicketDateMonth(int month);
	void SetWorkTicketDateYear(int year);
	void SetIssueDescription(string description);
	bool SetWorkTicket(int workTicketNumber, string clientID, int workTicketDateDay, int workTicketDateMonth,
	int workTicketDateYear, string issueDescription);
	WorkTicket(const WorkTicket& ticket2);
	//Accessors
	//Declaration
	int GetWorkTicketNumber();
	string GetClientID();
	int GetWorkTicketDateDay();
	int GetWorkTicketDateMonth();
	int GetWorkTicketDateYear();
	string getIssueDescription();
	string ShowWorkTicket() const;
	//Constructors
	//Default
	WorkTicket();
	//Parameterized Constructor
	WorkTicket(int workTicketNumber, string clientID, int workTicketDateDay, int workTicketDateMonth, int workTicketDateYear, string issueDescription);
};
//Main
int main()
{
	//Input variables for ticket attributes
	int inputTicketNumber;
	int inputDay;
	int inputMonth;
	int inputYear;
	string inputClientID;
	string inputClientIssue;

	//Constants
	const int NUM_TICKETS = 3; // total tickets being made

	//Objects
	WorkTicket ticket[NUM_TICKETS];
	WorkTicket ticket2 = WorkTicket();
	cout << "Default ticket example :" << endl;
	cout << ticket2.ShowWorkTicket() << endl;
	cout << "===================================================\n";

	cout << "You will be making " << NUM_TICKETS << " tickets today..." << endl;

	try
	{
		/*Input loop, prompts user for ticket attributes using getline() for strings and
		 *ConsoleInput::ReadInteger() for integers
		 */
		for (int i = 0; i < NUM_TICKETS; i++)
		{
			cout << "\nProcessing Ticket #" << i + 1 << endl;
			cout << "\nEnter your ticket number (Whole, positive number):";
			inputTicketNumber = ConsoleInput::ReadInteger(1);
			cout << "Enter your ticket ID (alpha-numeric):";
			cin.ignore();
			getline(cin >> std::ws, inputClientID);
			cout << "\nEnter the day the ticket was opened:(min.1 max.31)";
			inputDay = ConsoleInput::ReadInteger(1, 31);
			cout << "\nEnter the month the ticket was opened:(min.1 max.12)";
			inputMonth = ConsoleInput::ReadInteger(1, 12);
			cout << "\nEnter the year the ticket was opened:(min.2000 max.2099)";
			inputYear = ConsoleInput::ReadInteger(2000, 2099);
			cout << "\nEnter your work issue description:";
			cin.ignore();
			getline(cin >> std::ws, inputClientIssue);

			//once ticket has all valid inputs, place into object array

			if (ticket[i].SetWorkTicket(inputTicketNumber, inputClientID, inputDay, inputMonth, inputYear, inputClientIssue) == true)
			{
				//Ticket confirmation
				cout << "Ticket #" << i + 1 << " processed." << endl;
				cout << "Press any key to continue...";
				cin.ignore();
				system("CLS");
			}
		}

		//Output loop
		for (int i = 0; i < NUM_TICKETS; i++)
		{
			cout << "TICKET ENTRY:" << i + 1 << endl;
			cout << ticket[i].ShowWorkTicket() << endl;
		}
	}
	
	
	//Will catch any invalid inputs and give an error
	catch (exception& ex)
	{
		cerr << ex.what() << "Ending the program." << endl;
	}
	
	WorkTicket ticket3 = ticket[0];
	cout << ticket3.ShowWorkTicket();
}

WorkTicket::WorkTicket(const WorkTicket& ticket2)
{
	//SetWorkTicket(workTicketNumber, clientID, workTicketDateDay, workTicketDateMonth, workTicketDateYear, issueDescription);
	workTicketDateDay = ticket2.workTicketDateDay;
	workTicketDateMonth = ticket2.workTicketDateMonth;
	workTicketDateYear = ticket2.workTicketDateYear;
	workTicketNumber = ticket2.workTicketNumber;
	clientID = ticket2.clientID;
	issueDescription = ticket2.issueDescription;

	cout << "\nA WorkTicket object was COPIED.\n";
	
}


//Class Definition Section
//Default Constructor definition
WorkTicket::WorkTicket() {
	this->workTicketNumber = 0;
	this->workTicketDateDay = 1;
	this->workTicketDateMonth = 1;
	this->workTicketDateYear = 2000;
	this->clientID = "";
	this->issueDescription = "";
}
//Parametized contructor definition
WorkTicket::WorkTicket(int workTicketNumber, string clientID, int workTicketDateDay, int workTicketDateMonth, int workTicketDateYear,
	string issueDescription) {
	SetWorkTicket(workTicketNumber, clientID, workTicketDateDay, workTicketDateMonth,
		workTicketDateYear, issueDescription);
}
//Set work ticket boolean for validation and storing user input definition 
bool WorkTicket::SetWorkTicket(int workTicketNumber, string clientID, int workTicketDateDay, int workTicketDateMonth,
	int workTicketDateYear, string issueDescription) {
	if (workTicketNumber >= 1) {
		SetWorkTicketNumber(workTicketNumber);
		if (clientID.size() >= 1) {
			SetClientID(clientID);
			if (workTicketDateDay >= 1 && workTicketDateDay <= 31) {
				SetWorkTicketDateDay(workTicketDateDay);
				if (workTicketDateMonth >= 1 && workTicketDateMonth <= 12) {
					SetWorkTicketDateMonth(workTicketDateMonth);
					if (workTicketDateYear >= 2000 && workTicketDateYear <= 2099) {
						SetWorkTicketDateYear(workTicketDateYear);
						if (issueDescription.size() >= 1) {
							SetIssueDescription(issueDescription);
							return true;
						}
						else {
							cout << "\nInvalid issue description";
							return false;
						}
					}
					else {
						cout << "\nERROR, Year is out of range, must be between 2000 and 2099";
						return false;
					}
				}
				else {
					cout << "\nERROR, Month is out of range, must be between 1 and 12";
					return false;
				}
			}
			else {
				cout << "\nERROR, Day is out of range, must be between 1 and 31";
				return false;
			}
		}
		else {
			cout << "\nInvalid clientID";
			return false;
		}
	}
	else {
		cout << " \nInvalid ticket number. Ticket number must be a whole, positive number";
		return false;
	}
}
//Mutators definitions
void WorkTicket::SetWorkTicketNumber(int ticketNumber) {
	this->workTicketNumber = ticketNumber;
}
void WorkTicket::SetClientID(string clientID) {
	this->clientID = clientID;
}
void WorkTicket::SetIssueDescription(string issueDescription) {
	this->issueDescription = issueDescription;
}
void WorkTicket::SetWorkTicketDateDay(int day) {
	this->workTicketDateDay = day;
}
void WorkTicket::SetWorkTicketDateMonth(int month) {
	this->workTicketDateMonth = month;
}
void WorkTicket::SetWorkTicketDateYear(int year) {
	this->workTicketDateYear = year;
}
//Accessors definitions
int WorkTicket::GetWorkTicketNumber() {
	return this->workTicketNumber;
}
string WorkTicket::GetClientID() {
	return this->clientID;
}
string WorkTicket::getIssueDescription() {
	return this->issueDescription;
}
int WorkTicket::GetWorkTicketDateDay() {
	return this->workTicketDateDay;
}
int WorkTicket::GetWorkTicketDateMonth() {
	return this->workTicketDateMonth;
}
int WorkTicket::GetWorkTicketDateYear() {
	return this->workTicketDateYear;
}
//Output to show the object attributes 
string WorkTicket::ShowWorkTicket() const {
	// declare a stringstream object
	stringstream strOut;
	// build the string
	strOut << "Work Ticket Number : " << workTicketNumber << "\nClientID : " << clientID <<
		"\nWork Ticket Date : " << workTicketDateDay << "/" << workTicketDateMonth << "/" << workTicketDateYear <<
		"\nIssue Description : " << issueDescription << "\n";
	return strOut.str();
}

