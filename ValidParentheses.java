class Solution {
    public boolean isValid(String s) {
        ArrayList<Character> open = new ArrayList<>();
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(' || c == '[' ||c == '{') {
                open.add(open.size(), c);
                continue;
            }
            try {
                if (c == ')') {
                    if (open.remove(open.size()-1) != '(')
                        return false;
                }
                else {
                    if (open.remove(open.size()-1) != c-2)
                        return false;
                }
            }
            catch (Exception e) {
                return false;
            }
        }
        return (open.size() == 0) ? true : false;
    }
}
