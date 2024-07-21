package Array;
import java.util.*;

public class Painter {

	static int totaal(int arr[], int from, int to)
	{
		int total = 0;
		for (int i = from; i <= to; i++)
			total += arr[i];
		return total;
	}

	
	static int partitionpainter(int arr[], int n, int k)
	{
		
		if (k == 1) 
			return totaal(arr, 0, n - 1);
		if (n == 1) 
			return arr[0];

		int best = Integer.MAX_VALUE;

		for (int i = 1; i <= n; i++)
			best = Math.min(
				best, Math.max(partitionpainter(arr, i, k - 1),
							totaal(arr, i, n - 1)));

		return best;
	}

	public static void main(String args[])
	{
		int arr[] = { 10, 20, 60, 50, 30, 40 };

		int n = arr.length;
		int k = 3;
		System.out.println(partitionpainter(arr, n, k));
	}
}


