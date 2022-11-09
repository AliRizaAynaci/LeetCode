class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        while(1){    
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }
        int secondslow = 0;
        while(1){
            slow = nums[slow];
            secondslow = nums[secondslow];
            if(slow == secondslow) return slow;

        }    
    }

    

};