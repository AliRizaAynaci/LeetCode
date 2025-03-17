class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (s.size() < k) return s.size();
        int maxLength = 0, left = 0, n = s.size();
        unordered_map<char, int> count;
        for (int right = 0; right < n; right++) {
            count[s[right]]++;
            while (count.size() > k) {
                count[s[left]]--;
                if (count[s[left]] == 0) count.erase(s[left]);
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};