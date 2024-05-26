public class Act8_2 {
    public static void main(String[] args) {
        int[] d = {3, 7, 7, 2, 1}; 
        boolean valid;
        int sum = 0;
        int dd;
        
        for (int i = 1; i <= d.length; i++)
        {
              // Is right-to-left position even?
              if (i % 2  == 0)
              {
                  // If it is, set dd to twice the digit
                  dd = d[d.length - i] * 2;

                  // and add the sum of dd's digits to sum
                  sum += dd / 10 + dd % 10;
               }
               else
               {
                   // If it is odd, just add the digit to sum
                   sum += d[d.length - i];
                }
                System.out.println(sum);
        }
        
        valid = (sum % 10 == 0);
        System.out.println(valid);
    }
}
