// Problem: Merge K sorted arrays using a Min-Heap where K is the number of arrays and N is the number of elements in each array

import java.util.PriorityQueue; // Importing the PriorityQueue class
import java.util.Comparator; // Importing the Comparator class

class ArrayElement {
    int value;   // The value of the element
    int arrayIndex;  // The index of the array from which the element is taken
    int elementIndex; // The index of the element in the array

    public ArrayElement(int value, int arrayIndex, int elementIndex) {
        this.value = value;
        this.arrayIndex = arrayIndex;
        this.elementIndex = elementIndex;
    }
}

public class Day12 {

    public static int[] mergeKSortedArrays(int[][] arrays) {
        // Number of arrays
        int K = arrays.length;
        // Total number of elements
        int N = arrays[0].length;
        int[] result = new int[K * N];

        // Priority queue (min-heap) to store the elements
        PriorityQueue<ArrayElement> minHeap = new PriorityQueue<>(new Comparator<ArrayElement>() {
            @Override
            public int compare(ArrayElement o1, ArrayElement o2) {
                return o1.value - o2.value;
            }
        });

        // Insert the first element of each array into the min-heap
        for (int i = 0; i < K; i++) {
            if (arrays[i].length > 0) {
                minHeap.add(new ArrayElement(arrays[i][0], i, 0));
            }
        }

        int resultIndex = 0;

        // Extract the minimum element from the heap and insert the next element from the same array
        while (!minHeap.isEmpty()) {
            ArrayElement minElement = minHeap.poll();
            result[resultIndex++] = minElement.value;

            int nextElementIndex = minElement.elementIndex + 1;
            if (nextElementIndex < arrays[minElement.arrayIndex].length) {
                minHeap.add(new ArrayElement(arrays[minElement.arrayIndex][nextElementIndex], minElement.arrayIndex, nextElementIndex));
            }
        }

        return result;
    }

    public static void main(String[] args) {
        int[][] arrays = {
            {1, 3, 5, 7},
            {2, 4, 6, 8},
            {0, 9, 10, 11}
        };

        int[] mergedArray = mergeKSortedArrays(arrays);

        System.out.println("Merged sorted array:");
        for (int num : mergedArray) {
            System.out.print(num + " ");
        }
    }
}
