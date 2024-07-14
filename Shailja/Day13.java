import java.util.Arrays;
class Day13 {
public static void main(String[] args) {

    int[] aliceSizes1 = {1, 1};
    int[] bobSizes1 = {2, 2};
    int[] ans = fairCandySwap(aliceSizes1, bobSizes1);
    System.out.println( Arrays.toString(ans));

   
}

    public static int[] fairCandySwap(int[] aliceSizes, int[] bobSizes) {
        int aliceTotal = 0;
        int bobTotal = 0;

        for (int size : aliceSizes) {
            aliceTotal += size;
        }
        for (int size : bobSizes) {
            bobTotal += size;
        }

        int diff = (aliceTotal - bobTotal) / 2;

        for (int aliceCandy : aliceSizes) {
            for (int bobCandy : bobSizes) {
                if (aliceCandy - bobCandy == diff) {
                    return new int[]{aliceCandy, bobCandy};
                }
            }
        }

        return new int[0];
    }

    
}
