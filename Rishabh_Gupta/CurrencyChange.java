public class CurrencyChange {
    public static int fewestCoins(int[] coinValues, int totalAmount) {
        int[] coinsNeeded = new int[totalAmount + 1];
        coinsNeeded[0] = 0;
        for (int currentTotal = 1; currentTotal <= totalAmount; currentTotal++) {
            coinsNeeded[currentTotal] = Integer.MAX_VALUE;
            for (int valueIndex = 0; valueIndex < coinValues.length; valueIndex++) {
                if (coinValues[valueIndex] <= currentTotal) {
                    int previousAmount = coinsNeeded[currentTotal - coinValues[valueIndex]];
                    if (previousAmount != Integer.MAX_VALUE && previousAmount + 1 < coinsNeeded[currentTotal]) {
                        coinsNeeded[currentTotal] = previousAmount + 1;
                    }
                }
            }
        }
        return coinsNeeded[totalAmount];
    }

    public static void main(String[] args) {
        int[] coinValues = {9, 6, 5, 1};
        int desiredAmount = 11;

        System.out.println(fewestCoins(coinValues, desiredAmount));
    }
}
