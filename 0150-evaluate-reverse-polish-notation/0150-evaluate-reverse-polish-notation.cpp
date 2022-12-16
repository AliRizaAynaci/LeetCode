class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        
        for(int i = 0; i < tokens.size(); i++){
            
            if(tokens[i] == "+" or tokens[i] == "-" or tokens[i] == "*" or tokens[i] == "/"){
                //2 elements
                long v1 = st.top();
                st.pop();
                long v2 = st.top();
                st.pop();
                
                if(tokens[i] == "+"){
                    st.push(v2 + v1);
                }
                
                else if(tokens[i] == "-"){
                    st.push(v2 - v1);
                }
                
                else if(tokens[i] == "*"){
                    st.push(v2 * v1);
                }
                
                else if(tokens[i] == "/"){
                    st.push(v2 / v1);
                }                   
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};