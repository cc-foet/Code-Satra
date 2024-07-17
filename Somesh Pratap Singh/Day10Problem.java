package Array;

public class treee 
{
    public static int countBinaryTrees(int[] inorder)
     {
        int n = inorder.length;
        int[] T = new int[n + 1];
        T[0] = 1;
        T[1] = 1;

        for (int i = 2; i <= n; i++) 
        {
            for (int j = 0; j < i; j++) 
            {
                T[i] += T[j] * T[i - j - 1];
            }
        }

        return T[n];
    }

    public static void main(String[] args)
     {
        
        int[] inorder = {1, 2, 3, 5};

       
        int numTrees = countBinaryTrees(inorder);

       
        System.out.println("Number of possible binary trees: " + numTrees);
    }
}
