/************************************************************
 ** Program Filename: Btrip.cpp
 ** Author: Michael Smith
 ** Date: 5/26/2019
 ** Description: Business trip expense and reimbursement calculator
 ** Input: Various numbers and data from the employee about there business trip
 ** Output: Total expense, total reimbursement and the amount owed
 ***********************************************************/
#include <iostream>
using namespace std;

//declaring functions to calculate total expenses
void taxi_expense(int days, double cost, double &expense, double &reim);
void rental_expense(int day, int rental, int miles, double &expense, double &reim);
void first_day_expense(double depart, double *breakfast, double *lunch, double *dinner);
void last_day_expense(int days, double arrival, double *breakfast, double *lunch, double *dinner);
void multiple_employees(string employee, double *x, double *y, int days, int nights, double depart, double arrival);
/*********************************************************************
 * ** Function:taxi_expense()
 * ** Description:Calculates and adds to both the reimbursement and expense values from taxis
 * ** Parameters:Days spent on trip, total cost of taxis, address of expense and riembursement
 * ** Pre-Conditions:Expense before adding cost of taxis, reimbursement before adding taxi reimbursement value calculated
 * ** Post-Conditions:Updated total expense and reimbursement values
 * *********************************************************************/
void taxi_expense(int days, double cost, double &expense, double &reim)
{
	double x;
	x = days * 10;//company only reimburses up to 10$ per day
		if (x <= cost)
		{
			reim = reim + cost;	
		}
		else 
		{
			reim = reim + x;
		}
	expense = expense + cost;
}
/*********************************************************************
 * ** Function:rental_expense()
 * ** Description:Calculates the expense and reimbursement values from the rental car used 
 * ** Parameters:Days spent on trip, type of rental car used, the amount of miles driven, the address of expense and reimbursement
 * ** Pre-Conditions:Expense and reimbursement values before adding rental cost
 * ** Post-Conditions:New expense and reimbursement values after adding costs
 * *********************************************************************/
void rental_expense(int days, int rental, int miles, double &expense, double &reim)
{
	double x;
	double y;
	//if statements that determine the amount reimbursed based on the rental car used
	if (rental == 1)
	{
		x = days * 20;
		y = miles * .24;
		expense = expense + x + y;
		reim = reim + x + y; 	
	}else if (rental == 2)
	{
		x = days * 25;
		y = miles * .27;
		expense = expense + x + y;
		reim = reim + x + y;
	}else if (rental == 3)
	{
		x = days * 30;
		y = miles * .32;
		expense = expense + x + y;
		reim = reim + x + y;
	}else if (rental == 4)
	{
		x = days * 50;
		y = miles * .45;
		expense = expense + x + y;
		reim = reim + x + y;
	}
}
/*********************************************************************
 * ** Function:first_day_expense()
 * ** Description:Gathers the first day food expenses from the user and updates the expense and reimbursement costs
 * ** Parameters:The time of departure, and breakfast lunch and dinner pointers
 * ** Pre-Conditions:Breakfast lunch and dinner variables all equal zero 
 * ** Post-Conditions:breakfast lunch and dinner all equal the new expense entered by user
 * *********************************************************************/
void first_day_expense(double depart, double *breakfast, double *lunch, double *dinner)
{
	//if departure time is after 7 they do not get asked for the breakfast expense of the day. This continues for lunch and dinner
	if (depart > 7 and depart <= 12)
	{
		cout << "There isn't any breakfast expense for day one according to your departure time" << endl;
		cout << "Day 1 lunch expense: ";
                cin >> *lunch;
                cout << "Day 1 dinner expense: ";
                cin >> *dinner;
	}
	else if (depart > 12 and depart <= 18)
	{
		cout << "There isn't any breakfast expense for day one according to your departure time" << endl;
		cout << "There isn't any lunch expense for day one according to your departure time" << endl;
		cout << "Day 1 dinner expense: ";
                cin >> *dinner;
	}
	else if (depart > 18)
	{
		cout << "There isn't any breakfast expense for day one according to your departure time" << endl;
                cout << "There isn't any lunch expense for day one according to your departure time" << endl;
		cout << "There isn't any dinner expense for day one according to your departure time" << endl;
	}	
	else
	{
		cout << "Day 1 breakfast expense: ";
		cin >> *breakfast;
		cout << "Day 1 lunch expense: ";
		cin >> *lunch;
		cout << "Day 1 dinner expense: ";
		cin >> *dinner;
	}
	//use pointers for the breakfast lunch and dinner variables to update them
}
/*********************************************************************
 * ** Function:last_day_expense()
 * ** Description:Gathers the food cost from the user on the last day
 * ** Parameters:The total days spent on trip, the arrival time back, and breakfast lunch and dinner pointers
 * ** Pre-Conditions:Breakfast lunch and dinner equal the inputs of the first day
 * ** Post-Conditions:Breakfast lunch and dinner equal the new inputs from the user on the last day
 * *********************************************************************/
void last_day_expense(int days, double arrival, double *breakfast, double *lunch, double *dinner)
{
	//if the arrival time is before 8am, the user isn't asked for any food expenses for the last day. This continues for lunch and dinner
        if (arrival < 8)
        {
		cout << "There isn't any breakfast expense for day one according to your arrival time" << endl;
                cout << "There isn't any lunch expense for day one according to your arrival time" << endl;
                cout << "There isn't any dinner expense for day one according to your arrival time" << endl;
        }
        else if (arrival >= 8 and arrival < 13)
        {
		cout << "Day " << days << " breakfast expense: ";
                cin >> *breakfast;
                cout << "There isn't any lunch expense for day one according to your arrival time" << endl;
                cout << "There isn't any dinner expense for day one according to your arrival time" << endl;
        }
        else if (arrival >= 13 and arrival < 19)
        {
		cout << "Day " << days << " breakfast expense: ";
                cin >> *breakfast;
                cout << "Day " << days << " lunch expense: ";
                cin >> *lunch;
		cout << "There isn't any dinner expense for day one according to your arrival time" << endl;
	}
        else
        {
                cout << "Day " << days << " breakfast expense: ";
                cin >> *breakfast;
                cout << "Day " << days << " lunch expense: ";
                cin >> *lunch;
                cout << "Day " << days << " dinner expense: ";
                cin >> *dinner;
        }
}



void multiple_employees(string employee, double *x, double *y, int days, int nights, double depart, double arrival)
{
	double airfare, regfees, parkfee, hotel, expense, reim, owe;
	double breakfast, lunch, dinner, breakfastx, lunchx, dinnerx;
	double taxicost, parking;
	int tran, rental, miles;

	//ask user for amount spent of airfare and registration fees then adding it to expense and reimbursement
	cout << "Enter the total amount of airfare in $: " << endl;
	cin >> airfare;
	cout << "Enter the total amount of registration fees in $: " << endl;
	cin >> regfees;

	expense = airfare + regfees;
	reim = airfare + regfees;	
	//ask user if they rented a car or used a taxi, if they rented it also asks what time of car was rented
	cout << "Did you rent a car or use a taxi?\n";
	cout << "Enter 1 for a rental or 2 for a taxi: ";
	cin >> tran;
		//if they used taxis, it runs the taxi_expense() function to update expense and reimbursement
		if (tran == 2)
		{
			cout << "Enter the total cost spent on taxis: " << endl;
			cin >> taxicost;
			taxi_expense(days, taxicost, expense, reim); 		
		}
		else if (tran == 1)
		{
			cout << "1. Sedan\n" << "2. SUV\n" << "3. Van\n" << "4. Convertible" << endl;
			cout << "Enter the type of rental car used: " << endl;
			cin >> rental;
			cout << "Enter the total miles driven: " << endl;
			cin >> miles;
			rental_expense(days, rental, miles, expense, reim); //runs the rental_expense() function based on the rental car used
				//for loop asking for the parking cost of each day, only runs for the amount of days spent on trip
				for (int i = 1; i <= days; i++)
				{
					cout << "What was the parking cost on day " << i << ": ";
					cin >> parkfee;
						if (parkfee > 6)
						{
							reim = reim + 6;//company only allows 6$ of parking each day to be reimbursed 
							expense = expense + parkfee;
						}
						else 
						{
							reim = reim + parkfee;
							expense = expense + parkfee;
						}
				}
		}
	//for loop that asks for the hotel fees of each night
	for (int i = 1; i <= nights; i++)
	{
		cout << "Enter the hotel fees on night " << i << ": ";
		cin >> hotel;
			if (hotel <= 90)
			{
				reim = reim + hotel;
				expense = expense + hotel;				
			}
			else 
			{
				reim = reim + 90;//company only reimburses 90$ of hotel fees per night
				expense = expense + hotel;
			}		
	}
	//for loop that asked the user for the breakfast, lunch and dinner expenses for each day
	for (int i = 1; i <= days; i++)
	{
		//on the first day or the first iteration of the loop, the first_day_expense() function is ran
		if (i == 1)
		{
			first_day_expense(depart, &breakfast, &lunch, &dinner);
			expense = expense + breakfast + lunch + dinner;
				if (breakfast > 9)
				{
					reim = reim + 9;//company only reimburses 9$ for breakfast
				}
				else
					reim = reim + breakfast;
				if (lunch > 12)
				{
					reim = reim + 12;//company only reimburses 12$ for lunch
				}
				else 
					reim = reim + lunch;
				if (dinner > 16)
				{	
					reim = reim + 16;//company only reimburses 16$ for dinner
				}
				else 
					reim = reim + dinner;
		}
		//asks the users for the breakfast lunch and dinner expenses after the first day and before the last day
		else if (i > 1 and i < days) 
		{
			cout << "Day " << i << " breakfast expense: ";
        	        cin >> breakfastx;
	                cout << "Day " << i << " lunch expense: ";
           		cin >> lunchx;
                	cout << "Day " << i << " dinner expense: ";
                	cin >> dinnerx;
			expense = expense + breakfastx + lunchx + dinnerx;
				if (breakfastx > 9)
                                {
                                        reim = reim + 9;
				 }
				else
                                        reim = reim + breakfastx;
                                if (lunchx > 12)
                                {
                                        reim = reim + 12;
                                }
				else
                                        reim = reim + lunchx;
                                if (dinnerx > 16)
                                {
                                        reim = reim + 16;
                                }
				else
                                        reim = reim + dinnerx;
		}
		//if the for loop is on its last iteration, the last_day_expense() function is ran
		else if (i == days)
                {
                        last_day_expense(days, arrival, &breakfast, &lunch, &dinner);
                        expense = expense + breakfast + lunch + dinner;
                                if (breakfast > 9)
                                {
                                        reim = reim + 9;
                                }
				else
                                        reim = reim + breakfast;
                                if (lunch > 12)
                                {
                                        reim = reim + 12;
                                }
				else
                                        reim = reim + lunch;
                                if (dinner > 16)
                                {
                                        reim = reim + 16;
                                }
				else
                                        reim = reim + dinner;
                }

	}
	//calculate the total amount owed by the user and displays the expense, reimbursement and amount owed
	owe = expense - reim;
	*x = expense;
	*y = reim; 
	cout << "The total expense for " << employee << " on the trip is: " << expense << endl;
	cout << "The total reimbursement value provided by the company is: " << reim << endl;
	cout << "The total amount owed by " << employee << " to the company is: " << owe << endl;
}

int main()
{
	//declaring variables for the main function
	int number, days, nights;
	double totalexpense, totalreim, x, y, totalowed, depart, arrival;
	string name;
	//asking user for the number of days spent on trip, how many employees went, departure time and arrival time
	cout << "Enter the number of employees that went on the business trip: ";
	cin >> number;
	cout << "Enter the number of days spent on trip: " << endl;
	cin >> days;	
	nights = days - 1;
	cout << "Enter your departure time: " << endl;
        cin >> depart;
        cout << "Enter your arrival time: " << endl;
        cin >> arrival;
		//for loop that loops for each employee
		for (int i = 0; i < number; i++)
		{
			cout << "Enter emplyees name: ";
			cin >> name;
			multiple_employees(name, &x, &y, days, nights, depart, arrival);
			totalexpense = totalexpense + x;
			totalreim = totalreim + y; 
		}
	//displaying the total expense and reimbursement for the entire business trip for all employees
	totalowed = totalexpense - totalreim;
	cout << "The overall expense of this business trip was: " << totalexpense << endl;
	cout << "The overall reimbursement value paid by the company is: " << totalreim << endl;
	cout << "The total amount owed by employees is: " << totalowed << endl;
}









