class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        
        int i =0, j = 0;
        
        String newstr1 = "";
        String newstr2 = "";
        
        while(i < word1.length){
            newstr1 += word1[i];
            i ++;
        }
        
        
        while(j < word2.length){
            newstr2 += word2[j];
            j ++;
        }
    
        
        if(newstr1.equals(newstr2)){
            return true;
        }
            
        else{
            return false;
        }
        
    }
}