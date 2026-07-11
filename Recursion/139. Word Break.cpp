class Solution {
public:
    bool inDict(string &s,vector<string>& wordDict)
    {
        for(string str:wordDict)
            if(str==s) return true;
        
        return false;
    }
    void solve(string &s,vector<string>& wordDict,int index,bool &flag)
    {
        int n=s.size();
        if(flag) return;
        if(index==n)
        {
            flag=true;
            return;
        }
        for(int i=index;i<n;i++)
        {
            string temp=s.substr(index,i-index+1);
            if(inDict(temp,wordDict))
                solve(s,wordDict,i+1,flag);
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        bool flag=false;
        solve(s,wordDict,0,flag);
        return flag;
    }
};