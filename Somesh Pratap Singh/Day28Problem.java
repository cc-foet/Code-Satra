
public class Increments {

    private int[] segmentTree;
    private int[] prefix;

    public Increments(int[] arr) {
        int n = arr.length;
        segmentTree = new int[4 * n];
        prefix = new int[n + 1];
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        buildTree(arr, 0, n - 1, 0);
    }

    private int buildTree(int[] arr, int start, int end, int node) {
        if (start == end) {
            segmentTree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            segmentTree[node] = Math.max(buildTree(arr, start, mid, 2 * node + 1),
                    buildTree(arr, mid + 1, end, 2 * node + 2));
        }
        return segmentTree[node];
    }

    private int query(int start, int end, int l, int r, int node) {
        if (start > r || end < l) {
            return -1;
        }
        if (start >= l && end <= r) {
            return segmentTree[node];
        }
        int mid = (start + end) / 2;
        return Math.max(query(start, mid, l, r, 2 * node + 1),
                query(mid + 1, end, l, r, 2 * node + 2));
    }

    public int longestSubarray(int[] arr, int len, int k) {
        int res = 1;
        for (int i = 0; i < len; i++) {
            int start = i;
            int end = len - 1;
            int maxIndex = i;

            while (start <= end) {
                int mid = (start + end) / 2;
                int maxNum = query(0, len - 1, i, mid, 0);

                int sumExpected = (mid - i + 1) * maxNum;
                int sumActual = prefix[mid] - prefix[i] + arr[i];

                if (sumActual + k >= sumExpected) {
                    maxIndex = mid;
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            res = Math.max(res, maxIndex - i + 1);
        }
        return res;
    }

    public static void main(String[] args) {
        int[] arr = {2, 0, 4, 6, 7};
        int k = 6;
        Increments st = new Increments(arr);
        System.out.println(st.longestSubarray(arr, arr.length, k));
    }
}
