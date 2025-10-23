class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.empty()) {
            return "";
        }

        unordered_map<string, int> freq;
        for (auto str : strs) {
            for (int i = 0; i < str.size(); i++) {
                freq[str.substr(0, i + 1)]++;            
            }
        }     

        int totalStrings = strs.size();
        string longestLCP = "";
        for (const auto& pair : freq) {
            const string& currentPrefix = pair.first;
            int currentFreq = pair.second;

            if (currentFreq == totalStrings) {
                if (currentPrefix.length() > longestLCP.length()) {
                    longestLCP = currentPrefix;
                }
            }
        }
        return longestLCP;
    }
};
