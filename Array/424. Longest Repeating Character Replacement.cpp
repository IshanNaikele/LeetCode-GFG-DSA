//Approach 1 :(Easy to Understand)
class Solution {
public:
    int characterReplacement(string s, int k)
    {
        vector<int>freq(26,0);
        int n=s.size(),left=0;
       
        int maxWindow=0;
        int maxFreq=0;
        for(int right=0;right<n;right++)
        {
            int index=s[right]-'A';
            freq[index]++;
           
            maxFreq=max(maxFreq,freq[index]);
            int windowLength=right-left+1;
            while(windowLength-maxFreq>k)
            {
                int i=s[left]-'A';
                freq[i]--;
                left++;
                maxFreq=0;
                for(int j=0;j<26;j++) maxFreq=max(maxFreq,freq[j]);
                windowLength=right-left+1;
            }
            maxWindow=max(maxWindow,(right-left+1));
        }
        return maxWindow;
    }
};
//Approach 2 :Optimal 
class Solution {
public:
    int characterReplacement(string s, int k)
    {
        vector<int>freq(26,0);
        int n=s.size(),left=0;
       
        int maxWindow=0;
        int maxFreq=0;
        for(int right=0;right<n;right++)
        {
            int index=s[right]-'A';
            freq[index]++;
           
            maxFreq=max(maxFreq,freq[index]);
            int windowLength=right-left+1;
            if(windowLength-maxFreq>k)
            {
                int i=s[left]-'A';
                freq[i]--;
                left++;
                maxFreq--;
            }
            maxWindow=max(maxWindow,(right-left+1));
        }
        return maxWindow;
    }
};
