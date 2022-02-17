#include <iostream>
#include <iomanip>

using namespace std;

void FillOrder(int& largeTotal, int& mediumTotal, int& smallTotal, int& totalChoc, int &orderNum) {

	const double LARGE = 30.50;
	const double MEDIUM = 25.99;
	const double SMALL = 10.50;

	int userInput;
	int userTemp;
	int largeNeed;
	int mediumNeed;
	int smallNeed;

	double largeCost, mediumCost, smallCost, totalCost, tax, shipping;



	cout << "We currently have " << totalChoc << " pounds in stock!" << endl; //gives a number so you know how much you can order
	cout << "Please enter how many pounds of chocolate you would like to purchase: ";
	cin >> userInput;
	cout << endl << endl;

	while (userInput > totalChoc) { // will continue to ask for a valid amount that is less than what we have
		cout << "I'm sorry, we cannot fulfill that amount." << endl;
		cout << "Please enter a total less than " << totalChoc << ":";
		cin >> userInput;
		cout << endl << endl;
	}

	userTemp = userInput; //sets the pounds to temp so it can be manipulated. 

	largeNeed = userTemp / 5; //finds the total number of large bars needed

	if (largeNeed > largeTotal) {
		userTemp = userTemp - (largeTotal * 5); //converts lg bars to pounds and subtracts from total needed 
		largeNeed = largeTotal; //sets large needed to total
		largeTotal = 0; // changes total to 0
	}
	else {
		userTemp = userTemp % 5;//finds remaing pounds after large bars
		largeTotal -= largeNeed;
	}

	mediumNeed = userTemp / 3; //finds the total number of medium bars needed

	if (mediumNeed > mediumTotal) {
		userTemp = userTemp - (mediumTotal * 3); //converts medium bars to pounds and subtracts from total needed 
		mediumNeed = mediumTotal; //sets medium needed to total
		mediumTotal = 0; // changes total to 0
	}
	else {
		userTemp = userTemp % 3;//finds remaing pounds after medium bars
		mediumTotal -= mediumNeed;
	}

	smallNeed = userTemp;
	smallTotal -= smallNeed;

	totalChoc = (largeTotal * 5) + (mediumTotal * 3) + (smallTotal);

	largeCost = largeNeed * LARGE; //calculates cost of totals
	mediumCost = mediumNeed * MEDIUM;
	smallCost = smallNeed * SMALL;
	totalCost = largeCost + mediumCost + smallCost; 
	tax = totalCost * 0.075; // calculates tax

	if (userInput <= 0) { // calculates shipping
		shipping = 0;
	}
	else if (userInput <= 10) {
		shipping = 5.25;
	}
	else if (userInput <= 20) {
		shipping = 7.75;
	}
	else if (userInput <= 50) {
		shipping = 12.25;
	}
	else {
		shipping = 19.75;
	}


	cout << "Chocolate Order #" << orderNum << endl;
	cout << "Thank you for you order of " << userInput << " pounds of chocolate!" << endl;
	cout << "We will be sending the following: " << endl << endl;

	cout << "Large Bars: \t" << largeNeed << " \t= " << fixed << setprecision(2) << largeCost << endl;
	cout << "Medium Bars: \t" << mediumNeed << " \t= " << fixed << setprecision(2) << mediumCost << endl;
	cout << "Small Bars: \t" << smallNeed << " \t= " << fixed << setprecision(2) << smallCost << endl << endl << endl;


	cout << "Sub Total: \t" << fixed << setprecision(2) << totalCost << endl;
	cout << "Tax: \t" << "\t" << fixed << setprecision(2) << tax << endl;
	cout << "Shipping: \t" << fixed << setprecision(2) << shipping << endl;
	cout << "Total: \t" << "\t" << fixed << setprecision(2) << totalCost + tax + shipping << endl << endl << endl; // calculates new total

}


