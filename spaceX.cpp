#include "spaceX.h"

// Displays the items menu
// Efren
void displayMenu(){
    for(int i = 1; i <= 6; i++){
        cout << "[" << i << "] " << left << setw(19) << description[i - 1];
        cout << setprecision(2) << fixed;
        cout << "$" << right << setw(7) << prices[i-1] << endl;
    }
    cout << "Input the item numbers for the order, 0 to quit" << endl;
}

// Get user input, print error if item outside of menu
// Efren
void getInput(){
    int input;
    while(input != 0){
        cin >> input;
        if(input < 0 || input > 6){
            cout << "*Error: There is no item " << input << "." << endl;
            cout << "Processing other items..." << endl;
        }else{
            itemCount[input - 1]++;
            totalItemCount[input - 1]++;
        }
    }
}

// Display subtotal, tax-total, and total
// Angel
bool printPrice() {
    double total = 0;
    for (int i = 0; i < 6; i++) {
        total += (prices[i] * itemCount[i]);
    }
    cout << "Subtotal...$" << right << setw(8) << total << endl;
    double tax = total * TAX;
    cout << "Tax........$" <<  right << setw(8) << tax << endl;
    total += (total * TAX);
    totalForDay += total;
    cout << "Total......$" << right << setw(8) << total << endl;
    cout << "\nPlease enter 'N' to take a new order and 'E' to exit: ";
    string playAgain;
    cin >> playAgain;
    return playAgain.compare("N") == 0;
}

// Zero out the array
// Efren
void resetCount() {
    for (int i = 0; i < 6; i++) {
        itemCount[i] = 0;
    }
}

// Display totals for the day
// Angel
void printTotal(){
    cout << "*** End of Day:" << endl;
    cout << "Total sales: $" << totalForDay << endl;
    int max = 0;
    int maxItem = 0;
    for(int i = 0; i < 6; i++){
        if(totalItemCount[i] > max){
            max = totalItemCount[i];
            maxItem = i;
        }
    }
    cout << "Item ordered most often: " << description[maxItem] << " was purchased " << totalItemCount[maxItem] << " times." << endl;
}

int main(){
    bool playAgain = true;
    while (playAgain) {
        displayMenu();
        getInput();
        playAgain = printPrice();
        resetCount();
    }
    printTotal();
    return 0;
}