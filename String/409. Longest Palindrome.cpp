class Solution {
public:
    int longestPalindrome(string s) 
    {
        vector<int>smallAlpha(26,0),bigAlpha(26,0);
        for(char ch:s)
        {
            if(ch>='A' && ch<='Z') bigAlpha[ch-'A']++;
            else                   smallAlpha[ch-'a']++;
        }

        bool oddFound=false;
        int count=0;
        for(int i=0;i<26;i++)
        {
            if(bigAlpha[i]%2==0) count+=bigAlpha[i];
            else                 
            {
                oddFound=true;
                count=count+(bigAlpha[i]-1);
            }

            if(smallAlpha[i]%2==0) count+=smallAlpha[i];
            else                 
            {
                oddFound=true;
                count=count+(smallAlpha[i]-1);
            }
        }
        if(oddFound) count+=1;
        return count;
    }
};