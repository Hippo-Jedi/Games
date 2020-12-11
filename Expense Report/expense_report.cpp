/*******************************
* *Program: expense_report
* *Author:
* *Date: 05/25/2019
* *Description: Assignment 5 expense report
* *Input: Time of flights, #of days, Expenses and costs of trip, ints, floats and doubles
* *Output:Total expense, total reimbursed, total owed.
*******************************/



#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

//  FUNCTION TO UPDATE TOTALS VIA PASS BY POINTERS
void update_total (float* total_expense, float* total_reimbursement, float expense_to_add, float reimbursement_to_add){
    *total_expense = *total_expense + expense_to_add;
    *total_reimbursement = *total_reimbursement + reimbursement_to_add;
}

//MEAL FUNCTION TO UPDATE TOTAL MEAL EXPENSE BASED OFF ARRIVAL/DEPARTURE TIME
//Meal function is a long one to account for all the possible arrival/departure times
void meal_fee (int days_of_trip, double depart_time, double arrival_time, double* meal_expense, double* meal_reimbursement){
    float breakfast, breakfastTotal, lunch, lunchTotal, dinner, dinnerTotal, totalmeal;
    int allowedbr= days_of_trip*9, allowedlun=days_of_trip*12, alloweddin=days_of_trip*16;

    cout << "Enter total spent on breakfast per day: $";
    cin >> breakfast;
    if (depart_time<= 7){
      breakfastTotal = breakfast*days_of_trip;
    }
    else if (depart_time > 7){
      cout << "Your first meal is not eligible for reimbursement." << endl;
      breakfastTotal = breakfast*(days_of_trip-1);
    }

    cout << "Enter total spent on lunch per day: $";
    cin >> lunch;
    if (depart_time <= 12.00){
      lunchTotal = lunch*days_of_trip;
    }
    else if (depart_time > 12.00){
      cout << "Your first lunch is not elligible for reimbursement."<< endl;
      lunchTotal = lunch*(days_of_trip-1);
    }

    cout << "Enter total spent on dinner per day: $";
    cin >> dinner;
    if (arrival_time >= 19.00){
      dinnerTotal = dinner*days_of_trip;
    }
    else if (arrival_time < 19.00){
      cout << "Your last meal is not elligible for reimbursement."<< endl;
      dinnerTotal = dinner*(days_of_trip-1);
    }
    totalmeal = dinnerTotal + lunchTotal + breakfastTotal;
    cout << "Your total expense on food was: $" << totalmeal << endl;
    *meal_expense = totalmeal;

    if (breakfastTotal > allowedbr)
        *meal_reimbursement = breakfastTotal - allowedbr;
    else
        *meal_reimbursement = breakfastTotal;
    if (lunchTotal > allowedlun)
        *meal_reimbursement = *meal_reimbursement + (lunchTotal-allowedlun);
    else
        *meal_reimbursement= *meal_reimbursement + lunchTotal;
    if (dinnerTotal>alloweddin)
        *meal_reimbursement = *meal_reimbursement + (dinnerTotal-alloweddin);
    else
        *meal_reimbursement = *meal_reimbursement + dinnerTotal;

    cout << "Your total reimbursement on food is: $" << *meal_reimbursement << endl;
}

int main(){
  //Do/while loop so program continues till user tells it to stop
  int again;
  do{
    float total_expense = 0,total_reimbursement = 0;
    float expense, reimbursed, airfare, registration, taxifare, rentalcost, rentalFee, rentalGas, tobepaid;
    int days_of_trip = 0;
    double depart_time, arrival_time, parking, hotelCost, meal_expense = 0, meal_reimbursement = 0;
    int transport = 0;
    int cartype, carMiles;
  //Do/while loop so program continues till user tells it to sto
    cout << "Enter the total amount of airfare: ";
    cin >> airfare;
    update_total(&total_expense, &total_reimbursement, airfare, airfare);
    cout << "\nEnter the total registration cost: ";
    cin >> registration;
    update_total(&total_expense, &total_reimbursement, registration, registration);

    //cout << "Ruuning total is x:" << total_expense << "\nR=" <<total_reimbursement << endl;

    cout << "\nEnter the # of days of your trip: ";
    cin >> days_of_trip;
    //handles bad inputs of 0 but not handling non integer inputs
    //While roop repeats infinitley if a char is entered and not sure as to why
    while (!(days_of_trip >= 1) ){
        cout << "Invalid input try again!" << endl;
        cout << "Enter the # of days of your trip: ";
        cin >> days_of_trip;
      }

    cout << "\nEnter your departure time on the first day(00.00 based off 24 hr clock): ";
    cin >> depart_time;
    cout << "Enter your arrival time on the last day(00.00 based off 24 hr clock): ";
    cin >> arrival_time;

    //Function to determine meal costs/expense
    meal_fee(days_of_trip, depart_time, arrival_time, &meal_expense, &meal_reimbursement);

    //The values updated in the meal function are then sent to the total function to be added in
    update_total(&total_expense, &total_reimbursement, meal_expense, meal_reimbursement);

    cout <<"\nDid you (1) rent a car or (2) take a taxi?\n";
    cin >> transport;
    //Handles int inputs that are not 1 or 2 but still doesnt correct for non int inputs
    while (transport!= 1 && transport!= 2){
        cout <<"Invalid input try again: ";
        cin >> transport;
    }
    //Rental car if path
    if (transport == 1){
      //Handles bad inouts for rental car type.
      while (cartype < 1 || cartype > 4){
          cout << "\n(1)Sedan\n(2)SUV\n(3)Van\n(4)Convertible" << endl;
          cout << "Select your rental car type: ";
          cin >> cartype;
      }
      cout << "Enter total miles driven: ";
      cin >> carMiles;
          if (cartype==1){
            rentalFee = days_of_trip*20;
            rentalGas = carMiles*0.24;
            rentalcost = rentalFee + rentalGas;
          }
          else if (cartype==2){
            rentalFee = days_of_trip*25;
            rentalGas = carMiles*0.27;
            rentalcost = rentalFee + rentalGas;
          }
          else if (cartype==3){
            rentalFee = days_of_trip*30;
            rentalGas = carMiles*0.32;
            rentalcost = rentalFee + rentalGas;
          }
          else if (cartype==4){
            rentalFee = days_of_trip*50;
            rentalGas = carMiles*0.45;
            rentalcost = rentalFee + rentalGas;
          }
      update_total(&total_expense, &total_reimbursement, rentalcost, rentalcost);
      //cout << "Ruuning total is x:" << total_expense << "\nR=" <<total_reimbursement << endl;
      cout << "\nEnter total parking costs: ";
      cin >> parking;
        if (parking > days_of_trip*6){
            reimbursed = days_of_trip*6;
            tobepaid = parking - reimbursed;
            cout << "You will be reimbursed: "<< reimbursed <<".\nAnd pay the remaining: "<< tobepaid << endl;
          update_total(&total_expense, &total_reimbursement, parking, reimbursed);
        }
        else if (parking < days_of_trip*6){
            cout << "You will be reimbursed the total cost of your parking" << endl;
            update_total(&total_expense, &total_reimbursement, parking, parking);
        }
      //cout << "Ruuning total is x:" << total_expense << "\nR=" <<total_reimbursement << endl;
    }
    //Taxi if path
    else if (transport == 2){
        taxifare = 0;
        while (taxifare < 1){
          cout << "\nEnter the TOTAL amount spent on taxi fare: ";
          cin >> taxifare;
        }
        if (taxifare > days_of_trip*10){
            reimbursed = days_of_trip*10;
            tobepaid = taxifare - days_of_trip*10;
            cout << "You will be reimbursed: "<< reimbursed << ".\nAnd pay the remaining: "<< tobepaid <<endl;
        update_total(&total_expense, &total_reimbursement, taxifare, reimbursed);
        }
        else {
            reimbursed = taxifare;
            cout << "You will be reimbursed your total taxi fare." << endl;
        update_total(&total_expense, &total_reimbursement, taxifare, reimbursed);
        }

    }
    //cout << "Ruuning total is x:" << total_expense << "\nR=" <<total_reimbursement << endl;
    cout << "\nEnter total cost of hotel stay: ";
    cin >> hotelCost;
      if (hotelCost > days_of_trip*90){
        reimbursed = days_of_trip*90;
        tobepaid = hotelCost - reimbursed;
        cout <<"You will be reimbursed: " << reimbursed <<".\nAnd pay the remaining: " << tobepaid << endl;
        update_total(&total_expense, &total_reimbursement, hotelCost, reimbursed);

      }
      else {
          cout << "You will be reimbursed your whole hotel expense of: " << hotelCost << endl;
          update_total(&total_expense, &total_reimbursement, hotelCost, hotelCost);
      }
      //cout << total_expense << " " <<total_reimbursement << endl;

    cout << "\n\nYour total expense for this trip is: $" << total_expense << endl;
    cout << "Your total reimbursement for this trip is: $" << total_reimbursement << endl;
    cout << "Total left for you to pay is: $" << total_expense-total_reimbursement << endl;

    cout << "\nDo you want to fill this out agian? (1)Yes (0)No ";
    cin >> again;

  } while(again==1);


   return 0;
}
