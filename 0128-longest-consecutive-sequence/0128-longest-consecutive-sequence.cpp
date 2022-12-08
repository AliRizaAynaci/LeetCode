class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return 0;
	    unordered_set<int> s;
	
        for(int x : arr){
            s.insert(x);
        }

        int longest = 1;

        for(auto element : s){

            int diff = element - 1;

            if(s.find(diff) == s.end()){

                int next_no  = element + 1;
                int count = 1;

                while(s.find(next_no) != s.end()){
                    next_no++;
                    count++;
                }
                if(count > longest){
                    longest = count;
                }
            }
        }
        return longest;
    }
};