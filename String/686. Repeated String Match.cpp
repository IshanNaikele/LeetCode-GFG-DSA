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
    
    bool search(string &pat, string &txt) 
    {
        // code here
        vector<int>ans;
        int m=txt.size(),n=pat.size();
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

            if(suffix==n) return true;
        }
        return false;

    }
    int repeatedStringMatch(string a, string b) 
    {
        int m=a.size(),n=b.size();
        int repeat=1;
        string temp=a;
        while(temp.size()<n)
        {
            temp+=a;
            repeat++;
        }
        
        if(search(b,temp)) return repeat;
        temp+=a;
        repeat++;
        if(search(b,temp)) return repeat;

        return -1;
    }
};