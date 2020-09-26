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
	
private:
	//Attributes
	//private data members
	int workTicketNumber;
	string clientID;
	int workTicketDateDay;
	int workTicketDateMonth;
	int workTicketDateYear;
	string issueDescription;

public:
	
	//Mutators
	void SetWorkTicketNumber(int workTicektNumber);
	void SetClientID(string clientID);
	void SetWorkTicketDateDay(int day);
	void SetWorkTicketDateMonth(int month);
	void SetWorkTicketDateYear(int year);
	void SetIssueDescription(string description);
	bool SetWorkTicket(int workTicketNumber, string clientID, int workTicketDateDay, int workTicketDateMonth,
	int workTicketDateYear, string issueDescription);
	//
	
	
	//Friend overload
	friend std::ostream& operator << (std::ostream& out, const WorkTicket& ticket);
	friend std::istream& operator >>(std::istream& in, WorkTicket& point);

	//Comaprison
	bool operator==(const WorkTicket& other_ticket) const;
	
	//Accessors
	int GetWorkTicketNumber() const;
	string GetClientID() const;
	int GetWorkTicketDateDay() const;
	int GetWorkTicketDateMonth() const;
	int GetWorkTicketDateYear() const;
	WorkTicket GetWorkTicket() const;
	string GetIssueDescription() const;
	string ShowWorkTicket() const;
	
	//Constructors
	//Default
	WorkTicket();
	//Parameterized Constructor
	WorkTicket(int workTicketNumber, string clientID, int workTicketDateDay, int workTicketDateMonth, int workTicketDateYear, string issueDescription);
	
	//Copy constructor
	WorkTicket(const WorkTicket& ticket2);
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

	bool isValid;

	//Constants
	const int NUM_TICKETS = 3; // total tickets being made

	//Objects
	WorkTicket ticket[NUM_TICKETS];//users workticket arr
	WorkTicket default_ticket = WorkTicket();//default workticket
	
	cout << "Default ticket example :" << endl;
	cout << default_ticket << endl;
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
			
			cout << "\nEnter your ticket ID (alpha-numeric):";
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
			isValid = true;
			if (ticket[i].SetWorkTicket(inputTicketNumber, inputClientID, inputDay, inputMonth, inputYear, inputClientIssue) == isValid)
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
			cout << ticket[i] << endl;
		}
	}
	
	//Will catch any invalid inputs and give an error
	catch (exception& ex)
	{
		isValid = false;
		cerr << ex.what() << "Ending the program." << endl;
	}
	
	//copy Q.1 and display with ostream Q.6
	WorkTicket ticket3 = ticket[0];
	cout << ticket3;
	//Equality operator Q.3
	cout << "ticket 1 and 2 equal?" << to_string(ticket[0] == ticket[1]) << endl;
}
//Copy ticket definition Q.1
WorkTicket::WorkTicket(const WorkTicket& ticket2)
{
	SetWorkTicket(ticket2.workTicketNumber, ticket2.clientID, ticket2.workTicketDateDay, ticket2.workTicketDateMonth, ticket2.workTicketDateYear, ticket2.issueDescription);
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
	SetWorkTicket(workTicketNumber, clientID, workTicketDateDay, workTicketDateMonth,workTicketDateYear, issueDescription);
}
//Set work ticket boolean for validation and storing user input definition 
bool WorkTicket::SetWorkTicket(int workTicketNumber, string clientID, int workTicketDateDay, int workTicketDateMonth, int workTicketDateYear, string issueDescription)
{
	SetWorkTicketNumber(workTicketNumber);
	SetClientID(clientID);
	SetWorkTicketDateDay(workTicketDateDay);
	SetWorkTicketDateMonth(workTicketDateMonth);
	SetWorkTicketDateYear(workTicketDateYear);
	SetIssueDescription(issueDescription);
	return true;
	
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
//Equality operator will return true if ticket equal to other ticket, false otherwise. Q.3
bool WorkTicket::operator==(const WorkTicket& other_ticket) const
{
	return ((GetWorkTicketDateDay() == other_ticket.GetWorkTicketDateDay()) && GetWorkTicketDateMonth() == other_ticket.GetWorkTicketDateMonth() && GetWorkTicketDateYear() == other_ticket.GetWorkTicketDateYear()
				&& GetWorkTicketNumber() == other_ticket.GetWorkTicketNumber() && GetIssueDescription() == other_ticket.GetIssueDescription() && GetClientID() == other_ticket.GetClientID());
	//
	// return (GetWorkTicket() == other_ticket.GetWorkTicket());
}
//Accessors definitions
int WorkTicket::GetWorkTicketNumber() const{
	return this->workTicketNumber;
}
string WorkTicket::GetClientID() const{
	return this->clientID;
}
string WorkTicket::GetIssueDescription() const{
	return this->issueDescription;
}
int WorkTicket::GetWorkTicketDateDay() const{
	return this->workTicketDateDay;
}
int WorkTicket::GetWorkTicketDateMonth() const{
	return this->workTicketDateMonth;
}
int WorkTicket::GetWorkTicketDateYear() const{
	return this->workTicketDateYear;
}
//Trying to return all attributes from WorkTicket to use for operator ==
WorkTicket WorkTicket::GetWorkTicket() const
{
	return WorkTicket();
}
string WorkTicket::ShowWorkTicket() const {
	// declare a stringstream object
	stringstream strOut;
	// build the string
	strOut << "Work Ticket Number : " << workTicketNumber << "\nClientID : " << clientID <<
		"\nWork Ticket Date : " << workTicketDateDay << "/" << workTicketDateMonth << "/" << workTicketDateYear <<
		"\nIssue Description : " << issueDescription << "\n";
	return strOut.str();
}
//Output stream definition Q.6
std::ostream& operator<<(std::ostream& out, const WorkTicket& ticket)
{
	out << ticket.ShowWorkTicket();
	return out;
}
