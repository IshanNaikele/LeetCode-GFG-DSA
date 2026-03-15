class Solution 
{
public:
    
    int climbStairs(int n) 
    {
        if(n==1) return 1;
        if(n==2) return 2;

        return climbStairs(n-1)+climbStairs(n-2);
    }
};

class Solution 
{
public:

    int climbStairs(int n) 
    {
        if(n<=2) return n;

        int prev2 = 1;
        int prev1 = 2;

        for(int i=3;i<=n;i++)
        {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;

    }
};

class Solution 
{
public:
    int solve(int n)
    {
        if(n == 0) return 1;
        if(n < 0) return 0;

        int oneStep = solve(n-1);
        int twoStep = solve(n-2);

        return oneStep + twoStep;
    }

    int climbStairs(int n) 
    {
        return solve(n);
    }
};

class Solution 
{
public:
     int solve(int n, vector<int>& dp)
    {
        if(n==1) return 1;
        if(n==2) return 2;

        if(dp[n] != -1)
            return dp[n];

        return dp[n] = solve(n-1,dp) + solve(n-2,dp);
    }

    int climbStairs(int n) 
    {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};
