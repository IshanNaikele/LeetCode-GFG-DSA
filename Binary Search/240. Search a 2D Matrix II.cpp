class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row=matrix.size()-1,column=matrix[0].size(),col=0;
        
        while(row>=0 && col<column)
        {
            if(matrix[row][col]==target)       return true; 
            else if(matrix[row][col]>target)   row--;
            else                               col++;
        }
        return false;
    }
};