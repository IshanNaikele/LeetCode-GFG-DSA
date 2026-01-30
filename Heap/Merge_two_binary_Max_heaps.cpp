// User function Template for C++

class Solution 
{
  public:
    void heapify(vector<int>&ans,int index,int size)
    {
        while(true)
        {
            int largest=index;
            int left=index*2+1;
            int right=index*2+2;
            if(left<size && ans[largest]<ans[left])
            largest=left;
            if(right<size && ans[largest]<ans[right])
            largest=right;
            
            if(largest==index) break;
            swap(ans[largest],ans[index]);
            index=largest;
        }
    }
     
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) 
    {
        
        // your code here
        vector<int>ans;
        for(int x:a)   ans.push_back(x);
        for(int x:b)   ans.push_back(x);
        int size=ans.size();
        for(int i=(size/2)-1;i>=0;i--)     heapify(ans,i,size);
        
        return ans;
    }
};