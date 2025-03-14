class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        if (words.size() == 0) return true;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                if (j >= words.size() || i >= words[j].size() || words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};