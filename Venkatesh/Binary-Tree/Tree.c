#include <stdio.h>

int binaryTree(int inorder[], int n) {
    if (n <= 1) {
        return 1;
    } else {
        int total = 0;
        for (int root = 0; root < n; root++) {
            int left[root];
            int right[n - root - 1];

            for (int i = 0; i < root; i++) {
                left[i] = inorder[i];
            }

            for (int i = root + 1; i < n; i++) {
                right[i - root - 1] = inorder[i];
            }

            int leftSubtree = binaryTree(left, root);
            int rightSubtree = binaryTree(right, n - root - 1);

            total += leftSubtree * rightSubtree;
        }
        return total;
    }
}

void main() {
    int inorder[] = {4, 5, 7, 6, 8, 2};

    int n = sizeof(inorder) / sizeof(inorder[0]);
    printf("%d", binaryTree(inorder, n));
}