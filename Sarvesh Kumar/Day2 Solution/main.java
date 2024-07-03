
public class Main
{
    public static void mergeSort(int arr[] ,int startIndex, int endIndex){
        if(startIndex>=endIndex){
            return;
        }
        int mid= startIndex+(endIndex-startIndex)/2 ;     //or start+end/2
        mergeSort(arr,startIndex,mid ) ;  //left part sorted
        mergeSort(arr,mid+1,endIndex) ;     // right part sorted;
        
        merge(arr,mid,startIndex,endIndex);
        
    }
    
    public static void merge(int arr[],int mid, int startIndex,int endIndex){
        int temp[]=new int[endIndex-startIndex+1];  //creat a new arr
        int i= startIndex;   //itertor for leftpart
        int j=mid+1;          //iterator for rightpart
        int k=0;              //itertor for new arr
        
        while(i<=mid && j<=endIndex){
            if(arr[i]<arr[j]){
                temp[k]=arr[i];
                i++ ;
            } else{
                temp[k]=arr[j];
                j++;
            }
            k++;
        }
        
        
        //bache hue leftpart ke elemnet
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        
        //bache hue right part ke element
        while(j<=endIndex){
            temp[k++]=arr[j++];
        }
        
        //copy the temp arr eleemnt to original array
        for(k=0, i=startIndex; k<temp.length; k++ ,i++){
            arr[i]= temp[k];
            // System.out.print(arr[i]);
        }
    }
    
    
    
    //print the array
    public static void printArr(int arr[]){
        for(int i=0;i<arr.length;i++){
             System.out.print(arr[i]+" ");
             
        }
    }
	public static void main(String[] args) {
	    int arr[]={1,3,6,19,11,16};
	    mergeSort(arr,0,arr.length-1);
	    printArr(arr);
	}
}
