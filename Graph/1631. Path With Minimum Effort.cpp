class Solution {
public:
    int solve(vector<vector<int>>&grid)
    {
        int m=grid.size(),n=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();

            int effort = p.first;
            int row = p.second.first;
            int col = p.second.second;

            if(effort > dist[row][col])
                continue;

            if(row == m-1 && col == n-1)
                return effort;

            for(int i=0;i<4;i++)
            {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n)
                {
                    int edgeDiff = abs(grid[row][col] - grid[nr][nc]);

                    int newEffort = max(effort, edgeDiff);

                    if(newEffort < dist[nr][nc])
                    {
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }

        }
        return 0;
    }

    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        return solve(heights);
    }
};