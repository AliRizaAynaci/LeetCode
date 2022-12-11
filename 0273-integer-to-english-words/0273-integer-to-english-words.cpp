class Solution {
public:
    string numberToWords(int num) {
        if(num==0)
	        return "Zero";

    string s="";
    string THOUSANDS[4] = {"","Thousand","Million","Billion"};
    string ONES[10]= {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    string TENS[10]= {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    string TENS1[10]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};

    int i=0;
    while(num!=0)
    {
    int ones = 0,tens=0,hunds=0;
    string s1="";

    ones = num%10; num=num/10; 
    tens = num%10; num=num/10;
    if(tens==1)
        s1 = TENS1[ones]+" "+s1;
    else
    {
        if(ones>0)  s1= ONES[ones]+ " "+s1;
        if(tens>0) s1 = TENS[tens]+" "+s1;
    }            
    hunds = num%10; num=num/10;
    if(hunds>0) s1 = ONES[hunds]+" Hundred"+" "+s1;

    if(i>0 && s1.size()>0) 
        s= s1+THOUSANDS[i]+" "+s;
    else
        s=s1+s;
    i++;
    }

    return s.substr(0,s.size()-1);
    }
};