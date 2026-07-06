class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int n=s.size(),left=0;
        int count=0;
        vector<int>freq(3,0);
        int charReqd=3;
        for(int right=0;right<n;right++)
        {
            int index=s[right]-'a';
            if(freq[index]==0)
               charReqd--;
            
            freq[index]++;

            while(charReqd==0)
            {
                count+=(n-right);
                int i=s[left]-'a';
                freq[i]--;
                if(freq[i]==0) charReqd++;
                left++;
            }
        }
        return count;
    }
};