#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

	const double LARGE = 30.50;
	const double MEDIUM = 25.99;
	const double SMALL = 10.50;

	int userInput;
	int userTemp;
	int largeNeed;
	int mediumNeed;
	int smallNeed;

	double largeCost, mediumCost, smallCost, totalCost;

	int largeTotal = 150; //5 lbs each
	int mediumTotal = 120; //3 lbs each
	int smallTotal = 700; //1 lb each
	int totalChoc = (largeTotal * 5) + (mediumTotal * 3) + (smallTotal);



	cout << "Welcome to Alyssa's Chocolate Shop!" << endl << endl;
	cout << "We currently have " << totalChoc << " pounds in stock!" << endl;
	cout << "Please enter how many pounds of chocolate you would like to purchase: ";
	cin >> userInput;
	cout << endl << endl;


	while (userInput > totalChoc) {
		cout << "I'm sorry, we cannot fulfill that amount." << endl;
		cout << "Please enter a total less than " << totalChoc << ":";
		cin >> userInput;
		cout << endl << endl;
	}

	userTemp = userInput; //sets the pounds to temp so it can be manipulated. 

	largeNeed = userTemp / 5; //finds the total number of large bars needed

		if (largeNeed > largeTotal) {
			userTemp = userTemp - (largeTotal*5); //converts lg bars to pounds and subtracts from total needed 
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

	largeCost = largeNeed * LARGE; //calculates cost of totals
	mediumCost = mediumNeed * MEDIUM;
	smallCost = smallNeed * SMALL;
	totalCost = largeCost + mediumCost + smallCost;

	cout << "Thank you for you order of " << userInput << " pounds of chocolate!" << endl;
	cout << "We will be sending the following: " << endl << endl;

	cout << "Large Bars: \t" << largeNeed << " \t=\t" << fixed << setprecision(2) << largeCost << endl;
	cout << "Medium Bars: \t" << mediumNeed << " \t=\t" << fixed << setprecision(2) << mediumCost << endl;
	cout << "Small Bars: \t" << smallNeed << " \t=\t" << fixed << setprecision(2) << smallCost << endl;
	cout << "Total: \t" << "\t \t=\t" << fixed << setprecision(2) << totalCost << endl << endl << endl;

	cout << "Remaining Inventory:" << endl;
	cout << "Large Bars: \t" << largeTotal << endl;
	cout << "Medium Bars: \t" << mediumTotal << endl;
	cout << "Small Bars: \t" << smallTotal << endl;

	
	return 0;

}