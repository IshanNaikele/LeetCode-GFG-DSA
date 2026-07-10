//Recursion 
class Solution {
  public:
  
    int findTotalSum(vector<int>&arr)
    {
        int totalSum=0;
        for(int num:arr) totalSum+=num;
        return totalSum;
    }
    
    void solve(vector<int>&arr,int index,int totalSum,int sum,int &minDiff)
    {
        int n=arr.size();
        if(index==n) return;
        int diff=abs(sum-(totalSum-sum));
        minDiff=min(minDiff,diff);
        
        solve(arr,index+1,totalSum,sum,minDiff);
        solve(arr,index+1,totalSum,sum+arr[index],minDiff);
    }
    
    int minDifference(vector<int>& arr) 
    {
        // code here
        int totalSum=findTotalSum(arr);
        int minDiff=INT_MAX;
        solve(arr,0,totalSum,0,minDiff);
        return minDiff;
    }
};


//Memoization 
class Solution {
  public:
  
    int findTotalSum(vector<int>&arr)
    {
        int totalSum=0;
        for(int num:arr) totalSum+=num;
        return totalSum;
    }
    
    int solve(vector<int>&arr,int index,int target,vector<vector<int>>&dp)
    {
        int n=arr.size();
        if(target==0) return 1;
        if(index==n) return 0;
        if(dp[index][target]!=-1) return dp[index][target];
         
        bool notTake=solve(arr,index+1,target,dp);
        bool take=false;
        if(target-arr[index]>=0)
        take=solve(arr,index+1,target-arr[index],dp);
        
        return dp[index][target]=take || notTake;
    }
    
    int minDifference(vector<int>& arr) 
    {
        // code here
        int n=arr.size();
        int totalSum=findTotalSum(arr);
        int target=totalSum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        solve(arr,0,target,dp);
        
        int minDiff=INT_MAX;
        for(int tar=0;tar<=target;tar++)
        {
            if(dp[n-1][tar]==1){
                int sum1=tar;
                int sum2=target-sum1;
                minDiff=min(minDiff,abs(sum1-sum2));
            }
        }
        return minDiff;
    }
};


//Tabulation 
class Solution {
  public:
  
    int findTotalSum(vector<int>&arr)
    {
        int totalSum=0;
        for(int num:arr) totalSum+=num;
        return totalSum;
    }
    
    int minDifference(vector<int>& arr) 
    {
        // code here
        int n=arr.size();
        int totalSum=findTotalSum(arr);
        int sum=totalSum/2;
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        if(sum>=arr[n-1])
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
        
        int minDiff=totalSum;
        for(int tar=0;tar<=sum;tar++)
        {
            if(dp[0][tar]==1)
            {
                int sum1=tar;
                int sum2=totalSum-tar;
                minDiff=min(minDiff,abs(sum2-sum1));
            }
        }
        return minDiff;
    }
};

//Space Optimized 
class Solution {
  public:
  
    int findTotalSum(vector<int>&arr)
    {
        int totalSum=0;
        for(int num:arr) totalSum+=num;
        return totalSum;
    }
    
    int minDifference(vector<int>& arr) 
    {
        // code here
        int n=arr.size();
        int totalSum=findTotalSum(arr);
        int sum=totalSum/2;
        vector<bool>prev(sum+1,false);
        
        if(sum>=arr[n-1])
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
       
        int minDiff=totalSum;
        for(int tar=0;tar<=sum;tar++)
        {
            if(prev[tar]==1)
            {
                int sum1=tar;
                int sum2=totalSum-tar;
                minDiff=min(minDiff,abs(sum2-sum1));
            }
        }
        return minDiff;
    }
};
