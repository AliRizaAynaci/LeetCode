class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long totalsum = 0, currentsum = 0;
        int n = nums.size();
        
        for(auto i: nums){
            totalsum += i;
        }
        int mini = INT_MAX;
        int indexans = 0;
        
        for(int i = 0; i < n; i++){
            
            currentsum += nums[i];
            int average1 = currentsum / (i + 1);
            if(i == n - 1)
            {
                if(average1 < mini)
                    return n - 1;
                else
                    break;
            }
            int average2 = (totalsum - currentsum) / (n - i - 1);
            if(abs(average1 - average2) < mini){
                mini = abs(average1 - average2);
                indexans = i;
            }
        }
        return indexans;
    }
};