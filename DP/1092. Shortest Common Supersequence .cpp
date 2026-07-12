class Solution 
{
public:
    vector<vector<int>>LCS(string &s1,string &s2)
    {
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        for(int index1=1;index1<=m;index1++)
        {
            for(int index2=1;index2<=n;index2++)
            {
                if(s1[index1-1]==s2[index2-1])
                  dp[index1][index2]=1+dp[index1-1][index2-1];
                else
                  dp[index1][index2]=max(dp[index1][index2-1],dp[index1-1][index2]);
            }
        }
        return dp;
    }

    string shortestCommonSupersequence(string str1, string str2) 
    {
        vector<vector<int>>dp=LCS(str1,str2);
        int i=str1.size(),j=str2.size();
        string ans="";
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                ans+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>=dp[i][j-1])
            {
                ans+=str1[i-1];
                i--;
            }
            else
            {
                ans+=str2[j-1];
                j--;
            }
        }
        while(j>0) {
            ans+=str2[j-1];
            j--;
        }
        while(i>0) {
            ans+=str1[i-1];
            i--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};