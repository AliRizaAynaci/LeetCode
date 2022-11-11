class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int rowsize = size(wall), maxgapNumber = 0;
        unordered_map<int, int> hashmap;
        
        for(auto& row : wall){
            int gapIndex = 0;
            for(int i = 0; i < size(row) - 1; i++){
                gapIndex += row[i];
                hashmap[gapIndex] ++;
                maxgapNumber = max(maxgapNumber, hashmap[gapIndex]);

            }
        }
        return rowsize  - maxgapNumber;
    }
};