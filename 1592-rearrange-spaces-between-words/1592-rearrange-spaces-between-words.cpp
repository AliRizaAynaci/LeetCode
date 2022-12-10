class Solution {
public:
	vector<string>words;
    string reorderSpaces(string str) 
	{
        int space_count=0;
        int idx = 0;
        
        while(idx < str.length())
        {
        	string temp="";
        	while(idx<str.length() and (str[idx]>='a' and str[idx]<='z'))
        	{
        		temp.push_back(str[idx]);
        		idx++;
			}
			while(idx<str.length() and str[idx] == ' ')
			{
				space_count++;
				idx++;
			}
			
			if(temp.length() > 0)
			words.push_back(temp);
		}
        if(words.size()==1)
        {
            string s ="";
            s.append(words[0]);

            while(space_count > 0)
            {
                s.push_back(' ');
                space_count--;
            }
            return s;

        }
        cout<<"space_count = "<<space_count<<endl;

        if(space_count == 0) return str;

		int used_space = space_count / (words.size()-1);
		int extra_space = space_count % (words.size()-1);
		
		string ans = "";
		for(int i=0;i<words.size();i++)
		{
			ans.append(words[i]);
			
			if(i == words.size()-1) break;
			
			int temp = used_space;
			while(temp > 0)
			{
			    ans.push_back(' ');
				temp--;	
			}
		}
		while(extra_space > 0)
		{
			ans.push_back(' ');
			extra_space--;
		}
		return ans;
    }
};