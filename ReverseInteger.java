class Solution {
    public int reverse(int x) {
        int num = 0;
        long test;
        while (x!=0) {
                test = (long)num*10+(long)x%10;
                if (test>Integer.MAX_VALUE||test<Integer.MIN_VALUE)
                    return 0;
                num = num*10+x%10;
                x/=10;
        }
        return num;
    }
}
