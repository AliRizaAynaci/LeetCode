class Solution {
    public static boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        char[] parentheses = s.toCharArray();
        for (char ch : parentheses) {
            if (ch == '(' || ch == '[' || ch == '{') st.push(ch);
            if ((ch == ')' && !st.isEmpty() && st.pop() != '(') ||
                    (ch == ']' && !st.isEmpty() && st.pop() != '[') ||
                    (ch == '}' && !st.isEmpty() && st.pop() != '{')) {
                return false;
            }
        }
        return true;
    }
}