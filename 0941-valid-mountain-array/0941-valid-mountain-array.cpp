class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if( arr.size() < 3 or arr[0]>=arr[1] or arr[arr.size()-1]>=arr[arr.size()-2])
            return false;
        bool increasing = true, decreasing = true;
        int left = 0, right= arr.size()-1;
        while(left<right and (increasing or decreasing)){
			if(arr[left]<arr[left+1])    
				left++;
            else
				// since it is not strictly increasing we will make it false
                increasing = false;
            if(arr[right]<arr[right-1])
                right--;
            else
				// similarly if it not strictly decreasing we will make this false
                decreasing = false;
        }
        return left==right;
    }
};