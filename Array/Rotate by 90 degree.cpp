class Solution 
{
  public:
  
   void traverseMatrix(vector<vector<int>>&mat)
    {
        int n=mat.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
               swap(mat[i][j],mat[j][i]);
        }
    }

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
    void rotateMatrix(vector<vector<int>>& matrix) 
    {
        traverseMatrix(matrix);
        reverseCol(matrix);
    }
};
