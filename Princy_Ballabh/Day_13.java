import java.util.*;

class Key {
    int freq;
    char ch;
    Key(int val, char c){
        freq=val;
        ch=c;
    }
}

public class Day_13{
    public static void main(String args[]){
        String str="bbbaa";
        rearrange(str);
    }

    static void rearrange(String str) {
        int n=str.length();
        int[] count=new int[26];
        for(int i=0;i<n;i++)
            count[str.charAt(i)-'a']++;
        Comparator<Key> keyComparator=new Comparator<Key>(){
            @Override
            public int compare(Key k1, Key k2){
                return k2.freq-k1.freq;
            }
        };
        PriorityQueue<Key> pq=new PriorityQueue<>(keyComparator);
        for (char c='a';c<='z';c++){
            int val=c-'a';
            if(count[val]>0)
                pq.add(new Key(count[val], c));
        }
        String result="";
        Key prev=new Key(-1, '#');
        while(pq.size()!=0){
            Key k=pq.poll();
            result+=k.ch;
            if(prev.freq>0)
                pq.add(prev);
            k.freq--;
            prev=k;
        }
        if (n!=result.length())
            System.out.println("");
        else
            System.out.println(result);
    }
}
