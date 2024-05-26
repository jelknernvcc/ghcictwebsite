public class Act6_3 {
    public static void main(String[] args) {
        int meals[] = {0, 1, 1, 1, 1};
        double cost;

        if (meals[0] % 2 == 0)
        {
            cost = meals[0] * (1.75 + 2.08) / 2; 
        }
        else
        {
            cost = (meals[0] / 2 + 1) * 1.75 + (meals[0] / 2) * 2.08;      
        }
        cost += meals[1]*1.75 + meals[2]*2.08 + meals[3]*2.14 + meals[4]*0.98;

        System.out.println(cost);
    }
}
