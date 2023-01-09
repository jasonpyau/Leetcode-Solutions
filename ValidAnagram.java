class Solution {
    public boolean isAnagram(String s, String t) {
        HashMap<Character, Integer> letters = new HashMap<>();
        for(int i = 0; i < s.length(); i++) {
            char letter = s.charAt(i);
            if (letters.get(letter) == null) {
                letters.put(letter, 1);
            }
            else {
                letters.replace(letter, letters.get(letter)+1);
            }
        }

        for(int i = 0; i < t.length(); i++) {
            char letter = t.charAt(i);
            if (letters.get(letter) == null) {
                return false;
            }
            else {
                int remainder = letters.get(letter)-1;
                if (remainder == 0) {
                    letters.remove(letter);
                }
                else {
                    letters.replace(letter, remainder);
                }
            }
        }

        return (letters.size() == 0) ? true : false;
    }
}
