class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<pair<int, int>> st;
        heights.push_back(INT_MIN);

        for (int height : heights) {
            int step = 0;
            while (!st.empty() && st.top().second >= height) {
                int w = st.top().first;
                int h = st.top().second;
                st.pop();
                step += w;
                res = max(res, step * h);
            }
            st.push({step+1, height});
        }
        return res;
    }
};