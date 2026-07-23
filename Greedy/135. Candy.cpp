//Brute Force 
class Solution {
public:
    int candy(vector<int>& ratings)
    {
        int n=ratings.size(),prevCandies=1,totalCandies=0;
        vector<int>leftCandies(n,1),rightCandies(n,1);
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
                leftCandies[i]=leftCandies[i-1]+1;
        }
       
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
                rightCandies[i]=rightCandies[i+1]+1;
        }


        for(int i=0;i<n;i++)
            totalCandies+=max(leftCandies[i],rightCandies[i]);
       
        return totalCandies;
    }
};
