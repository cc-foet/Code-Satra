public class Day_9 {
    public static void main(String[] args) 
    { 
        int arr[][]={{1,2,3,4}, 
                    {5,6,7,8}, 
                    {9,10,11,12},
                    {13,14,15,16}}; 
        int k=7;
        int r=4,c=4; 
        System.out.println(spiral(arr,k,r,c)); 
    } 

    public static int spiral(int arr[][],int k,int r,int c){
        int i=0,j=0,a=0; 
        int count=0;
        while(i<r && j<c){
            for(a=j;a<c;a++){ 
                count++;
                if(count==k) 
                    return arr[i][a];
            } 
            i++; 
            for(a=i;a<r;a++){ 
                count++; 
                if(count==k) 
                    return arr[a][c-1];
            } 
            c--; 
            if(i<r){ 
                for(a=c-1;a>=j;a--){ 
                    count++;
                    if(count==k)
                    return arr[r-1][a];
                } 
                r--; 
            } 
            if(j<c){ 
                for(a=r-1;a>=i;a--){ 
                    count++;     
                    if(count==k) 
                        return arr[a][j]; 
                } 
                j++; 
            } 
        } 
        return -1;
    }
}
