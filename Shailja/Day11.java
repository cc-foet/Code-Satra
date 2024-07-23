public class Day11 {
    public static void main(String[] args) {
        int ans= minimumOperations("dac", "bac", "cac");

        System.out.println(ans); 
    }  
    public static int minimumOperations(String s1, String s2, String s3) {
        int minLength = Math.min(s1.length(), Math.min(s2.length(), s3.length()));
        int commonPrefixLength = 0;

        for (int i = 0; i < minLength; i++) {
            if (s1.charAt(i) == s2.charAt(i) && s1.charAt(i) == s3.charAt(i)) {
                commonPrefixLength++;
            } else {
                break;
            }
        }

        if (commonPrefixLength == 0) {
            return -1;
        }

        int totalLength = s1.length() + s2.length() + s3.length();
        int requiredLength = 3 * commonPrefixLength;

        return totalLength - requiredLength;
    }

        
}
