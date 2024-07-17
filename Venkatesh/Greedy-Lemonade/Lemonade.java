public class Lemonade {
    public static void sort(int[] array, int n) {
        int temp = 0;
        for(int i=0; i < n; i++) {
            for(int j=1; j < (n-i); j++) {
                if(array[j-1] > array[j]) {
                    temp = array[j-1];
                    array[j-1] = array[j];
                    array[j] = temp;
                }
            }
        }
    }

    public static boolean change(int[] bills, int n) {
        int fives = 0, tens = 0;
        for (int i = 0; i < n; i++) {
            if (bills[i] == 5) {
                fives++;
            } else if (bills[i] == 10) {
                if (fives == 0) {
                    return false;
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
                    return false;
                }
            }
        }
        return true;
    }
    public static void main(String[] args) {
        int n = 5;
        int[] bills = {10, 5, 5, 20, 5};

        sort(bills, n);
        System.out.println(change(bills, n));
    }
}