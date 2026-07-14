class Solution {
public:
    void fillColor(vector<vector<int>>&image,vector<vector<int>>&visited,int row,int col,int orgColor,int color)
    {
        int m=image.size(),n=image[0].size();
        image[row][col]=color;
        visited[row][col]=1;
        if(row+1<m && visited[row+1][col]==0 && image[row+1][col]==orgColor)     
            fillColor(image,visited,row+1,col,orgColor,color);
        if(row-1>=0 && visited[row-1][col]==0 && image[row-1][col]==orgColor)
            fillColor(image,visited,row-1,col,orgColor,color);
        if(col+1<n && visited[row][col+1]==0 && image[row][col+1]==orgColor)
            fillColor(image,visited,row,col+1,orgColor,color);
        if(col-1>=0 && visited[row][col-1]==0 && image[row][col-1]==orgColor) 
            fillColor(image,visited,row,col-1,orgColor,color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int m=image.size(),n=image[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int orgColor=image[sr][sc];
        fillColor(image,visited,sr,sc,orgColor,color);
        return image;
    }
};