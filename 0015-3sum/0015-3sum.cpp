class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;

        // Pick every a[i], pair sum for remaining part
        for(unsigned int i = 0; i < n; i++){
            if((i > 0) and arr[i] == arr[i-1])
                continue;
            int j = i + 1;
            int k = n - 1;

            // two pointer approach
            while(j < k){
                int current_sum = arr[i] + arr[j] + arr[k];
                if(current_sum > 0){
                    k--;
                }
                else if(current_sum < 0){
                    j++;
                }
                else{
                    result.push_back({arr[i], arr[j], arr[k]});
                    while (j < k and arr[j]==arr[j+1]) j++;
                    while (j < k and arr[k]==arr[k-1]) k--;
                    j++;
                    k--;
                }
            }
        }
        return result;
    }
};