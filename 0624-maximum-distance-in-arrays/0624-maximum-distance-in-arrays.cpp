class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int minValue = INT_MAX, secondMin = INT_MAX;
        int maxValue = INT_MIN, secondMax = INT_MIN;
        int minIndex = -1, maxIndex = -1;

        for (int i = 0; i < n; i++) {
            int localMin = arrays[i][0];
            int localMax = arrays[i].back();

            if (localMin < minValue) {
                secondMin = minValue;
                minValue = localMin;
                minIndex = i;
            } else if (localMin < secondMin) {
                secondMin = localMin;
            }

            if (localMax > maxValue) {
                secondMax = maxValue;
                maxValue = localMax;
                maxIndex = i;
            } else if (localMax > secondMax) {
                secondMax = localMax;
            }
        }

        if (minIndex != maxIndex) {
            return maxValue - minValue;
        }
        
        return max(maxValue - secondMin, secondMax - minValue);
    }
};