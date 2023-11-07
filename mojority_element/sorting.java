package mojority_element;
import java.util.*;

public class sorting {
    
    public  static int sortingMajor(int [] a, int n)
    {   
        Arrays.sort(a);
        int count = 1;
        for(int i = 1; i<n;i++)
        {
            if (a[i-1] == a[i]) {
                count++;
                
            }
            else
            {
                if (count>n/2) {
                    return a[i-1];                    
                }
                else
                {
                    count = 1;
                }
            }
        }

        if (count>n/2) {
            return a[n-1];
        }

        return -1;

    }
    public static void main(String[] args) {

        int []a = {2, 4, 5, 2, 2, 6, 7, 2, 2};
        int n = a.length;

        System.out.println(sortingMajor(a, n));
        
    }
}
