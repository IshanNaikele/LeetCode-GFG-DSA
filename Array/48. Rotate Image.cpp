class Solution {
public:
    void traverseMatrix(vector<vector<int>>&mat)
    {
        int row=mat.size();
        for(int i=0;i<row;i++)
        {
            for(int j=i+1;j<row;j++)
                swap(mat[i][j],mat[j][i]);
        }
    }

    void reverseRow(vector<vector<int>>&mat)
    {
        int row=mat.size();
        for(int i=0;i<row;i++)
        {
            int start=0,end=row-1;
            while(start<end)
               swap(mat[i][start++],mat[i][end--]);
        }
    }
    void rotate(vector<vector<int>>& matrix) 
    {
        traverseMatrix(matrix);
        reverseRow(matrix);
    }
};