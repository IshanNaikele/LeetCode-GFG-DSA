class Solution 
{
  public:
    vector<int>longestPrefixSuffix(string &s)
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
        return lps;
    }
    
    vector<int> search(string &pat, string &txt) 
    {
        // code here
        vector<int>ans;
        int m=txt.size(),n=pat.size();
        if(n>m) return ans;
        int prefix=0,suffix=0;
        vector<int>lps=longestPrefixSuffix(pat);
        while(prefix<m && suffix<n)
        {
            if(txt[prefix]==pat[suffix])
            {
                prefix++;
                suffix++;
            }
            else
            {
                if(suffix==0) prefix++;
                else          suffix=lps[suffix-1];
            }

            if(suffix==n) 
            {
               ans.push_back(prefix-suffix);
               suffix=lps[suffix-1];
            }
        }
        return ans;
    }
};