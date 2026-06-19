class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) 
    {
        // code here
        int n=arr.size();
        int row=0,col=n-1,maxOnesRow=-1;
        while(row<n && col>=0)
        {
            if(arr[row][col]==1)  
            {
                maxOnesRow=row;
                col--;
            }
            else 
             row++;
        }
        return maxOnesRow;
    }
};