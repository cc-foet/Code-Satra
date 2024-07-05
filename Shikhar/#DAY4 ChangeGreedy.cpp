// Solution for today's challenge.

#include <iostream>
#include <vector>

using namespace std;

bool lemonadeChange(vector<int>& bills) {
    // Initialize counters for $5 and $10 bills
    int five_count = 0;
    int ten_count = 0;

    // Iterate through each bill in the array
    for (int i = 0; i < bills.size(); ++i) {
        int bill = bills[i];
        if (bill == 5) {
            // Customer pays with a $5 bill, increase the count of $5 bills
            five_count++;
        } else if (bill == 10) {
            // Customer pays with a $10 bill
            if (five_count > 0) {
                // If we have at least one $5 bill, use it as change
                five_count--;
                // Increase the count of $10 bills
                ten_count++;
            } else {
                // If we don't have a $5 bill for change, return false
                return false;
            }
        } else if (bill == 20) {
            // Customer pays with a $20 bill
            if (ten_count > 0 && five_count > 0) {
                // If we have at least one $10 bill and one $5 bill, use them as change
                ten_count--;
                five_count--;
            } else if (five_count >= 3) {
                // If we don't have a $10 bill but have at least three $5 bills, use three $5 bills as change
                five_count -= 3;
            } else {
                // If we can't provide change using either of the above methods, return false
                return false;
            }
        }
    }

    // If we successfully provided change to all customers, return true
    return true;
}

int main() {
    // Example input
    int N = 5;
    int billsArray[] = {5, 5, 5, 10, 20};
    vector<int> bills(billsArray, billsArray + N);

    // Call the lemonadeChange function and print the result
    if (lemonadeChange(bills)) {
        cout << "True" << endl; // Output: True
    } else {
        cout << "False" << endl;
    }

    return 0;
}
