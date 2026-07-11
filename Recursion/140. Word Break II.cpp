class Solution {
public:
    bool inDict(string &s,vector<string>& wordDict)
    {
        for(string str:wordDict)
            if(str==s) return true;
        
        return false;
    }
    void solve(string &s,vector<string>&temp,vector<string>&result,vector<string>& wordDict,int index)
    {
        int n=s.size();
        if(index==n)
        {
            string ans="";
            for(int i=0;i<temp.size();i++)
            {
                ans+=temp[i];
                ans+=" ";
            }
            ans.pop_back();
            result.push_back(ans);
            return ;
        }
        for(int i=index;i<n;i++)
        {
            string str=s.substr(index,i-index+1);
            if(inDict(str,wordDict)) 
            {
                temp.push_back(str);
                solve(s,temp,result,wordDict,i+1);
                temp.pop_back();
            }
        }
    }
   
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        vector<string>temp;
        vector<string>result;
        solve(s,temp,result,wordDict,0);
        return result;
    }
};