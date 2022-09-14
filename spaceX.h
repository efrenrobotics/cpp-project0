#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const double TAX = 0.0825;
const int NUM_ITEMS = 6;

void displayMenu(double prices[], string description[]);
double getSubTotal(double prices[], int totalItemCount[]);
double printPrice(double subTotal);
int findMostOrderedItem(int totalItemCount[]);
void printTotal(int totalItemCount[], string description[], double totalForDay);
