class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.size();
        unordered_map<char, int> freq;
        int maxSize = 0;
        while (r < n) {
            char ch = s[r];
            while (freq.find(ch) != freq.end()) {
                freq[s[l]]--;
                if (freq[s[l]] == 0) freq.erase(s[l]);
                l++;
            }
            freq[s[r]]++;
            maxSize = max(maxSize, (r-l+1));
            r++;
        }
        return maxSize;
    }
};