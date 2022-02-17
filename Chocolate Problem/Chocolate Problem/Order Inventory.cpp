#include <iostream>

using namespace std;

void OrderInventory(int& largeTotal, int& mediumTotal, int& smallTotal) { // passes values back to main
	int userOrder;
	char orderSize;


	cout << "What size bars would you like to order (L, M, S)? ";
	cin >> orderSize;

	// makes sure the size is valid
	while (orderSize != 'l' && orderSize != 'L' && orderSize != 'M' && orderSize != 'm' && orderSize != 's' && orderSize != 'S') {
		cout << "I'm sorry, that is not a valid size." << endl;
		cout << "What size bars would you like to order?";
		cin >> orderSize;
		cout << endl << endl;
	}
	 
	cout << "How many bars would you like to order? ";
	cin >> userOrder;

	// makes sure the number is greater than zero
	while (userOrder <= 0) {
		cout << "I'm sorry, we cannot order that amount." << endl;
		cout << "How many bars would you like to order?";
		cin >> userOrder;
		cout << endl << endl;
	}

	switch (orderSize) { // adds order to correct size of bars
		case 'l':
		case 'L':
			largeTotal += userOrder;
			break;
		case 'm':
		case 'M':
			mediumTotal += userOrder;
			break;
		case 's':
		case 'S':
			smallTotal += userOrder;
			break;
		default: // doesn't do anything. cant even enter this
			break;
	}
	cout << endl << endl << endl; // extra spaces for asthetics
}
