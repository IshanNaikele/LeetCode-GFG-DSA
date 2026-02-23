//Approach 1: O(n*n)

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) 
    {
        // code here
        int n=mat.size();
        vector<int>index;
        for(int i=0;i<n;i++)
        {
            bool found=false;
            for(int j=0;j<n;j++)
            {
                if(i!=j && mat[i][j]==1)
                {
                    found=true;
                    break;
                }
            }
            if(!found) index.push_back(i);
        }
        
        if(index.size()>1) return -1;
        if(index.empty()) return -1;
        int ind=index.back();
        for(int i=0;i<n;i++)
        {
            if(mat[i][ind]==0) return -1;
        }
        return ind;
    }
};