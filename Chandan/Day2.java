/*Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. 
Find the order of characters in the alien language.*/

import java.util.*;

public class Day2 {
    public static void main(String[] args) {
        Solution alienDictionary = new Solution();
        String[] dict = {"baa", "abcd", "abca", "cab", "cad"};
        int N = 5;
        int K = 4;
        String order = alienDictionary.findOrder(dict, N, K);
        System.out.println(order);
    }

}


class Solution
{
    public String findOrder(String [] dict, int N, int K)
    {
      
        
        
     List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < K; i++) {
            adj.add(new ArrayList<>());
        }
        
        
        for(int i=0;i<N-1;i++){
            
            String s1=dict[i];
            String s2=dict[i+1];
            
            int len=Math.min(s1.length(),s2.length());
            
            for(int j=0; j<len;j++ ){
                
                
                if(s1.charAt(j)!=s2.charAt(j)){
                    
                    adj.get(s1.charAt(j)-'a').add(s2.charAt(j)-'a');
                    break;
                }
            }
            
            
        }
        
        List<Integer> tp=topo(K,adj);
        String ans="";
        for(int i: tp){
            
            ans=ans+(char)(i + (int)('a'));
            
        }
        
        
        return ans;
        
        
    }
    
    
    static List<Integer> topo(int k,List<List<Integer>> adj){
        
        int [] dig=new int[k];
        
        Queue<Integer> q=new LinkedList<>();
        
        
        for(int i=0;i<k;i++){
            
            for(int j:adj.get(i)){
                
                dig[j]++;
            }
        }
        
         for (int i = 0; i < k; i++) {
            if (dig[i] == 0) {
                q.add(i);
            }
        }
        
        
        List<Integer> ls=new ArrayList<>();
        
        while(!q.isEmpty()){
            
            
            int node=q.poll();
            ls.add(node);
            
            for(int i:adj.get(node)){
                
                dig[i]--;
                
                if(dig[i]==0){
                    
                    q.add(i);
                }
                
            }
        }
        
        return ls;
    }
}