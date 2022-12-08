class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        if(arr.size() < 3)
            return false;
        int n = arr.size();
        int i = 0;
        //up
        while(i < n-1 and arr[i] < arr[i+1])
            i++;
        
        if(i == n-1 or i == 0)
            return false;
        
        //down
        while(i < n-1 and arr[i] > arr[i+1])
            i++;
        
        return i == n-1;
    }
};