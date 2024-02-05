class Solution {
    public List<String> letterCasePermutation(String s) {
        List<String> res = new ArrayList<String>();
        char[] curr = new char[s.length()];
        solve(0, curr, s, res);
        return res;
    }

    private void solve(int i, char[] curr, String s, List<String> res) {
        if (i == s.length()) {
            res.add(new String(curr));
            return;
        }
        char ch = s.charAt(i);
        if (Character.isLetter(ch)) {
            curr[i] = Character.toLowerCase(ch);
            solve(i+1, curr, s, res);
            curr[i] = Character.toUpperCase(ch);
            solve(i+1, curr, s, res);
        } else {
            curr[i] = ch;
            solve(i+1, curr, s, res);
        }
    }
}
