// Problem: You are owner of Lemonade Stand. You are selling lemonade for $5. Customers are standing in a queue to buy from you. Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer, so that the net transaction is that the customer pays $5. You must act as a cashier and give correct change to each customer. You must give change in $5 and $10 bills. If you can give correct change to each customer, return true, otherwise return false.

public class Day4 {
    public boolean lemonadeChange(int[] bills) { // Time: O(n), Space: O(1)
        int five = 0, ten = 0;
        
        for (int bill : bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (five == 0) {
                    return false;
                }
                five--;
                ten++;
            } else { // bill == 20
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }

    public static void main(String[] args) {
        Day4 ls = new Day4();
        int[] bills = {5, 5, 5, 10, 20};
        System.out.println(ls.lemonadeChange(bills)); // Output: true
    }
}
