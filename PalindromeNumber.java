class Solution {
    public boolean isPalindrome(int x) {
        String xString = Integer.toString(x), temp = "";
        int size = xString.length();
        for (int i = size; i > 0; i--) {
            temp = temp + xString.charAt(i-1);
        }
        if (xString.equals(temp))
            return true;
        else
            return false;
    }
}
