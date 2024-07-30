package Array;
import java.util.*;

public class InversionCount {

   
    static class FenwickTree {
        private int[] tree;

        public FenwickTree(int size) {
            tree = new int[size + 1];
        }

        public void update(int index, int value) {
            while (index < tree.length) {
                tree[index] += value;
                index += index & -index;
            }
        }

        public int query(int index) {
            int sum = 0;
            while (index > 0) {
                sum += tree[index];
                index -= index & -index;
            }
            return sum;
        }
    }

    public static int countInversions(int[] arr) {
        
        int[] sortedArr = arr.clone();
        Arrays.sort(sortedArr);

        Map<Integer, Integer> rankMap = new HashMap<>();
        for (int i = 0; i < sortedArr.length; i++) {
            rankMap.put(sortedArr[i], i + 1);  
        }

       
        FenwickTree fenwickTree = new FenwickTree(arr.length);
        int inversions = 0;

      
        for (int i = arr.length - 1; i >= 0; i--) {
           
            int rank = rankMap.get(arr[i]);

          
            inversions += fenwickTree.query(rank - 1);

           
            fenwickTree.update(rank, 1);
        }

        return inversions;
    }

    public static void main(String[] args)
     {
        int[] arr = {8, 4, 2, 1};
        int inversionCount = countInversions(arr);
        System.out.println("Number of inversions: " + inversionCount);
    }
}
