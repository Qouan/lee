class Solution {
    public int primePalindrome(int N) {
        if (N <= 2) return 2;
        N = N%2==0 ? N+1 : N;//将N处理为奇数
        for (int i = N;  ; ) {
            int k = i;
            int len = 0;//判断数字的位数
            int[] nums = new int[10];
            while(k / 10 != 0){//将判断的数字处理放入数组中
                nums[len++] = k % 10;
                k /= 10;
            }
            nums[len++] = k;

            if ( len%2 == 0 && i != 11) //判断是否是除11之外的偶数位数字
                i = (int)Math.pow(10,len)+1;//直接跳过偶数位数字
            else {
                if (isHui(i,nums,len)) //是否是回文 即判断一下数组中的数字是否对称
                    if (isprime(i)) return i;//是否是素数
                i+=2;
            }
        }
    }

    public static boolean isprime(int i){
        for (int j = 2; j <= Math.sqrt(i); j++)
            if (i % j == 0) return false;
        return true;
    }

    public static boolean isHui(int i, int[] nums, int len){
        for (int j = 0; j < len/2; j++)
            if (nums[j] != nums[len-j-1]) return false;
        return true;
    }

}
