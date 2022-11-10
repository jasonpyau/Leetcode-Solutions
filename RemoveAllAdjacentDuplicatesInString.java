class Solution {
    public String removeDuplicates(String s) {
        ArrayDeque <Character> letters = new ArrayDeque<>();
        for (int i = 0; i < s.length(); i++) {
            if (!letters.isEmpty() && letters.peekLast() == s.charAt(i)) {
                letters.removeLast();
            }
            else {
                letters.add(s.charAt(i));
            }
        }
        StringBuilder sb = new StringBuilder();
        for(char letter : letters) {
            sb.append(letter);
        }
        return sb.toString();
    }
}
