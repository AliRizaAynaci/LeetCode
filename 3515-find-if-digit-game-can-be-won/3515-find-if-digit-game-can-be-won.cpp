class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int single_digits_sum = 0, double_digits_sum = 0;
        for (auto num : nums) {
            if (num < 10) {
                single_digits_sum += num;
            } else {
                double_digits_sum += num;
            }
        }
        return single_digits_sum > double_digits_sum || single_digits_sum < double_digits_sum;
    }
};