class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        int start = 0, end = -1;
            
        int smallest = INT_MIN;
        int largest = INT_MAX;
        
        int i = 0;
        int j = len - 1;
    
        while (j >= 0){
            
            if(nums[i] >= smallest) smallest = nums[i];
            else end = i;
            
            if(nums[j] <= largest) largest = nums[j];
            else start = j;
            
            i++;
            j--;
        }
    
        return end - start + 1;
    }
};