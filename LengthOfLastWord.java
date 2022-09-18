class Solution {
    public int lengthOfLastWord(String s) {
        int size = s.length(), letter = 0;
        for(int i = size-1; i >= 0; i--) {
            if ((s.charAt(i)>=65 && s.charAt(i) <= 90)||(s.charAt(i)>=97 && s.charAt(i) <= 122))
                letter += 1;
            if (s.charAt(i)==' '&&!(letter==0))
                return letter;
        }
        return letter;
    }
}
