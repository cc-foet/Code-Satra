import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Day12 {
 static class Element {
        int value;
        int arrayIndex;
        int elementIndex;
        
        Element(int value, int arrayIndex, int elementIndex) {
            this.value = value;
            this.arrayIndex = arrayIndex;
            this.elementIndex = elementIndex;
        }
    }
    
    public static int[] mergeKSortedArrays(int[][] arrays) {
        int k = arrays.length;
        int n = arrays[0].length;
        int[] result = new int[k * n];
        
        PriorityQueue<Element> minHeap = new PriorityQueue<>(new Comparator<Element>() {
            public int compare(Element e1, Element e2) {
                return Integer.compare(e1.value, e2.value);
            }
        });
        
        for (int i = 0; i < k; i++) {
            if (arrays[i].length > 0) {
                minHeap.add(new Element(arrays[i][0], i, 0));
            }
        }
        
        int resultIndex = 0;
        
        while (!minHeap.isEmpty()) {
            Element minElement = minHeap.poll();
            result[resultIndex++] = minElement.value;
            
            int nextElementIndex = minElement.elementIndex + 1;
            if (nextElementIndex < arrays[minElement.arrayIndex].length) {
                minHeap.add(new Element(arrays[minElement.arrayIndex][nextElementIndex], minElement.arrayIndex, nextElementIndex));
            }
        }
        
        return result;
    }

    public static void main(String[] args) {
        int[][] arrays = {
            {1, 3, 5},
            {2, 4, 6},
            {0, 9, 10}
        };
        
        int[] result = mergeKSortedArrays(arrays);
        System.out.println(Arrays.toString(result));
    }
    
}