#include <iostream>
#include <vector>

using namespace std;

bool check_change(vector<int>& bills) {
    vector<int> desk (3, 0);
    int change;

    for (int i = 0; i < bills.size(); i++) {
        // submit change in our desk
        switch(bills[i]) {
            case 5: desk[0]++; break;
            case 10: desk[1]++; break;
            case 20: desk[2]++; break;
            default: continue;
        }
        // check change
        change = bills[i] - 5;
        // check and return change
        if (change == 15) {
            if (desk[1] > 0 && desk[0] > 0) {
                desk[1]--;
                desk[0]--;
            }
            else if (desk[0] > 3) {
                desk[0] -= 3;
            }
            else {
                return false;
            }
        } else if (change == 5) {
            if (desk[0] > 0) {
                desk[0]--;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, const char **argv) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    int data;
    vector<int> bills;
    while (fscanf(fp, "%d", &data) != EOF) {
        bills.push_back(data);
    }

    cout << check_change(bills) << endl;
    return EXIT_SUCCESS;
}