public class Day9 {
    public static int searchspiral(int m[][],int k){
        int r=m.length,c=m[0].length;
        int tr=0,br=r-1,rc=c-1,lc=0;
        int totele=0;
        while (totele<(r*c)){
            //Traversing toprow
            for (int i=lc;i<=rc && totele<(r*c);i++){
                 if (k==totele) return m[tr][i];
                 totele++;
            }
            tr++;
           //Travesing right-column
           for (int i=tr;i<=br && totele<(r*c);i++){
            if (k==totele) return m[i][rc];
            totele++;
       }
       rc--;
       //Traversing bottom-row
       for (int i=rc;i<=lc && totele<(r*c);i++){
        if (k==totele) return m[br][i];
        totele++;
   }
   br--;
   //Trvaersing left-column
   for (int i=br;i<=tr && totele<(r*c);i++){
    if (k==totele) return m[i][lc];
    totele++;
    }
     lc++;
        }
        return -99999;//Garbage value
    }
    public static void main(String[] args) {
        int m[][]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
        int k=7;
        System.out.println(searchspiral(m,k-1));
    }
    
}
