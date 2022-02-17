#include <iostream>

using namespace std;

void FillOrder(int& largeTotal, int& mediumTotal, int& smallTotal, int& totalChoc, int &orderNum);
// pass by value updates totals after order

void PrintInventory(int largeTotal, int mediumTotal, int smallTotal);
// no need to update anything, just prints

void OrderInventory(int& largeTotal, int& mediumTotal, int& smallTotal);
// upates totals after order
