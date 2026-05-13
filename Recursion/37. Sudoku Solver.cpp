class Solution {
public:

    bool check(int num,vector<vector<char>>&board,int row,int col)
    {
        char ch='0'+num;

        for(int i=0;i<9;i++)
        {
            if(ch==board[row][i]) return false;
            if(ch==board[i][col]) return false;
        }
        int i=(row/3)*3,j=(col/3)*3;
        for(int k=i;k<i+3;k++)
        {
            for(int l=j;l<j+3;l++)
            {
                if(board[k][l]==ch) return false;
            }
        }
        return true;
    }
    bool find(int row,int col,vector<vector<char>>& board)
    {
        if(row==9) return 1;
        if(col==9) return find(row+1,0,board);

        if(board[row][col]!='.') return find(row,col+1,board);

        for(int num=1;num<10;num++)
        {
            if(check(num,board,row,col))
            {
                char ch='0'+num;
                board[row][col]=ch;
                if(find(row,col+1,board)) return 1;
                board[row][col]='.';
            }
        }

        return 0;
    }

    void solveSudoku(vector<vector<char>>& board) 
    {
        find(0,0,board);
    }
};