class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        //Complete this function, your function should return the maximum subarray sum

        int curMax = 0, MaxTillNow = INT_MIN;
        for(auto c : arr){
            curMax = curMax + c;
            MaxTillNow = max(MaxTillNow, curMax);
            if(curMax < 0)
                curMax = 0;
        }
        return MaxTillNow;
    }
};