bool sorted(vector<int>& v1, vector<int>& v2){
    return v1[1] < v2[1];
}
class Solution {
public:
    
    int findMinArrowShots(vector<vector<int>>& activities) {
        sort(activities.begin(), activities.end(), sorted);
        
        int counter = 0;
        int finish = activities[0][1];
        int len = activities.size();
        
        for(int i = 0; i < len; i++){
            
            if(counter == 0 or activities[i][0] > finish){
                counter++;
                finish = activities[i][1];
            }
            
        }  
        return counter;
    }
};