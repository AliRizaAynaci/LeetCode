class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        unordered_map<char, int> seen;
        int max_size = INT_MIN;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            char ch = s[right];
            if (seen.find(ch) != seen.end()) {
                left = max(left, seen[ch]+1);
            }
            seen[ch] = right;
            max_size = max(max_size, (right - left + 1));
        }
        return max_size;
    }
};