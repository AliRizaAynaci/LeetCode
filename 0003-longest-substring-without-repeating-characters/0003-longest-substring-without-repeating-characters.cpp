class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.size();
        unordered_set<char> freq;
        int maxSize = 0;
        while (r < n) {
            char ch = s[r];
            while (freq.find(ch) != freq.end()) {
                freq.erase(s[l]);
                l++;
            }
            freq.insert(s[r]);
            maxSize = max(maxSize, (r-l+1));
            r++;
        }
        return maxSize;
    }
};