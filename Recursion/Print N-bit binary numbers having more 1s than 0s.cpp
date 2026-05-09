// User function template for C++
class Solution 
{
  public:
    void solve(int n,string s,vector<string>&ans,int ones,int zeros)
    {
        if(n==s.size())
        {
            ans.push_back(s);
            return ;
        }
        solve(n,s+"1",ans,ones+1,zeros);
        if(ones>zeros)
        solve(n,s+"0",ans,ones,zeros+1);
    }
    
    vector<string> NBitBinary(int n) 
    {
        // Your code goes here
        vector<string>ans;
        int ones=0,zeros=0;
        solve(n,"",ans,ones,zeros);
        return ans;
    }
};