class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n=s.size(),maxLen=0;
        int left=0,right=0;
        unordered_map<char,int>mpp;
        
        while(right<n)
        {
            mpp[s[right]]++;
            while(left<right && mpp[s[right]]>1)
            {
                mpp[s[left]]--;
                left++;
            }
            maxLen=max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};