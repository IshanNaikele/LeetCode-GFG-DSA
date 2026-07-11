class Solution {
public:
    void solve(vector<vector<char>>& board,vector<vector<bool>>&visited,string word,int row,int col,int index,bool &flag)
    {
        int size=word.size();
        int m=board.size(),n=board[0].size();
        if(flag) return;
        if(index==size)  
        {
            flag=true;
            return;
        }

        if(row==m || col==n || row<0 || col<0) return ;

        if(word[index]==board[row][col]){
            if(index==size-1 )
            {
                flag=true;
                return;
            }
            visited[row][col]=1;
            if(row+1<m && visited[row+1][col]==0){ 
                solve(board,visited,word,row+1,col,index+1,flag); 
            }

            if(row-1>=0 && visited[row-1][col]==0){ 
                solve(board,visited,word,row-1,col,index+1,flag); 
            }

            if(col+1<n && visited[row][col+1]==0){
                solve(board,visited,word,row,col+1,index+1,flag);
            }

            if(col-1>=0 && visited[row][col-1]==0){
                solve(board,visited,word,row,col-1,index+1,flag);
            }
            visited[row][col]=0;
        }
    }

    bool exist(vector<vector<char>>& board, string word) 
    {
        bool flag=false;
        int m=board.size(),n=board[0].size();
         
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0])
                {
                    vector<vector<bool>>visited(m,vector<bool>(n,false));
                    solve(board,visited,word,i,j,0,flag);
                    if(flag) return flag;
                }
            }
        }
        return flag;
    }
};