class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) 
    {
        // Code here
        vector<pair<int,pair<int,int>>>v;
        for(int i=0;i<mat.size();i++)
        v.push_back(make_pair(mat[i][0],make_pair(i,0)));
        priority_queue<
                       pair<int,pair<int,int>>,
                       vector<pair<int,pair<int,int>>>,
                       greater<pair<int,pair<int,int>>>
                      >pq(v.begin(),v.end());
        
        pair<int,pair<int,int>>element;  
        vector<int>ans;
        int i,j;
        while(!pq.empty())
        {
            element=pq.top();
            ans.push_back(element.first);
            pq.pop();  
            i=element.second.first;
            j=element.second.second;
            if(j+1<mat[0].size())
            pq.push(make_pair(mat[i][j+1],make_pair(i,j+1)));
        }
        return ans;
    }
};