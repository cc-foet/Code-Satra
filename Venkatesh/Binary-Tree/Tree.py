def binary_tree(inorder):
    n = len(inorder)
    if n <= 1:
        return 1
    else:
        total = 0
        for i in range(n):
            left_subtree = binary_tree(inorder[:i])
            right_subtree = binary_tree(inorder[i+1:])
            total += left_subtree * right_subtree
        return total

inorder = [4, 5, 7, 6]
total_trees = binary_tree(inorder)
print("Total possible number of binary trees:", total_trees)
