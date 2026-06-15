class Solution {
  public:
    
    void reverseCol(vector<vector<int>>&mat)
    {
        int n=mat.size();
        
        for(int i=0;i<n;i++)
        {
            int start=0,end=n-1;
            while(start<end)
               swap(mat[start++][i],mat[end--][i]);
        }
    }
    
    void reverseRow(vector<vector<int>>&mat)
    {
        int n=mat.size();
        
        for(int i=0;i<n;i++)
        {
            int start=0,end=n-1;
            while(start<end)
               swap(mat[i][start++],mat[i][end--]);
        }
    }
    
    void rotateMatrix(vector<vector<int>>& mat) 
    {
        reverseCol(mat);
        reverseRow(mat);
    }
};