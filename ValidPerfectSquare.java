class Solution {
    public boolean isPerfectSquare(int num) {
        return ((int)(Math.sqrt(num)) == Math.sqrt(num)) ? true : false;
    }
}
