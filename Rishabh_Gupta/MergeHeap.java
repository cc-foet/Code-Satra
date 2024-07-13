class Node {
    int value;
    int row;
    int col;

    public Node(int value, int row, int col) {
        this.value = value;
        this.row = row;
        this.col = col;
    }
}

class MinHeap {
    Node[] heapArray;
    int heapSize;

    public MinHeap(Node a[], int size) {
        heapSize = size;
        heapArray = a;
        int i = (heapSize - 1) / 2;
        while (i >= 0) {
            minHeapify(i);
            i--;
        }
    }

    void minHeapify(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < heapSize && heapArray[left].value < heapArray[i].value) {
            smallest = left;
        }
        if (right < heapSize && heapArray[right].value < heapArray[smallest].value) {
            smallest = right;
        }
        if (smallest != i) {
            Node temp = heapArray[i];
            heapArray[i] = heapArray[smallest];
            heapArray[smallest] = temp;
            minHeapify(smallest);
        }
    }

    Node getRoot() {
        if (heapSize <= 0) {
            return null;
        }
        return heapArray[0];
    }

    void replaceRoot(Node root) {
        heapArray[0] = root;
        minHeapify(0);
    }

    void swap(Node arr[], int i, int j) {
        Node temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    static int[] mergeSorted(int[][] arr, int k) {
        Node[] heapArray = new Node[k];
        int n = 0;
        for (int i = 0; i < k; i++) {
            heapArray[i] = new Node(arr[i][0], i, 1);
            n += arr[i].length;
        }

        MinHeap minHeap = new MinHeap(heapArray, k);
        int[] result = new int[n];

        for (int i = 0; i < n; i++) {
            Node root = minHeap.getRoot();
            result[i] = root.value;
            if (root.col < arr[root.row].length) {
                root.value = arr[root.row][root.col];
                root.col += 1;
            } else {
                root.value = Integer.MAX_VALUE;
            }
            minHeap.replaceRoot(root);
        }
        return result;
    }
}

public class MergeHeap {
    public static void main(String[] args) {
        int k = 3;
        int n = 4;
        int arr[][] = new int[k][n];
        arr = new int[][] { { 1, 3, 5, 7 }, { 2, 4, 6, 8 }, { 0, 9, 10, 11 } };

        int[] result = MinHeap.mergeSorted(arr, k);
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + " ");
        }
    }
}
