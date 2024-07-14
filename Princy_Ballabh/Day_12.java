class Node { 
	int element;
	int i;
	int j; 
	public Node(int element, int i, int j) 
	{ 
		this.element = element; 
		this.i=i; 
		this.j=j; 
	} 
}

public class Day_12{ 
	Node harr[]; 
	int hsize; 
	public Day_12(Node a[], int size) 
	{ 
		hsize=size; 
		harr=a; 
		int i=(hsize-1)/2; 
		while(i>=0){ 
			MinHeap(i); 
			i--; 
		} 
	} 

    public static void main(String args[]) 
	{ 
		int arr[][]={{1,3,5,7}, 
					{2,4,6,8}, 
					{0,9,10,11}}; 
		System.out.println("Sorted merged array : "); 
		mergeArray(arr,arr.length); 
	} 

	void MinHeap(int i) 
	{ 
		int l=left(i); 
		int r=right(i); 
		int smallest=i;
		if(l<hsize && harr[l].element<harr[i].element) 
			smallest=l; 
		if(r<hsize && harr[r].element<harr[smallest].element) 
			smallest=r; 
		if(smallest!=i){ 
			swap(harr,i,smallest); 
			MinHeap(smallest); 
		} 
	}
	int left(int i)
    {
         return (2*i+1); 
    } 

	int right(int i)
    {
        return (2*i+2);
    } 

	Node getMin() 
	{ 
		if(hsize<=0) 
			return null; 
		return harr[0]; 
	} 

	void replaceMin(Node root) 
	{ 
		harr[0]=root; 
		MinHeap(0); 
	} 

	void swap(Node arr[], int i, int j) 
	{ 
		Node temp=arr[i]; 
		arr[i]=arr[j]; 
		arr[j]=temp; 
	} 
 
	static void printArray(int arr[]) 
	{ 
		for(int i:arr) 
			System.out.print(i+" "); 
		System.out.println(); 
	} 

	static void mergeArray(int arr[][], int K) 
	{ 
		Node arrr[]=new Node[K]; 
		int size=0; 
		for(int i=0;i<arr.length;i++){ 
			Node node=new Node(arr[i][0], i, 1); 
			arrr[i]=node; 
			size+=arr[i].length; 
		} 
		Day_12 mh=new Day_12(arrr, K); 
		int result[]=new int[size]; 
		for(int i=0;i<size;i++){
			Node root=mh.getMin(); 
			result[i]=root.element; 
			if(root.j<arr[root.i].length) 
				root.element=arr[root.i][root.j++]; 
			else
				root.element=Integer.MAX_VALUE; 
			mh.replaceMin(root); 
		} 
		printArray(result); 
	} 	
}


