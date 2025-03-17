class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums2.size(); i++) {
            mp[nums2[i]] = i;
        }
        vector<int> res;
        for (int num : nums1) {
            if (mp.find(num) != mp.end()) {
                res.push_back(mp[num]);
            }
        }
        return res;
    }
};