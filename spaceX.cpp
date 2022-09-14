#include "spaceX.h"

// Displays the items menu
// Efren
void displayMenu(double prices[], string description[]) {
    for (int i = 1; i <= NUM_ITEMS; i++) {
        cout << "[" << i << "] " << left << setw(19) << description[i - 1];
        cout << setprecision(2) << fixed;
        cout << "$" << right << setw(7) << prices[i-1] << endl;
    }
    cout << "Input the item numbers for the order, 0 to quit" << endl;
}

// Get user input, print error if item outside of menu
// Efren
double getSubTotal(double prices[], int totalItemCount[]) {
    int input = -1;
    int itemCount[NUM_ITEMS] = {0};
    while (input != 0) {
        cin >> input;
        if (input < 0 || input > NUM_ITEMS) {
            cout << "*Error: There is no item " << input << "." << endl;
            cout << "Processing other items..." << endl;
        } else {
            itemCount[input - 1]++;
            totalItemCount[input - 1]++;
        }
    }
    double total = 0;
    for (int i = 0; i < NUM_ITEMS; i++) {
        total += (prices[i] * itemCount[i]);
    }
    return total;
}

// Display subtotal, tax-total, and total
// Angel
double printPrice(double subTotal) {
    cout << "Subtotal...$" << right << setw(8) << subTotal << endl;
    double tax = subTotal * TAX;
    cout << "Tax........$" <<  right << setw(8) << tax << endl;
    double total = subTotal + (subTotal * TAX);
    cout << "Total......$" << right << setw(8) << total << endl;
    cout << "\nPlease enter 'N' to take a new order and 'E' to exit: ";
    return total;
}

// Find the index of the most ordered item
// Angel
int findMostOrderedItem(int totalItemCount[]) {
    int maxItemIndex = 0;
    int max = 0;
    for (int i = 0; i < NUM_ITEMS; i++) {
        if(totalItemCount[i] > max) {
            max = totalItemCount[i];
            maxItemIndex = i;
        }
    }
    return maxItemIndex;
}

// Display totals for the day
// Angel
void printTotal(int totalItemCount[], string description[], double totalForDay) {
    cout << "*** End of Day:" << endl;
    cout << "Total sales: $" << totalForDay << endl;
    int maxItemIndex = findMostOrderedItem(totalItemCount);
    cout << "Item ordered most often: " << description[maxItemIndex]
        << " was purchased " << totalItemCount[maxItemIndex] << " times." << endl;
}

int main() {
    double prices[NUM_ITEMS] = {1099, 1299, 499, 799, 999, 399};
    string description[NUM_ITEMS] = {"Rolex Watch", "MacBook Pro", "Men's Cufflinks",
                                "iPad Pro 11-in", "Ladies Ring", "Watch S4"};
    int totalItemCount[NUM_ITEMS] = {0};
    bool playAgain = true;
    double totalForDay = 0;
    while (playAgain) {
        displayMenu(prices, description);
        double subtotal = getSubTotal(prices, totalItemCount);
        totalForDay += printPrice(subtotal);
        string input;
        cin >> input;
        playAgain = (input.compare("N") == 0);
    }
    printTotal(totalItemCount, description, totalForDay);
    return 0;
}
