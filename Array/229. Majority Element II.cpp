class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int first=INT_MIN,second=INT_MIN,count1=0,count2=0,n=nums.size();

        for(int num:nums)
        {
            if(first==num) count1++;
            else if(second==num) count2++;
            else if(count1==0 && second!=num)
            {
                count1=1;
                first=num;
            }
            else if(count2==0 && first!=num)
            {
                count2=1;
                second=num;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1=0,count2=0;
        for(int num:nums)
        {
            if(num==first) count1++;
            if(num==second)count2++;
        }
        
        vector<int>ans;
        if(count1>n/3)  ans.push_back(first);
        if(count2>n/3)  ans.push_back(second);
        return ans;
    }
};