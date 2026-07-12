//Recursion 
class Solution {
public:
    bool isPalindrome(string &s )
    {
        int start=0,end=s.size()-1;
        while(start<end)
          if(s[start++]!=s[end--]) return false;


        return true;
    }
    int solve(string &s,string &temp,int index)
    {
        int n=s.size(),maxLen=0;
        if(index==n){
            if(isPalindrome(temp))
                return temp.size();
            return 0;
        }
        int exclude=solve(s,temp,index+1 );
        temp.push_back(s[index]);
        int include=solve(s,temp,index+1);
        temp.pop_back();
       
        return max(include,exclude);
    }
    int longestPalindromeSubseq(string s)
    {
        string temp="";
        vector<vector<int>>dp(s.size());
        return solve(s,temp,0 );
    }
};

//Space Optimized(Using LCS Prb Approach)
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
    int longestPalindromeSubseq(string s)
    {
        string org=s;
        reverse(s.begin(),s.end());
        return LCS(org,s);
    }
};
