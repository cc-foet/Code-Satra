#include <stdio.h>
#include <stdbool.h>

bool lemonadeChange(int* bills, int size) {
    int fiveCount = 0, tenCount = 0;

    for (int i = 0; i < size; i++) {
        if (bills[i] == 5) {
            fiveCount++;
        } else if (bills[i] == 10) {
            if (fiveCount == 0) {
                return false;
            }
            fiveCount--;
            tenCount++;
        } else if (bills[i] == 20) {
            if (tenCount > 0 && fiveCount > 0) {
                tenCount--;
                fiveCount--;
            } else if (fiveCount >= 3) {
                fiveCount -= 3;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int bills[] = {5, 5, 5, 10, 20};
    int size = sizeof(bills) / sizeof(bills[0]);

    if (lemonadeChange(bills, size)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
