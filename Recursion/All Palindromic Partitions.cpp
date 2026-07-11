class Solution {
  public:
    
    bool isPalindrome(string &s,int start,int end)
    {
        while(start<end)
        {
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    void solve(string &s,vector<string>&temp,vector<vector<string>>&ans,int index)
    {
        int n=s.size();
        if(index==n) {
            if(!temp.empty())
            ans.push_back(temp);
            return;
        }
        
        for(int i=index;i<n;i++)
        {
            if(isPalindrome(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                solve(s,temp,ans,i+1);
                temp.pop_back();
            }
            
        }
    }
    vector<vector<string>> palinParts(string &s) 
    {
        // code here
        vector<string>temp;
        vector<vector<string>>result;
        solve(s,temp,result,0);
        return result;
    }
};