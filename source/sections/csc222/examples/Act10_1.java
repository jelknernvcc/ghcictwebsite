public class Act10_1 {
    public static void main(String[] args) {
        int t = 29;
        String inwords;
        String[] smallnums = {"narf", "one", "two", "three", "four", "five",
                              "six", "seven", "eight", "nine", "ten",
                              "eleven", "twelve", "thirteen", "fourteen",
                              "fifteen", "sixteen", "seventeen", "eighteen",
                              "nineteen"};
        String[] tens = {"twenty", "thirty", "forty", "fifty"};

        if (t < 20)
            inwords = smallnums[t];
        else if (t % 10 == 0)
            inwords = tens[(t / 10) - 2];
        else
            inwords = tens[(t / 10) - 2] + " " + smallnums[t % 10];

        System.out.println(inwords);
    }
}
