class Solution 
{
public:
    int LCS(string &s1,string &s2)
    {
        int m=s1.size();
        int n=s2.size();
        vector<int>prev(n+1,0);

        for(int index1=1;index1<=m;index1++)
        {
            vector<int>curr(n+1,0);
            for(int index2=1;index2<=n;index2++)
            {
                if(s1[index1-1]==s2[index2-1])
                  curr[index2]=1+prev[index2-1];
                else
                  curr[index2]=max(curr[index2-1],prev[index2]);
            }
            prev=curr;
        }
        return prev[n];
    }

    int minDistance(string word1, string word2) 
    {
        int m=word1.size(),n=word2.size();
        int common=LCS(word1,word2);
        return (m-common)+(n-common);
    }
};