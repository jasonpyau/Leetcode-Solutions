class Solution {
    static int p1, p2;
    public int calculate(String s) {
        String newInput = "";
        int num = 0;
        while (s.contains("(")) {
            try {
                p2 = s.length();
                newInput = solve(checkP(s));
                s = s.substring(0, p1) +newInput+ s.substring(p2+1);
                newInput = s;
            }
            catch (Exception e) {
                break;
            }
        }
        s = solve(s);
        return Integer.parseInt(s);
        
    }
    
    public static String checkP(String s) {
        String expression = "";
        p2 = s.indexOf(")");
        p1 = s.substring(0, p2).lastIndexOf("(");
        for (int i = p1+1; i < p2; i++) {
            if (s.charAt(i) != ' ')
                expression = expression + s.charAt(i);
        }
        return expression;
    }
    
    public static String solve(String s) {
        String num1 = "", num2 = "0";
        int i = 0; 
        if (s.contains("+-")) 
            s = s.substring(0,s.indexOf("+-")) + s.substring(s.indexOf("+-")+1);
        if (s.contains("--")) 
            s = s.substring(0,s.indexOf("--")) +"+"+ s.substring(s.indexOf("--")+2);
        boolean multipleOp = false;
        char op = ' ';
        int num = 0;
        for (i = i; i < s.length(); i++) {
            if ((s.charAt(i) == '+' || s.charAt(i) == '-') && i != 0) {
                op = s.charAt(i);
                break;
            }
            else if (s.charAt(i) == ' ') {}
            else
                num1 = num1 + s.charAt(i);
        }
        for (i = i+1; i < s.length(); i++) {
            if (s.charAt(i) == '+' || s.charAt(i) == '-') {
                multipleOp = true;
                break;
            }
            else if (s.charAt(i) == ' ') {}
            else
                num2 = num2 + s.charAt(i);
        }
        if (op == '+')
            num = Integer.parseInt(num1) + Integer.parseInt(num2);
        else
            num = Integer.parseInt(num1) - Integer.parseInt(num2);
        if(multipleOp)
            num = Integer.parseInt(solve(String.valueOf(num) + s.substring(i)));
        return String.valueOf(num);
    }
}
