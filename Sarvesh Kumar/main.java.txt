
public class Main
{
    
    public static void bubbleSort(int numbers[]){
        int swap=1;
        for(int turn=0;turn<numbers.length-1;turn++){
            for (int j=0;j<numbers.length-1-turn;j++){
               if(numbers[j+1]<numbers[j]){ 
                   //swap
                int temp= numbers[j];
                numbers[j]=numbers[j+1];
                numbers[j+1]=temp;
                 swap++;
            }
         }
     }
    System.out.println( " Total Number OF Swap :" + swap);
    }
       public static void printArr(int numbers[]){
            for(int i=0;i<numbers.length;i++)
        System.out.print(numbers[i] + " ");
        
        }

    
	public static void main(String[] args) {
	int numbers[]={64,34,25,12,22,11,90};
	bubbleSort(numbers);
	printArr(numbers);
	}
}
