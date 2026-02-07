class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) 
    {
        sort(arr.begin(),arr.end());
        return arr[k-1];
    }
};

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) 
    {
        priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.end());
        k--;
        while(k--)
        {
            pq.pop();
        }
        
        return pq.top();
    }
};

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) 
    {
        priority_queue<int>pq;
         
        for(int i=0;i<arr.size();i++)
        {
            pq.push(arr[i]);
            if(pq.size()>k)
            pq.pop();
        }
        
        return pq.top();
    }
};