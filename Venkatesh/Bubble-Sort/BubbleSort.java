public class BubbleSort {
    static int bubbleSort(int[] arr) {
        int count = 0;
        int n = arr.length;
        int temp = 0;
        for(int i=0; i < n; i++) {
            for(int j=1; j < (n-i); j++) {
                if(arr[j-1] > arr[j]) {
                    temp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = temp;
                    count += 1;
                }
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90, 2, 10, 7};
        int count = bubbleSort(arr);

        System.out.print("Sorted array: [");
        for (int i = 0; i < arr.length - 1; i++) {
            System.out.print(arr[i] + ", ");
        }
        System.out.println(arr[arr.length - 1] + "]");
        System.out.println("Number of swaps: " + count);
    }
    
}