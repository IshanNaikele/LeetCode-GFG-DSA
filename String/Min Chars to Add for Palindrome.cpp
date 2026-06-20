class Solution 
{
  public:
    int longestPrefixSuffix(string &s)
    {
        int n=s.size();
        vector<int>lps(n,0);
        
        int prefix=0,suffix=1;
        
        while(suffix<n)
        {
            if(s[prefix]==s[suffix])
            {
                lps[suffix]=prefix+1;
                prefix++;
                suffix++;
            }
            else
            {
                if(prefix==0) suffix++;
                else          prefix=lps[prefix-1];
            }
        }
        return lps[n-1];
    }
    int minChar(string &s) 
    {
        // code here
        int n=s.size();
        string rev=s;
        reverse(rev.begin(),rev.end());
        s=s+"#"+rev;
        
        return n-longestPrefixSuffix(s);
    }
};
