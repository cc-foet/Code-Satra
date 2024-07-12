public class Tree {

    public static int binaryTree(int[] inorder) {
        int n = inorder.length;
        if (n <= 1) {
            return 1;
        } else {
            int total = 0;
            for (int root = 0; root < n; root++) {
                int[] left = new int[root];
                int[] right = new int[n - root - 1];

                for (int i = 0; i < root; i++) {
                    left[i] = inorder[i];
                }

                for (int i = root + 1; i < n; i++) {
                    right[i - root - 1] = inorder[i];
                }

                int leftSubtree = binaryTree(left);
                int rightSubtree = binaryTree(right);

                total += (leftSubtree * rightSubtree);
            }
            return total;
        }
    }

    public static void main(String[] args) {
        int[] inorder = {4, 5, 7, 6, 8};

        System.out.println(binaryTree(inorder));
    }
}