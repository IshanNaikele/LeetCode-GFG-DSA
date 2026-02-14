// Approach 1:
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n=heights.size();
        vector<int>smallerOnRight(n,n);
        vector<int>smallerOnLeft(n,-1);
        stack<int>st;

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                smallerOnRight[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                smallerOnLeft[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        int maxArea=0;
        for(int i=0;i<n;i++)
        {
            maxArea=max(maxArea,heights[i]*(smallerOnRight[i]-smallerOnLeft[i]-1));
        }
        return maxArea;

    }
};


//Approach 2 :
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
};
