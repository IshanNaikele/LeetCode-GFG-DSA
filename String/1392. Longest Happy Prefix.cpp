class Solution 
{
public:
    int longestPrefixSuffix(string s)
    {
        int prefix=0,suffix=1,n=s.size();
        vector<int>lps(n,0);
        while(suffix<n)
        {
            if(s[prefix]==s[suffix])
            {
                lps[suffix]=prefix+1;
                suffix++;
                prefix++;
            }
            else
            {
                if(prefix==0) suffix++;
                else          prefix=lps[prefix-1];
            }
        }
        return lps[n-1];
    }

    string longestPrefix(string s) 
    {
        int index=longestPrefixSuffix(s);
        if(index==0) return "";
        return s.substr(0,index);
    }
};