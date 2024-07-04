public class Searching {
    
    public static int daysToBouquet(int[] bloomArray, int noOfBouquets, int flowersInBouquet) {
        if (bloomArray.length < noOfBouquets * flowersInBouquet) {
            return -1;
        }

        int left = Integer.MAX_VALUE, right = 0;
        for (int day : bloomArray) {
            left = Math.min(left, day);
            right = Math.max(right, day);
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canMake(mid, bloomArray, flowersInBouquet, noOfBouquets)) {
                right = mid;
            } else {
                left = mid + 1;                
            }
        }
        return canMake(left, bloomArray, flowersInBouquet, noOfBouquets) ? left : -1;
    }

    private static boolean canMake(int days, int[] bloomArray, int flowersInBouquet, int noOfBouquets) {
        int bouquets = 0;
        int flowers = 0;
        for (int day : bloomArray) {
            if (day <= days) {
                flowers++;
                if (flowers == flowersInBouquet) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return bouquets >= noOfBouquets;
    }

    public static void main(String[] args) {
        int[] bloomDay = {1, 10, 3, 10, 2};
        int k = 1;
        int m = 3;

        System.out.println(daysToBouquet(bloomDay, m, k));
    }
}
