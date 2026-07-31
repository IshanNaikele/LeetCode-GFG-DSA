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

//Another Approach 

class Solution {
public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++)
        {
            while(!st.empty())
            {
                if(arr[i]<=arr[st.top()]) st.pop();
                else {
                    ans[i]=st.top();
                    break;
                }
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> nextSmaller(vector<int> &arr)
    {
        int n=arr.size();
        vector<int>ans(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty())
            {
                if(arr[i]<=arr[st.top()])
                st.pop();
                else
                {
                    ans[i]=st.top();
                    break;
                }
            }
            st.push(i);
        }
        return ans;
    }

    

    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int m=matrix.size(),n=matrix[0].size();
        vector<int>curr(n,0),prev(n,0);

        int maxArea=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0') {
                    curr[j]=0;
                }else  {
                    curr[j]+=(matrix[i][j]-'0');
                }
            }

            vector<int>smallerOnLeft= prevSmaller(curr);
            vector<int>smallerOnRight=nextSmaller(curr);
            for(int i=0;i<n;i++)
            {
                int diff=smallerOnRight[i]-smallerOnLeft[i]-1;
                int area=diff*curr[i];
                maxArea=max(maxArea,area);
            }

            
        }
        return maxArea;
    }
};