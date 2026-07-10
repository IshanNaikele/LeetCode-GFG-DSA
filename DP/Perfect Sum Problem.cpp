//Recursion 
class Solution {
  public:
    int solve(vector<int>&arr,int target,int index )
    {  
        if(index==arr.size())  return (target == 0) ? 1 : 0;
        
        int exclude= solve(arr,target,index+1 );
        
        int include = 0;
        if(target>=arr[index])
        include=solve(arr,target-arr[index],index+1);
        
        return include+exclude;
    }
    
    int perfectSum(vector<int>& arr, int target)
    {
        // code here
        return solve(arr,target,0);
    }
};

//Memoization 
class Solution {
  public:
    int solve(vector<int>&arr,int target,int index ,vector<vector<int>>&dp)
    {  
        if(index==arr.size())  return (target == 0) ? 1 : 0;
        if(dp[index][target]!=-1) return dp[index][target];
        int exclude= solve(arr,target,index+1,dp);
        
        int include = 0;
        if(target>=arr[index])
        include=solve(arr,target-arr[index],index+1,dp);
        
        return dp[index][target]=include+exclude;
    }
    
    int perfectSum(vector<int>& arr, int target)
    {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(arr,target,0,dp);
    }
};

//Tabulation 
class Solution {
  public:
     
    int perfectSum(vector<int>& arr, int target)
    {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        
        for(int index=0;index<n;index++)
        dp[index][0]=1;
        
        if(arr[n-1] <= target)
        dp[n-1][arr[n-1]] += 1; 
        
        for(int index=n-2;index>=0;index--)
        {
            for(int tar=0;tar<=target;tar++)
            {
                int exclude=dp[index+1][tar];
        
                int include = 0;
                if(tar>=arr[index])
                include=dp[index+1][tar-arr[index]]; 
                
                dp[index][tar]=include+exclude;
            }
        }
         
        return dp[0][target];
    }
};

//Space Optimized
class Solution {
  public:
     
    int perfectSum(vector<int>& arr, int target)
    {
        // code here
        int n=arr.size();
        vector<int>prev(target+1,0);
        
        prev[0]=1;
        
        if(arr[n-1] <= target)
        prev[arr[n-1]] += 1; 
        
        for(int index=n-2;index>=0;index--)
        {
            vector<int>curr(target+1,0);
            curr[0]=1;
            for(int tar=0;tar<=target;tar++)
            {
                int exclude=prev[tar];
        
                int include = 0;
                if(tar>=arr[index])
                include=prev[tar-arr[index]]; 
                
                curr[tar]=include+exclude;
            }
            prev=curr;
        }
         
        return prev[target];
    }
};
