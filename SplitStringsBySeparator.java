class Solution {
    public List<String> splitWordsBySeparator(List<String> words, char separator) {
        StringBuilder sb = new StringBuilder();
        List<String> ans = new LinkedList<>();
        for (String word : words) {
            for (char ch : word.toCharArray()) {
                if (ch == separator) {
                    if (sb.length() != 0) {
                        ans.add(sb.toString());
                    }
                    sb.setLength(0);
                } else {
                    sb.append(ch);
                }
            }
            if (sb.length() != 0) {
                ans.add(sb.toString());
                sb.setLength(0);
            }
        }
        return ans;
    }
}
