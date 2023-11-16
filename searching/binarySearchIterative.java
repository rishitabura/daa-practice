class binarySearchIterative{

    public static int search(int[] nums, int target)
    {
        int l = 0;
        int h = nums.length;
        int m;
        while(l<=h){
            m = (l+h)/2;
            if(target == nums[m])
            {
                return m;
            }
            else if(target < nums[m])
            {
                h = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        return -1;
        // return l;     // for search insert
        
    }
    public static void main(String[] args) {

        int[] a = {11,54,12,14,13};
        int ans = search(a, 12);
        System.out.println(ans);

        
    }
}