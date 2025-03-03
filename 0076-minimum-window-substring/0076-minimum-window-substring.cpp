class Solution {
public:
    string minWindow(string s, string t) {
         if (s.empty() || t.empty()) return "";

        unordered_map<char, int> freq;
        for (char ch : t) {
            freq[ch]++;
        }

        int i = 0, j = 0, left = 0, minLength = INT_MAX;
        int count = freq.size();

        while (j < s.size()) {
            char endChar = s[j++];
            if (freq.count(endChar)) {
                freq[endChar]--;
                if (freq[endChar] == 0) count--;
            }

            while (count == 0) {  // Valid window found
                if (j - i < minLength) {
                    left = i;
                    minLength = j - i;
                }

                char startChar = s[i++];
                if (freq.count(startChar)) {
                    freq[startChar]++;
                    if (freq[startChar] > 0) count++;
                }
            }
        }

        return minLength == INT_MAX ? "" : s.substr(left, minLength);
    }
};