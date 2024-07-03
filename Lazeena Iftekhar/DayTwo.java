public class DayTwo {

    public static void main(String[] args) {
    
        int[] arr = { 1, 3, 6, 19, 11, 16};
        int m =3;
        int n = 3;
        sortArray(arr, n, m);
    }

    static void sortArray(int arr[], int m, int n) { // last m elements sorting


        mergeSort(arr, n, m + n - 1);
    
    
        mergeSortedArrays(arr, 0, n - 1, n + m - 1);
    
        for (int val : arr) {
            System.out.print(val + "\t");
        }
    }
        
    
   
    static void mergeSort(int arr[], int i, int j) {
	if (i < j) {


		int mid = i + (j - i) / 2;

		
		mergeSort(arr, i, mid);
		mergeSort(arr, mid + 1, j);


		mergeSortedArrays(arr, i, mid, j);
	}
}


static void mergeSortedArrays(int a[], int l, int m, int r) {
	int x = m - l + 1;
	int y = r - m;


	int left[] = new int[x];
	int right[] = new int[y];


	for (int i = 0; i < x; i++)
		left[i] = a[l + i];


	for (int j = 0; j < y; j++)
		right[j] = a[j + m + 1];

	int i = 0, j = 0, k = l;


	while (i < x && j < y) {

		if (left[i] <= right[j]) {
			a[k] = left[i];
			i++;
		}

		else {
			a[k] = right[j];
			j++;
		}
		k++;
	}

	
	while (i < x) {
		a[k] = left[i];
		i++;
		k++;
	}

	while (j < y) {
		a[k] = right[j];
		j++;
		k++;
	}
}

    }


