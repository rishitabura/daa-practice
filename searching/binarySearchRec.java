public class binarySearchRec {

    public static int search(int[] a, int l, int h, int target) {

        while (l <= h) {

            int mid = (l + h) / 2;

            if (l == h) {
                if (a[l] == target) {
                    return l;
                } else {
                    return -1;
                }

            } else {
                if (target == a[mid]) {
                    return mid;
                } else if (target < a[mid]) {
                    return search(a, l, mid - 1, target);
                } else {
                    
                    return search(a, mid + 1, h, target);
                }
            }

        }
        return -1;

    }

    public static void main(String[] args) {

        int[] a = {3,5,65,23,121,23};
        int n = a.length;
        int ans = search(a, 0, n-1, 121);
        System.out.println(ans);

    }

}
