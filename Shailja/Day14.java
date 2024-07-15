public class Day14 {
    public static void main(String[] args) {
        
        int[] flowerbed1 = {1, 0, 0, 0, 1};
        int n1 = 1;
        boolean result1 = canPlaceFlowers(flowerbed1, n1);
        System.out.println(result1); 
}

public static  boolean canPlaceFlowers(int[] flowerbed, int n) {
    int length = flowerbed.length;
    
    for (int i = 0; i < length; i++) {
        if (flowerbed[i] == 0) {
            boolean emptyPrev = (i == 0) || (flowerbed[i - 1] == 0);
            boolean emptyNext = (i == length - 1) || (flowerbed[i + 1] == 0);
            
            if (emptyPrev && emptyNext) {
                flowerbed[i] = 1;
                n--;
                
                if (n == 0) {
                    return true;
                }
            }
        }
    }
    
    return n <= 0;
}
}
