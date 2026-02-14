class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n=heights.size();
        stack<int>st;
        int area=0,maxArea=0;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[i]<heights[st.top()])
            {
                int value=heights[st.top()];
                int right=i ;
                st.pop();
                if(!st.empty()) area=value*(right-st.top()-1);
                else            area=value*right ;

                maxArea=max(maxArea,area);
            }
            st.push(i);
        }

        while(!st.empty())
        {
            int value=heights[st.top()];
            int right=n;
            st.pop();
                
            if(!st.empty()) area=value*(right-st.top()-1);
            else            area=value*right;

            maxArea=max(maxArea,area);
        }
        return maxArea;
    }


    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int row=matrix.size(),col=matrix[0].size();
        vector<int>storeValue(col,0);
        int ans=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]=='0')
                storeValue[j]=0;
                else
                storeValue[j]+=1;
            }
            ans=max(ans,largestRectangleArea(storeValue));
        }
        return ans;
    }
};