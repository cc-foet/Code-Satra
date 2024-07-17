
/*Find Greatest Common Divisor of two given numbers using Recursion.*/

import java.util.*;
public class Day4 {

    public static int Euclid(int x,int y){
        if (y==0) return x;
        return (Euclid(y,x%y));
    }
    public static void main(String[] args) {
        Scanner sc= new Scanner (System.in);
        System.out.println("Enter two numbers ");
        int x= sc.nextInt();
        int y= sc.nextInt();
        System.out.println("Greatest common divisor of "+x+" and "+y+" is "+Euclid(x,y));
    }
}

