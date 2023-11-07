public class quickSort {

    
    public static int partition(int[]a, int l , int h)
    {
        int i = l;
        int j = h;
        int p = a[l];

        while (i<j) {
            // do{
            //     i++;
            // }while(a[i]<=p);

            // do{
            //     j--;
            // }while(a[j]>p);

            while (i <= h && a[i] <= p) {
                i++;
            }
            while (a[j] > p) {
                j--;
            }

            if (i<j) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        int temp = a[l];
        a[l] = a[j];
        a[j] = temp;

        return j;
    }

    public static void quicksort(int[]a, int l, int h)
    {
        if (l<h) {
            int j = partition(a,l,h);
            quicksort(a, l, j);
            quicksort(a, j+1, h);
        }
    }

    public static void print(int[] a, int n)
    {
        for (int p = 0; p < n; p++) {
            System.out.print(a[p] + " ");
        }
    }

    public static void main(String[] args) {
        int[]a = {34,21,23,11,25,75,1};
        int n = a.length;
        quicksort(a, 0, n-1);
        print(a, n);
        
    }
    
}
