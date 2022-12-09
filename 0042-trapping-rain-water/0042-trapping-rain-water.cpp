class Solution {
public:
    int trap(vector<int>& arr) {
        int len = arr.size();
        if(len <= 2) return 0;

        vector<int> left(len, 0), right(len, 0);
        left[0] = arr[0];
        right[len-1] = arr[len-1];

        for(int i = 1; i < len; i++){
            left[i] = max(left[i-1], arr[i]);
            right[len-i-1] = max(right[len-i], arr[len-i-1]);
        }

        int count = 0;
        for(int i = 0; i < len; i++){
            count += min(left[i], right[i]) - arr[i];
        }
        return count;
    }
};