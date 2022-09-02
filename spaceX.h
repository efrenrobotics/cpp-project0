#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const double TAX = 0.0825;


// number of items in menu
int itemCount[6];
// prices of the menu
double prices[6] = {1099, 1299, 499, 799, 999, 399};
// description of menu items
string description[6] = {"Rolex Watch", "MacBook Pro", "Men's Cufflinks", "iPad Pro 11-in", "Ladies Ring", "Watch S4"};
// total item for day array
int totalItemCount[6];
// total amount earned 
double totalForDay;

void displayMenu();
void getInput();
bool printPrice();
void resetCount();