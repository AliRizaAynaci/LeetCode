class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;
        unordered_map<char, int> targetFreq, windowFreq;
        for (char ch : s1) targetFreq[ch]++;

        for (int i = 0; i < n; i++) {
            windowFreq[s2[i]]++;
        }

        if (windowFreq == targetFreq) return true;

        for (int i = n; i < m; i++) {
            windowFreq[s2[i]]++;
            char leftChar = s2[i-n];
            windowFreq[leftChar]--;
            if (windowFreq[leftChar] == 0)
                windowFreq.erase(leftChar);
            if (windowFreq == targetFreq) return true;
        }

        return false;
    }
};