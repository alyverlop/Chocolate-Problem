#include <iostream>
#include <iomanip>
#include "Header.h"

using namespace std;

int main() {
	char userOption = 't'; //initialized to a char that isnt e to enter while loop

	int largeTotal = 1500; //5 lbs each
	int mediumTotal = 1200; //3 lbs each
	int smallTotal = 7000; //1 lb each
	int totalChoc = (largeTotal * 5) + (mediumTotal * 3) + (smallTotal);

	int orderNum =0;

	cout << "Welcome to Alyssa's Chocolate Shop!" << endl << endl;

	while (userOption != 'e' && userOption != 'E') { // creates the endless loop of main menu until e is presses
		cout << "Main Menu:" << endl;
		cout << "F - Fill an order" << endl;
		cout << "P - Print inventory" << endl;
		cout << "O - Order inventory" << endl;
		cout << "E - Exit" << endl;
		cout << "Select a menu option:";
		cin >> userOption;


		switch (userOption) { // reads input and preforms correct action
			case 'f':
			case 'F':
				totalChoc = (largeTotal * 5) + (mediumTotal * 3) + (smallTotal); // recalculated total before sending through
				orderNum += 1; // increasing order number each time
				FillOrder(largeTotal, mediumTotal, smallTotal, totalChoc, orderNum);// sends to fill order
				break;
			case 'p':
			case 'P':
				PrintInventory(largeTotal, mediumTotal, smallTotal); // sends to print inventory
				break;
			case 'o':
			case 'O':
				OrderInventory(largeTotal, mediumTotal, smallTotal); // sends to order inventory
				break;
			case 'e':
			case 'E': // exits
				break;
			default: 
				cout << endl << endl << "Not a valid entry." << endl << endl; 
				break;
		}

	}

	return 0;

}