//Approach 1 :
class Solution {
  public:
    
    int kthSmallest(vector<vector<int>> &mat, int k) 
    {
        // code here
        vector<pair<int,pair<int,int>>>v;
        for(int i=0;i<mat.size();i++)
        v.push_back(make_pair(mat[i][0],make_pair(i,0)));
        
        priority_queue<
                       pair<int,pair<int,int>>,
                       vector<pair<int,pair<int,int>>>,
                       greater<pair<int,pair<int,int>>>
                       >pq(v.begin(),v.end());
        
        int ans,i,j;   
        pair<int,pair<int,int>>element;
        while(k--)
        {
            element=pq.top();
            ans=element.first;
            i=element.second.first;
            j=element.second.second;
            pq.pop();
            if(j+1<mat.size())
            pq.push(make_pair(mat[i][j+1],make_pair(i,j+1)));
        }
        return ans;        
    }
};


//Approach 2 :

class Solution {
  public:
    
    int kthSmallest(vector<vector<int>> &mat, int k) 
    {
        // code here
        int n=mat.size(),count=0;
        int start=mat[0][0],end=mat[n-1][n-1];
        
        while(start<end)
        {
            int mid=start+(end-start)/2;
            int count=0;
            int row=n-1,col=0;
            while(row>=0 && col<n)
            {
                if(mat[row][col]<=mid)
                {
                    col++;
                    count += row + 1;
                }
                else
                row--;
            }
            
            if(count<k) start=mid+1;
            else        end=mid;
        }
        
        return start;
    }
};
