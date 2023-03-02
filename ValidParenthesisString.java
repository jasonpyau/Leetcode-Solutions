class Solution {
    public boolean checkValidString(String s) {
        Stack<Integer> parens = new Stack<>();
        Stack<Integer> options = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(')
                parens.push(i);
            else if (c == '*')
                options.push(i);
            else if (c == ')') {
                if (parens.empty()) {
                    if (options.empty())
                        return false;
                    else 
                        options.pop();
                } else
                    parens.pop();
            }
        }

        while (!parens.empty() && !options.empty()) {
            if (parens.pop() > options.pop())
                return false;
        }
        return parens.empty();
    }
}
