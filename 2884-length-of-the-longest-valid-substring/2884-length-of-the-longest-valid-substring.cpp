class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string> forbiddens;
        for (string str : forbidden) forbiddens.insert(str);
        int l = word.size() - 1, r = l;
        int length = 0;
        while (l > -1) {
            for (int i = l; i <= min(r, l + 9); i++) {
                string substr = word.substr(l, i - l + 1);
                if (forbiddens.find(substr) != forbiddens.end()) {
                    r = i - 1;
                    break;
                }
            }
            length = max(length, r - l + 1);
            l--;
        }
        return length;
    }
};