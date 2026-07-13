//Recursion 
class Solution {
public:
    int solve(string &word1,string &word2,int index1,int index2)
    {
        if(index1<0) return index2+1;
        if(index2<0) return index1+1;
       
        if(word1[index1]==word2[index2]) return solve(word1,word2,index1-1,index2-1);


        int replace=1+solve(word1,word2,index1-1,index2-1);
        int insertion=1+solve(word1,word2,index1,index2-1);
        int deletion=1+solve(word1,word2,index1-1,index2);


        return min({replace,insertion,deletion});
    }
    int minDistance(string word1, string word2)
    {
        int m=word1.size(),n=word2.size();
        return solve(word1,word2,m-1,n-1);
    }
};

//Memoization 
class Solution {
public:
    int solve(string &word1,string &word2,int index1,int index2,vector<vector<long long>>&dp)
    {
        if(index1<0) return index2+1;
        if(index2<0) return index1+1;
        if(dp[index1][index2]!=INT_MAX) return dp[index1][index2];
        if(word1[index1]==word2[index2]) return solve(word1,word2,index1-1,index2-1,dp);


        int replace=1+solve(word1,word2,index1-1,index2-1,dp);
        int insertion=1+solve(word1,word2,index1,index2-1,dp);
        int deletion=1+solve(word1,word2,index1-1,index2,dp);


        return dp[index1][index2]=min({replace,insertion,deletion});
    }
    int minDistance(string word1, string word2)
    {
        int m=word1.size(),n=word2.size();
        vector<vector<long long>>dp(m+1,vector<long long>(n+1,INT_MAX));
        return solve(word1,word2,m-1,n-1,dp);
    }
};



//Tabulatation 
class Solution {
public:
    
    int minDistance(string word1, string word2)
    {
        int m=word1.size(),n=word2.size();
        vector<vector<long long>>dp(m+1,vector<long long>(n+1,INT_MAX));
       
        for(int index1=0;index1<=m;index1++)  dp[index1][0]=index1;
        for(int index2=0;index2<=n;index2++)  dp[0][index2]=index2;


        for(int index1=1;index1<=m;index1++)
        {
            for(int index2=1;index2<=n;index2++)
            {
                if(word1[index1-1]==word2[index2-1]) dp[index1][index2]=dp[index1-1][index2-1];
                else
                {
                    int replace=1+dp[index1-1][index2-1];
                    int insertion=1+dp[index1][index2-1];
                    int deletion=1+dp[index1-1][index2];


                    dp[index1][index2]=min({replace,insertion,deletion});
                }
            }
        }
        return dp[m][n];
    }
};

//Space Optimized
class Solution {
public:
    
    int minDistance(string word1, string word2)
    {
        int m=word1.size(),n=word2.size();
        vector<long long>prev(n+1,INT_MAX);
   
        for(int index2=0;index2<=n;index2++)  prev[index2]=index2;


        for(int index1=1;index1<=m;index1++)
        {
            vector<long long>curr(n+1,INT_MAX);
            curr[0]=index1;
            for(int index2=1;index2<=n;index2++)
            {
                if(word1[index1-1]==word2[index2-1]) curr[index2]=prev[index2-1];
                else
                {
                    int replace=1+prev[index2-1];
                    int insertion=1+curr[index2-1];
                    int deletion=1+prev[index2];


                    curr[index2]=min({replace,insertion,deletion});
                }
            }
            prev=curr;
        }
        return prev[n];
    }
};
