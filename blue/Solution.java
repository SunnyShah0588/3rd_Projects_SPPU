    import java.io.*;
    import java.util.*;
    import java.text.*;
    import java.math.*;
    import java.util.regex.*;

    public class Solution {

        public static void main(String[] args) {

            Scanner sc=new Scanner(System.in);
            int n=sc.nextInt();            
            String ans="";
            if( n%2==1||n/2==0 || n/2=3 || n/2==4 || n/2==5 || n/2==6 || n/2==7 || n/2==8 || n/2==9 || n/2==10){
              ans = "Weird";
            }
            else{
                    ans = "Not Weird";
               
                
            }
            System.out.println(ans);
            
        }
    }
