class Solution {
    public int longestContinuousSubstring(String s) {
    char lastChar = (char)(s.charAt(0)-1);
        int length = 0, temp = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i)==(char)((lastChar)+1)) {
                lastChar++;
                temp++;
            }
            else {
                if (temp>0)
                    i--;
                length = (length>temp) ? length : temp;
                lastChar = (char)(s.charAt(i+1)-1);
                temp = 0;
            }
        }
        return (temp>length) ? temp : length;
    }
}
    
            
