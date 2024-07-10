## Matrix / 2D Array

To start we convert the given matrix into its spiral matrix.

To do that we first define the constraints for rows and column pointers.

Then we traverse the matrix in a spiral pattern i.e., starting with every column of first row, last column of every row, every column of last row but in reverse and so on.

After we get the spiral of the matrix we simply display the Kth element or (K-1)th index.