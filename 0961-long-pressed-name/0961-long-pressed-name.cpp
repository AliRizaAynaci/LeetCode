class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (j < typed.size()) {
            if (i < name.size() && name[i] == typed[j]) {
                i++;
            } 
            else if (j == 0 || typed[j] != typed[j - 1]) {
                return false;
            }
            j++;
        }
        return i == name.size(); 
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        /*
        unordered_map<char, int> nameMap;
        for (char ch : name) {
            nameMap[ch]++;
        }
        
        for (int i = 0; i < typed.size(); i++) {
            if (i > 0) {
                char previousCharacter = typed[i-1];
                if (nameMap.find(typed[i]) == nameMap.end() && (typed[i] == previousCharacter)) {
                    continue;
                }
            }
            if (nameMap.find(typed[i]) != nameMap.end()) {
                nameMap[typed[i]]--;
            }
            if (nameMap[typed[i]] == 0) nameMap.erase(typed[i]);
            
        }
        return nameMap.empty();
        */
    }
};