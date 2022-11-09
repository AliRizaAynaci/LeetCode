class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
       unordered_map<int, int> seen;
       for(int i = 0; i < nums.size(); ++i){
            int b = nums[i], a = target - b;
            if(seen.count(a))
                return {seen[a], i};
            seen[b] = i;
       }
       return {};
    }
};