class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        for (String str : tokens) {
            if (str.equals("+") || str.equals("-") ||
                    str.equals("*") || str.equals("/")) {
                String res = "";
                int num2 = stack.pop();
                int num1 = stack.pop();
                switch (str) {
                    case "+":
                        stack.push(num1 + num2);
                        break;
                    case "-":
                        stack.push(num1 - num2);
                        break;
                    case "*":
                        stack.push(num1 * num2);
                        break;
                    case "/":
                        stack.push(num1 / num2);
                        break;
                }
            } else {
                stack.push(Integer.parseInt(str));
            }
        }
        return stack.pop();
    }
}