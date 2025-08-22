class Solution {
public:
    // Time Comp -> O(n)
    // Space Comp -> O(n)
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0, maxLen = 0;
        unordered_map<char, int> freq;
        for (int right = 0; right < n; right++) {
            char ch = s[right];
            while (freq.find(ch) != freq.end()) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) freq.erase(s[left]);
                left++;
            }
            freq[s[right]]++;
            maxLen = max(maxLen, (right - left + 1));
        }
        return maxLen;
    }
};