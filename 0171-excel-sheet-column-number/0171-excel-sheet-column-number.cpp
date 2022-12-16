class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        int n  = columnTitle.size();
        long pow = 1;
        
        for(int i = n-1; i >= 0; i--){
            ans = ans + (columnTitle[i] - 64)*pow;
            pow = pow*26;
        }
        return ans;
    }
};