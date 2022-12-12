class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        
        int jump = 0;
        int largest = 0;
        int curr = 0;
        
        for(int i = 0; i < n - 1; i++){
            largest = max(largest, i + nums[i]);
            if(i == curr){
                jump++;
                curr = largest;
            }
        }
        return jump;
    }
};