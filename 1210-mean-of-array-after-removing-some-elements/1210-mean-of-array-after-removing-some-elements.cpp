class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int size = arr.size();
        int erasing_size = size * 0.05;
        double sum = 0;
        for (int i = erasing_size; i < size - erasing_size; i++) {
            sum += arr[i];
        }
        return sum / (size - erasing_size * 2);
    }
};