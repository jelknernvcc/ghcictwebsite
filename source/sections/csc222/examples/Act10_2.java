public class Act10_2 {
    public static void main(String[] args) {
        int[] s = {21, 22, 973, 1000};
        String[] ordinals = new String[s.length];

        for (int i = 0; i < s.length; i++)
        {
            if (s[i] % 10 == 1) {
                ordinals[i] = (Integer.toString(s[i]) + "st");
            }
            else if (s[i] % 10 == 2) {
                ordinals[i] = (Integer.toString(s[i]) + "nd");
            }
            else if (s[i] % 10 == 3) {
                ordinals[i] = (Integer.toString(s[i]) + "rd");
            }
            else {
                ordinals[i] = (Integer.toString(s[i]) + "th");
            }
        }
        for (String ordval: ordinals)
            System.out.println(ordval);
    }
}
