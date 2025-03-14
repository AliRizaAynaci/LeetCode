class Solution {
public:
    bool confusingNumber(int n) {
        unordered_map<char, char> mp = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        string rotatedNumber;
        for (char ch : to_string(n)) {
            if (mp.find(ch) == mp.end()) return false;
            rotatedNumber += mp[ch];
        }
        reverse(begin(rotatedNumber), end(rotatedNumber));
        return stoi(rotatedNumber) != n;
    }
};