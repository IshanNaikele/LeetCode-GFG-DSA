class Solution {
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
    int strStr(string haystack, string needle) 
    {
        int m=haystack.size(),n=needle.size();
        if(n>m) return -1;
        int prefix=0,suffix=0;
        vector<int>lps=longestPrefixSuffix(needle);
        while(prefix<m && suffix<n)
        {
            if(haystack[prefix]==needle[suffix])
            {
                prefix++;
                suffix++;
            }
            else
            {
                if(suffix==0) prefix++;
                else          suffix=lps[suffix-1];
            }

            if(suffix==n) return prefix-suffix;
        }
        return -1;
    }
};