class Solution {
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
    

    string shortestPalindrome(string s) 
    {
        int n=s.size();
        string rev=s;
        reverse(rev.begin(),rev.end());
        string str=s+'$'+rev;
        int index=longestPrefixSuffix(str);
         
        string ans="";
        for(int i=n-1;i>=index;i--)
        ans+=s[i];

        ans+=s;
        return ans;
    }
};