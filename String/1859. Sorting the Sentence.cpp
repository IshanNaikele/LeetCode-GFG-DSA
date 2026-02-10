// Approach 1 :
class Solution {
public:
    string sortSentence(string s) 
    {
        s+=" ";
        vector<string>store(10);
        string temp="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
            {
                temp+=s[i];
            }
            else
            {
                int index=temp[temp.size()-1]-'0';
                temp.pop_back();
                store[index]=temp;
                temp="";
            }
        }
        string ans="";
        for(int i=1;i<10;i++)
        {
            if(store[i].empty()) break ;
            ans+=store[i]+" ";
        }
        ans.pop_back();
        return ans;
    }
};