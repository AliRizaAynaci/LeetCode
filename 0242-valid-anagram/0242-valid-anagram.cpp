class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq;

        for (auto ch : s) {
            freq[ch]++;
        }

        for (auto ch : t) {
            if (freq.find(ch) != freq.end()) {
                freq[ch]--;
                if (freq[ch] == 0) freq.erase(ch);
            } else {
                return false;
            }
        }

        if (freq.size() != 0) return false;

        return true;
    }
};