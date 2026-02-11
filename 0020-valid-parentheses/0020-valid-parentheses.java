class Solution {
    public boolean isValid(String s) {
        
        Stack<Character> st = new Stack<>();

        for (char ch : s.toCharArray()) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if (st.isEmpty() || ch == ')' && st.pop() != '(' 
                    || ch == ']' && st.pop() != '['
                    || ch == '}' && st.pop() != '{') {
                        return false;
                 }
            }
        }
        
        return st.isEmpty();
    }
}