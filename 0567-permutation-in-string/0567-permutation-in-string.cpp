class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;
        unordered_map<char, int> targetFreq, windowFreq;
        for (char ch : s1) {
            targetFreq[ch]++;
        }

        for (int i = 0; i < s1.size(); i++) {
            windowFreq[s2[i]]++;
        }
        
        if (windowFreq == targetFreq) return true;

        for (int i = s1.size(); i < s2.size(); i++) {
            windowFreq[s2[i]]++;
            char leftChar = s2[i - s1.size()];
            windowFreq[leftChar]--;
            if (windowFreq[leftChar] == 0) windowFreq.erase(leftChar);
            if (windowFreq == targetFreq) return true;
        }
        return false;
    }
};