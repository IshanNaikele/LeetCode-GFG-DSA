//Recursion 
class Solution {
  public:
    void solve(vector<int>&arr,int target,int index,bool &flag)
    {
        int n=arr.size();
        if(flag) return;
        if(target==0) 
        {
            flag=true;
            return;
        }
        if(index==n || target<0) return;
         
        solve(arr,target,index+1,flag);
        solve(arr,target-arr[index],index+1,flag);
    }
    bool isSubsetSum(vector<int>& arr, int sum) 
    {
        // code here
        bool flag=false;
        solve(arr,sum,0,flag);
        return flag;
    }
};

//Memoization 
 class Solution {
  public:
    bool solve(vector<int>&arr,int target,int index,vector<vector<int>>&dp)
    {
        int n=arr.size();
         
        if(target==0) 
           return 1;
        if(index==n) return 0;
        if(dp[index][target]!=-1) return dp[index][target];
         
         
        bool notTake=solve(arr,target,index+1,dp);
        bool take=false;
        if(target-arr[index]>=0)
        take=solve(arr,target-arr[index],index+1,dp);
        
        return dp[index][target]=take || notTake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) 
    {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,sum,0,dp);
    }
};


//Tabulation  
class Solution {
  public:
 
    bool isSubsetSum(vector<int>& arr, int sum) 
    {
        // code here
        int n=arr.size();
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        
        dp[n-1][arr[n-1]]=true;
        for(int i=0;i<n;i++)
        dp[i][0]=true;
        
        for(int index=n-2;index>=0;index--)
        {
            for(int target=1;target<=sum;target++)
            {
                bool notTake=dp[index+1][target];
                bool take=false;
                if(target-arr[index]>=0)
                take=dp[index+1][target-arr[index]]; 
                
                dp[index][target]=take || notTake ;
            }
        }
        return dp[0][sum];
    }
};


//Space Optimization 
class Solution {
  public:
 
    bool isSubsetSum(vector<int>& arr, int sum) 
    {
        // code here
        int n=arr.size();
        vector<bool>prev(sum+1,false);
        
        prev[arr[n-1]]=true;
        prev[0]=true;
        
        for(int index=n-2;index>=0;index--)
        {
            vector<bool>curr(sum+1,false);
            curr[0]=true;
            for(int target=1;target<=sum;target++)
            {
                bool notTake=prev[target];
                bool take=false;
                if(target-arr[index]>=0)
                take=prev[target-arr[index]]; 
                
                curr[target]=take || notTake ;
            }
            prev=curr;
        }
        return prev[sum];
    }
};
