class Solution {
  public:
    int totalElements(vector<int> &fruits) 
    {
        // code here
        int left=0,n=fruits.size();
        int distinct=0;
        int maxLen=0;
        unordered_map<int,int>freq;
        for(int right=0;right<n;right++)
        {
            int num=fruits[right];
            if(freq[num]==0) distinct++;
            freq[num]++;

            while(distinct>2)
            {
                freq[fruits[left]]--;
                if(freq[fruits[left]]==0) distinct--;
                left++;
            }

            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};