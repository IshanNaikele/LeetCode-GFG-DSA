//Recursion 
class Solution {
public:
    int solve(string &s,string &t,int index1,int index2)
    {
        int n=s.size();
        int m=t.size();
        if(index2==m) return 1;
        if(index1==n) return 0;
        int matched=0;
        int unmatched=0;
        if(s[index1]==t[index2])
        matched=solve(s,t,index1+1,index2+1)+solve(s,t,index1+1,index2);
        else
        unmatched=solve(s,t,index1+1,index2);


        return matched+unmatched;
    }
    int numDistinct(string s, string t)
    {
        return solve(s,t,0,0);
    }
};
//Memoization 
class Solution {
public:
    int solve(string &s,string &t,int index1,int index2,vector<vector<int>>&dp)
    {
        int n=s.size();
        int m=t.size();
        if(index2==m) return 1;
        if(index1==n) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        int matched=0;
        int unmatched=0;
        if(s[index1]==t[index2])
        matched=solve(s,t,index1+1,index2+1,dp)+solve(s,t,index1+1,index2,dp);
        else
        unmatched=solve(s,t,index1+1,index2,dp);


        return dp[index1][index2]=matched+unmatched;
    }
    int numDistinct(string s, string t)
    {
        int n=s.size(),m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(s,t,0,0,dp);
    }
};




//Tabulation 
class Solution {
public:
    
    int numDistinct(string s, string t)
    {
        int n=s.size(),m=t.size();
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));


        for(int index1=0;index1<=n;index1++) dp[index1][m]=1;
       
        for(int index1=n-1;index1>=0;index1--)
        {
            for(int index2=m-1;index2>=0;index2--)
            {
                int matched=0;
                int unmatched=0;
                if(s[index1]==t[index2])
                matched=dp[index1+1][index2+1]+dp[index1+1][index2];
                else
                unmatched=dp[index1+1][index2];


                dp[index1][index2]=matched+unmatched;
            }
        }
        return dp[0][0];
    }
};

//Space Optimized 
class Solution {
public:
   
    int numDistinct(string s, string t)
    {
        int n=s.size(),m=t.size();
        vector<long long>prev(m+1,0);
        prev[m]=1;
       
        for(int index1=n-1;index1>=0;index1--)
        {
            vector<long long>curr(m+1,0);
            curr[m]=1;
            for(int index2=m-1;index2>=0;index2--)
            {
                int matched=0;
                int unmatched=0;
                if(s[index1]==t[index2])
                matched=prev[index2+1]+prev[index2];
                else
                unmatched=prev[index2];


                curr[index2]=matched+unmatched;
            }
            prev=curr;
        }
        return prev[0];
    }
};
