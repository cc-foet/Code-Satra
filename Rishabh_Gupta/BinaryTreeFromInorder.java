import java.util.ArrayList;
import java.util.List;

class Node {
    int key;
    Node left, right;

    Node(int item) {
        key = item;
        left = right = null;
    }
}

public class BinaryTreeFromInorder {
    static List<Node> getTrees(int[] arr, int start, int end) {
        List<Node> trees = new ArrayList<>();

        if (start > end) {
            trees.add(null);
            return trees;
        }

        for (int i = start; i <= end; i++) {
            List<Node> leftSubtrees = getTrees(arr, start, i - 1);
            List<Node> rightSubtrees = getTrees(arr, i + 1, end);

            for (Node left : leftSubtrees) {
                for (Node right : rightSubtrees) {
                    Node root = new Node(arr[i]);
                    root.left = left;
                    root.right = right;
                    trees.add(root);
                }
            }
        }

        return trees;
    }

    public static void main(String[] args) {
        int[] inorder = {4, 5, 7};
        List<Node> trees = getTrees(inorder, 0, inorder.length - 1);

        System.out.println("Number of possible Binary Trees: " + trees.size());
    }
}
