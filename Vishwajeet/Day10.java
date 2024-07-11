// Problem: Given an array thet represents inorder traversal, find the number of possble binary trees.

import java.math.BigInteger;

public class Day10 {

    // Function to calculate the nth Catalan number
    public static BigInteger catalanNumber(int n) {
        // Calculate (2n)!
        BigInteger factorial_2n = factorial(2 * n);

        // Calculate (n+1)!
        BigInteger factorial_n1 = factorial(n + 1);

        // Calculate n!
        BigInteger factorial_n = factorial(n);

        // Calculate Catalan number using the formula C_n = (2n)! / ((n+1)! * n!)
        return factorial_2n.divide(factorial_n1.multiply(factorial_n));
    }

    // Helper function to calculate factorial of a given number
    public static BigInteger factorial(int num) {
        BigInteger result = BigInteger.ONE;
        for (int i = 1; i <= num; i++) {
            result = result.multiply(BigInteger.valueOf(i));
        }
        return result;
    }

    public static void main(String[] args) {
        int[] inorderTraversal = {4, 5, 7}; // Example inorder traversal array
        int n = inorderTraversal.length;

        BigInteger numberOfBinaryTrees = catalanNumber(n);

        System.out.println("The number of possible binary trees is: " + numberOfBinaryTrees);
    }
}



/*Catalan Number Calculation:
The catalanNumber method calculates the nth Catalan number using the formula:
Cn = ( [(n+1)!n!] / (2n)!)
​
The factorial values are computed using the factorial method to handle large numbers effectively by using the BigInteger class.
Factorial Calculation:

The factorial method computes the factorial of a given number iteratively. It uses BigInteger to avoid overflow issues that can arise with large values. */