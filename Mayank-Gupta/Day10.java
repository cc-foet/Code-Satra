/*Problem: Given a string containing digits from 2-9 inclusive,
return all possible letter combination that the number could represent.
 Return the answer in any order.*/

import java.util.Scanner;

public class Day10 {

        public static void combination(String dig, String kp[],String res){
            //base case
            if (dig.length()==0) {
                System.out.println(res + " ");
                return;
            }
            int currnum = dig.charAt(0)-'0';
            String Currchoice=kp[currnum];
            for (int i=0;i<Currchoice.length();i++){
                combination(dig.substring(1),kp,res+Currchoice.charAt(i));
            }

        }
        public static void main(String args[]){
            String kp[]=new String[]{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
            //                        0  1   2     3     4     5     6      7     8      9
            Scanner sc= new Scanner(System.in);
            String s=sc.nextLine();
            combination(s,kp,"");
        }
    }

