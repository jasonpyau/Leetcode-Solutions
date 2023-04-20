class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack();
        for (String t : tokens) {
            switch(t) {
                case "+":
                    int num2 = stack.pop(), num1 = stack.pop();
                    stack.push(num1+num2);
                    break;
                case "-":
                    num2 = stack.pop();
                    num1 = stack.pop();
                    stack.push(num1-num2);
                    break;
                case "*":
                    num2 = stack.pop();
                    num1 = stack.pop();
                    stack.push(num1*num2);
                    break;
                case "/":
                    num2 = stack.pop();
                    num1 = stack.pop();
                    stack.push(num1/num2);
                    break;
                default:
                    stack.push(Integer.parseInt(t));
                    break;
            }
        }
        return stack.pop();
    }
}
