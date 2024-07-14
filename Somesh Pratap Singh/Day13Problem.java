package Array;

import java.util.HashMap;
import java.util.Map;

public class AdjacentnotSame
  {
  
    public static String rearrangeCharacters(String str)
     {
    
        StringBuilder p=new StringBuilder(str);
        HashMap<Character,Integer> m=new HashMap<>();
        for(int i=0;i<str.length();i++)
        {
            m.put(str.charAt(i),m.getOrDefault(str.charAt(i),0)+1);
        }
        char ch='a';
        int x=Integer.MIN_VALUE;
        for(Map.Entry<Character,Integer> e:m.entrySet())
        {
            if(e.getValue()>x)
            {
                x=e.getValue();
                ch=e.getKey();
            }
        }
        int i=0;
        while(x>0&&i<str.length())
        {
            p.setCharAt(i,ch);
            x--;
            i+=2;
        }
        if(x>0)
        return " ";
        m.remove(ch);
            for(Map.Entry<Character,Integer> e:m.entrySet())
            {
            int v=e.getValue();
            while(v>0){
            if(i>=str.length())
            i=1;
            p.setCharAt(i,e.getKey());
            v--;
            i+=2;
            }
        }
        return p.toString();
    
    }
    public static void main(String[] args) {
        String str="abbbcc";
        System.out.println(rearrangeCharacters(str));
    }
}
    

