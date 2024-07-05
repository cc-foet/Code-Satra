public class GreedyAlgorithm {
    //Lemonade Problem Solution
    static boolean lemonade(int N, int bills[]) {
        int five = 0;
        int ten = 0;
        for (int i = 0; i < N; i++) {
            int x = bills[i];
            if (x == 5)
                five++;
            else if (x == 10) {
                if (five > 0) {
                    five--;
                    ten++;
                } else {
                    return false;
                }
            } else if (x == 20) {
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
        int bills[] = {5, 5, 5, 10, 20};
        int N = bills.length;
        System.out.println(lemonade(N, bills));
    }
}