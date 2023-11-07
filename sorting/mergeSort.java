public class mergeSort {

    public static void Merge(int[] A, int l, int h, int mid) {
        int n = A.length;
        int i = l;
        int j = mid + 1;
        int k = l;
        int[] B = new int[n];

        while (i <= mid && j <= h) {
            if (A[i] <= A[j]) {
                B[k] = A[i];
                i++;
                k++;
            }
            if (A[i] > A[j]) {
                B[k] = A[j];
                j++;
                k++;
            }

        }
        while (i <= mid) {
            B[k] = A[i];
            i++;
            k++;
        }
        while (j <= h) {
            B[k] = A[j];
            j++;
            k++;
        }

        for (int z = l; z <= h; z++) {
            A[z] = B[z];
        }

    }

    public static void mergesort(int[] A, int l, int h) {
        if (l < h) {
            int mid = (l + h) / 2;
            mergesort(A, l, mid);
            mergesort(A, mid + 1, h);
            Merge(A, l, h, mid);
        }
    }
    

    public static void print(int[] a, int n)
    {
        for (int p = 0; p < n; p++) {
            System.out.print(a[p] + " ");
        }
    }

    public static void main(String[] args) {
        int[] num = {4,45,31,54,23,77,1};
        int n= num.length;
        mergesort(num, 0, n-1);
        print(num, n);
        // for (int p = 0; p < n; p++) {
        //     System.out.print(num[p] + " ");
        // }

    }

}
