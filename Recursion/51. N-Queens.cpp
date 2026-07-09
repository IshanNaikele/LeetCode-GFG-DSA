class Solution {
public:

    bool check(int n,vector<string>&board,int row,int col)
    {
        int i=row,j=col;
        while(i>=0 && j>=0)
        {
            if(board[i][j]=='Q') return false;
            i--;j--;
        }
        
        i=row,j=col;
        while(i>=0 && j<n)
        {
            if(board[i][j]=='Q') return false;
            i--;j++;
        }

        return true;
    }

    void solve(int row,int n,vector<vector<string>>&ans,vector<string>&board,vector<bool>&column)
    {
        if(row==n )
        {
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++)
        {
            if(column[j]==0 && check(n,board,row,j))
            {
                column[j]=1;
                board[row][j]='Q';
                solve(row+1,n,ans,board,column);
                column[j]=0;
                board[row][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>>ans;
        vector<string>board(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            board[i].push_back('.');
        }

        vector<bool>column(n,0);
        solve(0,n,ans,board,column);

        return ans; 
    }     
};  


//Approach 2 :- 


class Solution 
{
public:

    void find(int row,int n,vector<vector<string>>&ans,vector<string>&board,vector<int>column,vector<bool>&leftDig,vector<bool>&rightDig)
    {
        if(row==n) 
        {
            ans.push_back(board);
            return ;
        }

        for(int col=0;col<n;col++)
        {
            if(column[col]!=1 && leftDig[col-row+n-1]==0 && rightDig[row+col]==0)
            {
                column[col]=1;
                board[row][col]='Q';
                leftDig[col-row+n-1]=1;
                rightDig[row+col]=1;
                find(row+1,n,ans,board,column,leftDig,rightDig);
                column[col]=0;
                board[row][col]='.';
                leftDig[col-row+n-1]=0;
                rightDig[row+col]=0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        vector<int>column(n,0);
        vector<bool>leftDig((n*2)-1,0);
        vector<bool>rightDig((n*2)-1,0);
        find(0,n,ans,board,column,leftDig,rightDig);
        return ans;
    }
};