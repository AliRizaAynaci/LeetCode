class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int n = arr.size();
        int largest = 0;

        for(int i = 1; i <= n-2;){

            if(arr[i] > arr[i-1] and arr[i] > arr[i+1]){
                int counter = 1;
                int j = i;
                // backward counter (left)
                while(j >= 1 and arr[j] > arr[j-1]){
                    j--;
                    counter++;
                }
                // forward counter (right)
                while(i <= n-2 and arr[i] > arr[i+1]){
                    i++;
                    counter++;
                }
                largest = max(largest, counter);
            }
            else
                i++;
        }
        return largest;
        
    }
};