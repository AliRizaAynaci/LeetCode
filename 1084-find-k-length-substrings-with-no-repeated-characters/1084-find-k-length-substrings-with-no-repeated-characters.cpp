class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if (s.size() < k) return 0;
        int l = 0, counter = 0;
        unordered_map<char, int> freq;
        for (int r = 0; r < s.size(); r++) {
            freq[s[r]]++;
            while (freq[s[r]] > 1) {
                freq[s[l]]--;
                if (freq[s[l]] == 0) freq.erase(s[l]);
                l++;
            }
            if (freq.size() == k) {
                counter++;
                freq[s[l]]--;
                if (freq[s[l]] == 0) freq.erase(s[l]);
                l++;
            }
        }
        return counter;
    }
};