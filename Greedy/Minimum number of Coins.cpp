class Solution {
  public:
    int findMin(int n) 
    {
        // code here
        vector<int>coins={10,5,2,1};
        int count=0;
        for(int i=0;i<4 ;i++)
        {
            int num=n;
            int inc=num/coins[i];
            count+=inc;
            n-=(inc*coins[i]);
        }
        
        return count;
    }
};