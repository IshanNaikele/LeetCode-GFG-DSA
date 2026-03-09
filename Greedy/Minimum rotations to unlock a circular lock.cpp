// User function Template for C++

class Solution {
  public:
    int rotationCount(long long R, long long D) 
    {
        // code here
        long long count=0;
        while(R)
        {
            int rem1=R%10;
            int rem2=D%10;
            int minValue=min(abs(rem2-rem1),10-abs(rem2-rem1));
            count+=minValue;
            R/=10;
            D/=10;
        }
        return count;
    }
};