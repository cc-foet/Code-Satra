public class DayOne {
    public static void main(String[] args) {
        
        int[] arr = {64, 34, 25, 12, 22, 11, 90};

        int count = bubbleSort(arr);
        System.out.println("Sorted array: ");

        for (int val : arr) {
            System.out.print( val + "\t");
        }

        System.out.println("No of swaps - " + count);

    }

    private static int bubbleSort(int[] arr) {

        int ct = 1;
        int n = arr.length;
        for(int i = 0; i < n-1; i++) {
            boolean isSwapped = false; // checks if swapping is done or not, if not then array is sorted.

            for(int j = 0; j < n-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    isSwapped = true;
                    ct++;
                    }
            }
            if (!isSwapped) return ct;
        }
        return ct;
    }
}
