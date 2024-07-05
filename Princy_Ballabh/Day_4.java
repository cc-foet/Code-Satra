public class Day_4{
    public static void main(String args[]){
        int n=5;
        int bills[]={5,5,5,10,20};
        System.out.println(change(n,bills));
    }

    public static boolean change(int n, int bill[]){
        int five=0,ten=0,i;
        for(i=0;i<n;i++){
            if(bill[i]==5)
            five++;
            else if(bill[i]==10 && five>0){
                ten++;
                five--;
            }
            else if(bill[i]==20 && ten>0 && five>0){
                ten--;
                five--;
            }
            else if(bill[i]==20 && five>2){
                five-=3;
            }
            else return false;
        }
        return true;
    }

}