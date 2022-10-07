class Solution {
    public int maximum69Number(int num) {
        int n = (int)Math.log10(num);
        for(; n >= 0; n--) {
            if((int)(num/Math.pow(10, n))%10 == 6) return num+(int)(Math.pow(10,n)*3);
        }
        return num;
    }
}
