public class Act6_2 {
    public static void main(String[] args) {
        String request = "child lo mein";
        int mealcode;

        if (request.indexOf("no beef") != -1 ||
            request.indexOf("chicken") != -1 &&
            request.indexOf("child") == -1)
        {
            mealcode = 1;
        }
        else if (request.indexOf("beef") != -1 &&
                 request.indexOf("child") == -1)
        {
            mealcode = 2;
        }
        else if (request.indexOf("vegetarian") != -1)
        {
            mealcode = 3;
        }
        else if (request.indexOf("child") != -1 &&
                 request.indexOf("vegetarian") == -1)
        {
            mealcode = 4;
        }
        else
        {
            mealcode = 0;
        }

        System.out.println(mealcode);
    }
}
