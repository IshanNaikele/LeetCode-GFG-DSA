class Solution {
public:
    int LCS(string &s1,string &s2)
    {
        int n=s1.size();
        vector<int>prev(n+1,0);

        for(int index1=1;index1<=n;index1++)
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

    int minInsertions(string s) 
    {
        int n=s.size();
        string rev=s;
        reverse(rev.begin(),rev.end());

        return n-LCS(s,rev);
    }
};