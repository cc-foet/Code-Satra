import java.util.Arrays;

public class Day15 {
    public static void main(String[] args) {
        String s1 = "listen";
        String t1 = "silent";
        boolean ans = isAnagram(s1, t1);
        System.out.println(ans);
    }

    public static boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        char[] schar = s.toCharArray();
        char[] tchar = t.toCharArray();

        Arrays.sort(schar);
        Arrays.sort(tchar);
        for (int i = 0; i < schar.length; i++) {
            if (schar[i] != tchar[i]) {
                return false;
            }
        }
        return true;
    }

}
