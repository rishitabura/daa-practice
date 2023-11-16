

public class honoi_count {
    static int hanoi(int n ,char source, char dest, char inter, int k , int count )
    {
//        int count = 0;
        if (n == 0)
        {
            System.out.println("No disk present");
            return  count;
        }
        if (n==1)
        {
            count++;
            if (count == k)
            {
                System.out.println("Move disk " + n + " from " + source+ " to "+ dest + " in " + k + " move");
            }
            return count;
        }

            count = hanoi(n-1, source, inter, dest, k , count);
            count++;
            if (count == k)
            {
                System.out.println("Move disk " + n + " from " + source+ " to "+ dest + " in " + k + " move");
                return  count;
            }
             return  hanoi(n-1, inter, dest, source, k , count);

    }


    public static void main(String[] args) {
        int n = 3;
        int count = 0;
        int k = 5;
        System.out.println("At the "+ k+ "th move : ");
        hanoi(n,'A', 'C', 'B', k,count);
        //System.out.println("");


    }
}

