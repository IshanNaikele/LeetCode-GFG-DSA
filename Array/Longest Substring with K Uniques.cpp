class Solution {
  public:
    int longestKSubstr(string &s, int k) 
    {
        // code here
        int n=s.size(),left=0,distinctChars=0;
        int maxLen=-1;
        vector<int>freq(26,0);
        for(int right=0;right<n;right++)
        {
            int index=s[right]-'a';
            if(freq[index]==0) distinctChars++;
            freq[index]++;
            
            while(distinctChars>k)
            {
                int i=s[left]-'a';
                freq[i]--;
                if(freq[i]==0) distinctChars--;
                left++;
            }
            
            if(distinctChars==k)
               maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};