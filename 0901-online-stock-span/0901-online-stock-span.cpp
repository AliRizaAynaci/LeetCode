class StockSpanner {
public:
    stack<pair<int, int>> st;
    
    int next(int price) {
        int counter = 1;
        while(!st.empty() && st.top().first <= price){
            counter += st.top().second;
            st.pop();
        }
        st.push({price, counter});
        return counter;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */