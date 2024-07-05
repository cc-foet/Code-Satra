#include <stdio.h>
#include <stdbool.h>  

bool lemonade(int a[], int n); 

bool lemonade(int a[], int n) {  
  int five = 0;
  int ten = 0;
  
  for (int i = 0; i < n; i++) {  
    if (a[i] == 5) {
      five++;
    } else if (a[i] == 10) {
      if (five > 0) {
        five--;
        ten++;
      } else {
        return false;
      }
    } else if (a[i] == 20) {
      if (five > 0 && ten > 0) {
        five--;
        ten--;
      } else if (five >= 3) {
        five -= 3;  
      } else {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int n = 5;
  int bills[] = {5, 5, 5, 10, 20};  
  
  if (lemonade(bills, n)) {  
    printf("Billing Possible--Lemonade Can be sold--Changes available\n");
  } else {
    printf("Cannot sell lemonade due to insufficient changes\n");
  }
  
  return 0;  
}
