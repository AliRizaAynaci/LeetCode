class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> minHeap;
        for(auto& p : points){
            int x = p[0], y = p[1];
            minHeap.push_back({-x*x - y*y, x, y});
        }
        make_heap(minHeap.begin(), minHeap.end());
        vector<vector<int>> ans;
        
        while(k--){
            vector<int> top = minHeap[0];
            pop_heap(minHeap.begin(), minHeap.end());
            minHeap.pop_back();
            
            ans.push_back({top[1], top[2]});
        }
        return ans;
    }
};