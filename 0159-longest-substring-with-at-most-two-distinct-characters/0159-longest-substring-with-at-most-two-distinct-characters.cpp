class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int l = 0, longest = 0;
        unordered_map<char, int> mp;
        for (int r = 0; r < s.size(); r++) {
            mp[s[r]]++;
            while (mp.size() > 2) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            longest = max(longest, r - l + 1);
        }
        return longest;
    }
};