   public class Bill {
       
       public static void main (String [] args){
           float rate = 5000.0f;
           int qty = 5;
           float gross = 0.0f;
           float discount = 0.0f;
           float net = 0.0f;
           
           gross=rate*qty;
           
           discount=(5*gross)/100;
           net=gross-discount;
           
           System.out.println("Gross Amount is "+gross);
           System.out.println("NET BILL AMOUNT IS"+net);
           
           
           
           
        }
    }
    
       
       
     