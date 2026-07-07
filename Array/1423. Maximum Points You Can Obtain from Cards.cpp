class Solution 
{
public:
    int totalSum(vector<int>& cardPoints)
    {
        int sum=0;
        for(int num:cardPoints) sum+=num;
        return sum;
    }
    int minimumSum(vector<int>& cardPoints,int k)
    {
        int left=0,minSum=INT_MAX;
        int sum=0,n=cardPoints.size();
        for(int right=0;right<n;right++)
        {
            sum+=cardPoints[right];
            while((right-left+1)>k)
            {
                sum-=cardPoints[left];
                left++;
            }
            if(minSum>sum && right-left+1==k)
                minSum=sum;
        }
        return minSum;
    }
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int n=cardPoints.size();
        return totalSum(cardPoints)-minimumSum(cardPoints,n-k);
    }
};