package Array;

import java.util.TreeMap;

public class HandsofStraight {
    static boolean isStraightHand(int N, int groupSize, int hand[])
    {
        // code here
        
        if (hand.length % groupSize != 0)
            return false;

        TreeMap<Integer, Integer> map = new TreeMap<>();
        for (int card : hand) {
            map.put(card, map.getOrDefault(card, 0) + 1);
        }

        while (!map.isEmpty()) {
            int firstNumber = map.firstKey();
            for (int i = 0; i < groupSize; i++) {
                if (!map.containsKey(firstNumber + i)) {
                    return false;
                }

                map.put(firstNumber + i, map.get(firstNumber + i) - 1);
                if (map.get(firstNumber + i) == 0) {
                    map.remove(firstNumber + i);
                }
            }
        }

        return true;
    }
    public static void main(String args[])
    {
        int N = 9;
        int groupSize = 3;
        int hand[] = {1,2,3,6,2,3,4,7,8};
        System.out.println(isStraightHand(N, groupSize, hand));
    }
    
}
