//Approach 1: O(n*n)

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) 
    {
        // code here
        int n=mat.size();
        vector<int>index;
        for(int i=0;i<n;i++)
        {
            bool found=false;
            for(int j=0;j<n;j++)
            {
                if(i!=j && mat[i][j]==1)
                {
                    found=true;
                    break;
                }
            }
            if(!found) index.push_back(i);
        }
        
        if(index.size()>1) return -1;
        if(index.empty()) return -1;
        int ind=index.back();
        for(int i=0;i<n;i++)
        {
            if(mat[i][ind]==0) return -1;
        }
        return ind;
    }
};

//Approach 2 :
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) 
    {
        // code here
        int n=mat.size();
        stack<int>st;
        for(int i=0;i<n;i++)       st.push(i);
        
        while(st.size()>1) 
        {
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            
            if(mat[first][second]==1) 
            st.push(second);
            else
            st.push(first);
        }
        
        if(st.empty()) return -1;
        int top=st.top();
        int row=0,col=0;
        for(int i=0;i<n;i++)
        {
            row+=mat[top][i];
            col+=mat[i][top];
        }
        
        if(row==1 && col==n)  return top;
        return -1;
    }
};   