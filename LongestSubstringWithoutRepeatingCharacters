class Solution {
   public static int lengthOfLongestSubstring(String s) {
        int length = 0;
        String temp = "";
        for (int i = 0; i < Math.abs(length-s.length()-1); i++) {
            temp = "";
            for (int k = i; k < s.length(); k++) {
                if (temp.contains(Character.toString(s.charAt(k))))
                    break;
                else
                    temp = temp + s.charAt(k);

                if (temp.length()>length) {
                    length++;
                }
            }
        }
        return length;
    }
}
