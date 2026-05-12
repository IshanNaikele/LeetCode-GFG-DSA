class Solution {
  public:
  
    void solve(vector<vector<int>>&maze,vector<string>&ans,
               string path,int i,int j,vector<vector<int>>&visited)
   {
       int row=maze.size(),col=maze[0].size();
       // If Destination is reached 
       if(i==row-1 && j==col-1) 
       {
           ans.push_back(path);
           return;
       }
       
       //Mark the path as Visted 
       visited[i][j]=1;
       // For Bottom or Down Path 
       if(i+1<row && maze[i+1][j] && visited[i+1][j]==0)
       {
           path.push_back('D');
           solve(maze,ans,path,i+1,j,visited);
           path.pop_back();
       }
       
       // For Right Path 
       if(i-1>=0 && maze[i-1][j] && visited[i-1][j]==0)
       {
           path.push_back('U');
           solve(maze,ans,path,i-1,j,visited);
           path.pop_back();
       }
       
       // For Left Path
       if(j+1<col && maze[i][j+1] && visited[i][j+1]==0)
       {
           path.push_back('R');
           solve(maze,ans,path,i,j+1,visited);
           path.pop_back();
       }
       
       // For Up Path 
       if(j-1>=0 && maze[i][j-1] && visited[i][j-1]==0)
       {
           path.push_back('L');
           solve(maze,ans,path,i,j-1,visited);
           path.pop_back();
       }
       
       visited[i][j]=0;
   }
    vector<string> ratInMaze(vector<vector<int>>& maze) 
    {
        // code here
        int row=maze.size(),col=maze[0].size();
        if(maze[0][0]==0 || maze[row-1][col-1]==0) return {};
        vector<string>ans;
        vector<vector<int>>visited(row,vector<int>(col,0));
        solve(maze,ans,"",0,0,visited);
        sort(ans.begin(),ans.end());
        return ans;
    }
};