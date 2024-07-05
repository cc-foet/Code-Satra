#include <stdio.h>


void sort(int array[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int lemonade(int bills[], int n) {
    int fives = 0, tens = 0;
    for (int i = 0; i < n; i++) {
            if (bills[i] == 5) {
                fives++;
            } else if (bills[i] == 10) {
                if (fives == 0) {
                    return 0;
                }
                fives--;
                tens++;
            } else {
                if (tens > 0 && fives > 0) {
                    tens--;
                    fives--;
                } else if (fives > 2) {
                    fives -= 3;
                } else {
                    return 0;
                }
            }
        }
        return 1;
}

void main() {
    int n = 5;
    int bills[] = {10, 5, 5, 20, 5};

    sort(bills, n);
    printf("%s", lemonade(bills, n) ? "true" : "false");
}