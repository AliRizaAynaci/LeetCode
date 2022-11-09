class Solution {
public:
    int maximum69Number (int num) {
        int x=num,index=0,index6=-1; 
        while(x>0)
        {
            if(x%10==6)
            {
                index6=index;
            }
            index++;
            x=x/10;
        }
        if(index6==-1)
            return num;
        else
            return (num+3*pow(10,index6));
    }
};