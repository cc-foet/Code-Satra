public class Day6ques1 {
    public static void main(String[] args) {
        int ans =numWaterBottles(15,4);
        System.out.println(ans);
       
    }
        public static int numWaterBottles(int numBottles, int numExchange) {
            int totalDrank = numBottles; 
            
            int emptyBottles = numBottles;
            
            while (emptyBottles >= numExchange) {
                int newBottles = emptyBottles / numExchange; 
                totalDrank += newBottles; 
                emptyBottles = newBottles + (emptyBottles % numExchange); 
            }
            
            return totalDrank;
        }
        
        
    }
    

