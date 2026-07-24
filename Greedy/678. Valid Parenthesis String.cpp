//Recursion 
class Solution
{
public:
    bool solve(string &s,int index,int count)
    {
        int n=s.size();
        if(index==n) return count==0;
        if(count<0) return false;
        if(s[index]=='(') return solve(s,index+1,count+1);
        if(s[index]==')') return solve(s,index+1,count-1);


        return solve(s,index+1,count+1) || solve(s,index+1,count-1) || solve(s,index+1,count);
    }
    bool checkValidString(string s)
    {
        return solve(s,0,0);
    }
};

//Memoization 
class Solution
{
public:
    bool solve(string &s,int index,int count,vector<vector<int>>&dp)
    {
        int n=s.size();
        if(index==n) return count==0;
        if(count<0) return false;
        if(dp[index][count]!=-1) return dp[index][count];
        if(s[index]=='(') return solve(s,index+1,count+1,dp);
        if(s[index]==')') return solve(s,index+1,count-1,dp);


        return dp[index][count]=solve(s,index+1,count+1,dp) || solve(s,index+1,count-1,dp) || solve(s,index+1,count,dp);
    }
    bool checkValidString(string s)
    {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(100,-1));
        return solve(s,0,0,dp);
    }
};

//Greedy 
class Solution
{
public:
     
    bool checkValidString(string s)
    {
        int n=s.size(),minChar=0,maxChar=0;
        for(int i=0;i<n;i++)
        {
             
            if(s[i]=='(')
            {
                minChar+=1;
                maxChar+=1;
            }
            else if(s[i]==')')
            {
                minChar-=1;
                maxChar-=1;
            }
            else
            {
                minChar--;
                maxChar+=1;
            }
            if(minChar<0) minChar=0;
            if(maxChar<0) return false;
        }
        return  minChar==0 ;
    }
};
