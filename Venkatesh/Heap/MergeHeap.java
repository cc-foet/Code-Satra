class Node {
    int data;
    int i;
    int j;
    public Node(int data, int i, int j) {
        this.data = data;
        this.i = i;
        this.j = j;
    }
}

class MinHeap {
    Node[] heapArr;
    int heapSize;

    public MinHeap(Node a[], int size) {
        heapSize = size;
        heapArr = a;
        int i = (heapSize - 1) / 2;
        while (i >= 0) {
            minHeapify(i);
            i--;
        }
    }
    
    void minHeapify(int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;
        if (l < heapSize && heapArr[l].data < heapArr[i].data) {
            smallest = l;
        }
        if (r < heapSize && heapArr[r].data < heapArr[smallest].data) {
            smallest = r;
        }
        if (smallest != i) {
            Node temp = heapArr[i];
            heapArr[i] = heapArr[smallest];
            heapArr[smallest] = temp;
            minHeapify(smallest);
        }
    }

    Node getRoot() {
        if (heapSize <= 0) {
            return null;
        }
        return heapArr[0];
    }

    void replaceRoot(Node root) {
        heapArr[0] = root;
        minHeapify(0);
    }

    void swap(Node arr[], int i, int j) {
        Node temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    static int[] mergeSorted(int[][] arr, int k) {
        Node[] heapArr = new Node[k];
        int n = 0;
        for (int i = 0; i < k; i++) {
            heapArr[i] = new Node(arr[i][0], i, 1);
            n += arr[i].length;
        }

        MinHeap minHeap = new MinHeap(heapArr, k);
        int[] result = new int[n];

        for (int i = 0; i < n; i++) {
            Node root = minHeap.getRoot();
            result[i] = root.data;
            if (root.j < arr[root.i].length) {
                root.data = arr[root.i][root.j];
                root.j += 1;
            } else {
                root.data = Integer.MAX_VALUE;
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