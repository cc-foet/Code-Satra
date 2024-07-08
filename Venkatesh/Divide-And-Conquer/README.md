## Divide & Conquer

To obtain the element at the given position we first need to merge the given 2 arrays.

Since we know that both the arrays are sorted, we can just merge them as we do in merge sort.

After we get the final sorted array after merging, the element at kth position will be at (k-1)th index.