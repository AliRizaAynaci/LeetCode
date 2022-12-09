class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        
        //Create an output Array
        int n = arr.size();

        if(n == 1) return {0};
        int i, temp = 1;
        vector<int> output(n,1);

        for(i = 0; i < n; i++){
            output[i] = temp;
            temp *= arr[i];
        }

        temp = 1;

        for(i = n-1; i >= 0; i--){
            output[i] *= temp;
            temp *= arr[i];
        }

        return output;
    }
};