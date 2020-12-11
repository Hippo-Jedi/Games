/*************************************************
 *Program: Assignment5.cpp
 *Author: Kiernan Canavan 
 *Date: 05/25/2019
 *Description: 
 *Input: 
 *Output: 
 * **********************************************/
#include <iostream>
using namespace std;
 
void update_total(float* exp, float* reim, float* expAdd, float* reimAdd);
void meal_fee(int days, double depTime, double arTime, float* mealExp, float* mealReim);
void hotel_fee(int days, float* stayExp, float* stayReim);
void taxi_fee(int days, float* taxiExp, float* taxiReim);
void rental_fee(int days, float rentFee, float gasFee, float miles, float* rentExp, float* rentReim);
char checkChoice(char choice);
int checkCarChoice(int choice);
double checkTime(double time);

 int main(){
	float exp, reim, pay, expAdd, reimAdd, hotel, regFees, taxiFee, breakfast, lunch, dinner, mealExp, mealReim, stayExp, stayReim, taxiExp, taxiReim, rentFee, gasFee, airfare, miles, rentExp, rentReim; 
	double depTime, arTime; //Arrival and departure time variables
	int days, loop = 0, carChoice;
	char choice; //choice to pick either taxi or rental car

	while(loop == 0){
		cout << "Please enter the number of days spent on the trip: " << endl; //Put this all in a while loop that reprompts for a recalculation at end, use int loop
		cin >> days;
		cout<< "Please enter your departure time: \n (Use format of 17.00 for 5:00pm)" << endl;
		cin >> depTime;//Get departure time
		depTime = checkTime(depTime);
		
		cout << "Please Enter your arrival time: \n (Use format of 17.00 for 5:00pm)" << endl; 
		cin >> arTime;//Get arrival time
		arTime = checkTime(arTime);
		
		cout << "Enter total airfare for trip: " << endl;
		cin >> airfare;//Get airfare
		exp = exp + airfare; //since airfare is fully reimbursable we can directly add it both the the expenses and the reimbursement variables
		reim = reim + airfare; //no need to use pointers here...yay!!!!
		meal_fee(days, depTime, arTime, &mealExp, &mealReim);//call the meal fee function
		update_total(&exp, &reim, &mealExp, &mealReim);//send the data from meal fee to the function to add up the total expenses
		if(days>1){ //if trip is more than one day call the hotel fee function then update total
			hotel_fee(days, &stayExp, &stayReim);
			update_total(&exp, &reim, &stayExp, &stayReim);	
		}
		cout << "Enter any conference or registration fees: " << endl;
		cin >> regFees;//get conference fees
		exp = exp + regFees;//directly send the fees to the expences and reimbursement variables, these fees are 100% reimbursed
		reim = reim + regFees;
		cout << "Enter a 't' if a taxi was used or an 'r' f a rental car was used" << endl;//find out if taxi or rental car was used
		cin >> choice;
		choice = checkChoice(choice);//check the input to tell if valid
		if(choice=='t'){//if taxi was used get go to taxi fee function then update total
			taxi_fee(days, &taxiExp, &taxiReim);
			update_total(&exp, &reim, &taxiExp, &taxiReim);
		}
		if(choice=='r'){ //if rental car was used get the type and then assign the fees based on the type then send it to the rental function
			cout << "Enter a '1' for a sedan \nEnter a '2' for an SUV \nEnter a '3' for a van \nEnter a '4' for a convertible" << endl;
			cin >> carChoice;
			carChoice = checkCarChoice(carChoice);
			//set daily fee and gas fee from this then send to function, calc daily expense and park fee
			if(carChoice==1){ //sets the rental fee and gas fee based on the car type rented
				rentFee = 20;
				gasFee = 0.24;
			}
			if(carChoice==2){
				rentFee = 25;
				gasFee = 0.27;
			}
			if(carChoice==3){
				rentFee = 30;
				gasFee = 0.32;
			}
			if(carChoice==4){
				rentFee = 50;
				gasFee = 0.45;
			}
			cout << "Enter the total miles driven during the trip: " << endl;
			cin >> miles;
			rental_fee(days, rentFee, gasFee, miles, &rentExp,  &rentReim);
			update_total(&exp, &reim, &rentExp, &rentReim);
		}
		pay = exp - reim; //the amount you need to pay out of pocket are the total expenses - the reimbursement
		cout << "Total Expenses: $" << exp << endl; //print out the total expense data
		cout << "Total Reimbursement: $" << reim << endl;
		cout << "Total to be paid: $" << pay << endl;
		cout << "Would you like to re-calculate expenses?" << endl;
		cout << "Enter a '0' for yes or a '1' for no: " << endl;
		cin >> loop; //if user inputs a 1 then this breaks the loop causing the program to end, a 0 will continue it through once more
	} //end of loop
		cout << "Program has ended, thank you!" << endl;
} //end MAIN
 
char checkChoice(char choice){ //check to make sure taxi/rental choice input was valid
	while(1){
		if((choice!='r')&&(choice!='t')){
		cout << "Please enter either an 'r' or a 't' only!" << endl;
		cin >> choice;
		}
		if(choice == 't' || choice == 'r'){
			break;
		}
	}
	return choice;
}

int checkCarChoice(int choice){ //check to make sure rental car type input was valid
	while((4 < choice) || (choice < 1)){ 
		cout << "Please enter a number between 1 and 4 only!" << endl;
		cin >> choice;
	}
	return choice;
}

double checkTime(double time){
	while((23.59 < time) || (time < 00.00)){ 
		cout << "Please enter a time between 00.00 and 23.59 only!" << endl;
		cin >> time;
	}
	return time;
}
 
 void update_total(float* exp, float* reim, float* expAdd, float* reimAdd){ //updates total expenses and reimbursement
	*exp = *exp + *expAdd;
	*reim = *reim + *reimAdd;
 }
 
 void meal_fee(int days, double depTime, double arTime, float* mealExp, float* mealReim){ //calculate meal fees for all the days spent on the trip
	float breakfast, lunch, dinner;
	*mealExp = 0;
	*mealReim = 0;
	for(int i = 0; i < days; i++){ //go through the total days spent on trip and get the meal info for each day
		cout << "Day " << (i+1) << endl;
		cout << "Enter Breakfast fee: " << endl;
		cin >> breakfast;
		cout << "Enter Lunch fee: " << endl;
		cin >> lunch;
		cout << "Enter dinner expense: " << endl;
		cin >> dinner;
		
		if(i==1){ //Departure on first day
			if(depTime<7.00){
				*mealReim = *mealReim; //if you leave before 7 then all meals are reimbursed
			}
			if(7.00 < depTime <= 12.00){ //If you leave after 7am then breakfast is not reimburesed
				*mealReim = *mealReim - 9;
			}
			if(12.00 < depTime <= 18.00){//If you leave after 12pm then breakfast and luch is not reimbursed
				*mealReim = *mealReim - 21;
			}
			if(18.00 < depTime){//If you leave after 6pm no meals are reimbursed
				*mealReim = *mealReim - 37;
			}
		}
		if(i==days){ //Arival on last day
			if(arTime < 8.00){ //If you arrive before 8am no meals are reimbursed
				*mealReim = *mealReim - 37;
			}
			if(8.00 <= arTime < 13.00){; //If you arrive before 1pm then only breakfast is reimbursed
				*mealReim = *mealReim - 28;
			}
			if(13.00 <= arTime < 19.00){ //If you arrive before 7 then breakfast and lunch are reimbursed
				*mealReim = *mealReim - 16;
			}
			if(19.00 < arTime){ //if you arrive after 7pm then all meals are reimbursed
				*mealReim = *mealReim;
			}
		}
		*mealExp = *mealExp + breakfast + lunch + dinner;
		*mealReim = *mealReim + 37; //total meal reimbursement per day is 37 dollars max, for arival and departure days the reimbusrement is fixed based on the time
	}
	//cout << "***meal exp" << *mealExp << endl;
	//cout << "***meal reim" << *mealReim << endl;
 }
 
 void hotel_fee(int days, float* stayExp, float* stayReim){ //hotel expenses calculated here based on day
	float fee=0, totfee=0;
	*stayExp = 0;
	*stayReim = 0;
	for(int i = 0; i < days;i++){
		cout << "Enter hotel fee for day " << (i+1) << " :" << endl;
		cin >> fee;
		totfee = totfee + fee;
		if(fee<90){ //if the total fee is less than max reimbursement value then set reimbursement to that fee 
			*stayReim = *stayReim + fee;
		}
		else if(fee>=90){ //if the fee was above max reimbursement then set reimbursement to the max value 
			*stayReim = *stayReim + 90;
		}
	}
	*stayExp = totfee;
	//cout << "***stay exp" << *stayExp << endl;
	//cout << "***stay reim" << *stayReim << endl;
 }
 
 void taxi_fee(int days, float* taxiExp, float* taxiReim){
	 float fee=0, totfee=0;
	 *taxiExp = 0;
	 *taxiReim = 0;
	for(int i = 0; i < days;i++){
		cout << "Enter taxi fee for day " << (i+1) << " :" << endl;
		cin >> fee;
		totfee = totfee + fee;
		if(fee<10){ //if the total fee is less than max reimbursement value then set reimbursement to that fee
			*taxiReim = *taxiReim + fee;
		}
		else if(fee>=10){ //if the fee was above max reimbursement then set reimbursement to the max value 
			*taxiReim = *taxiReim + 10;
		}
	}
	*taxiExp = totfee; 
	//cout << "***taxi exp" << *taxiExp << endl;
	//cout << "***taxi reim" << *taxiReim << endl;
 }
 
 void rental_fee(int days, float rentFee, float gasFee, float miles, float* rentExp, float* rentReim){
	 float carfee=0, fee=0, totfee=0;
	 *rentExp = 0;
	 *rentReim = 0;
	 carfee = (days*rentFee) + (miles * gasFee);
	 for(int i = 0; i < days;i++){
		cout << "Enter parking fee for day " << (i+1) << " :" << endl;
		cin >> fee;
		totfee = totfee + fee;
		if(fee<6){ //if the total fee is less than max reimbursement value then set reimbursement to that fee
			*rentReim = *rentReim + fee;
		}
		else if(fee>=6){ //if the fee was above max reimbursement then set reimbursement to the max value 
			*rentReim = *rentReim + 6;
		}
	}
	*rentExp = *rentExp + carfee + totfee;
	*rentReim = *rentReim + carfee; 
	//cout << "***rent exp" << *rentExp << endl;
	//cout << "***rent reim" << *rentReim << endl;
 }