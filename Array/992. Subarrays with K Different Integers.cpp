class Solution {
public:
    int atMostKDistinct(vector<int>& nums, int k) 
    {
        int left=0,n=nums.size(),count=0;
        unordered_map<int,int>mpp;
        int distinctNum=0;
        for(int right=0;right<n;right++)
        {
            if(mpp[nums[right]]==0)  distinctNum++;
            mpp[nums[right]]++;
            while(  distinctNum>k)
            {
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0) distinctNum--;
                left++;
            }

            count+=(right-left+1);
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return atMostKDistinct(nums,k)-atMostKDistinct(nums,k-1);
    }
};


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int atMostKDistinct(vector<int>&nums,int k)
{
    int n=nums.size();
    int left=0,distinct=0;

    int count=0;
    unordered_map<int,int>mpp;
    for(int right=0;right<n;right++)
    {
        if(mpp[nums[right]]==0) {
            distinct++;
            cout<<"At right index "<<right<<" distinct is "<<distinct<<endl;
        }
        mpp[nums[right]]++;
        while(distinct>k)
        {
            cout<<"Entered into while loop "<<endl;
            mpp[nums[left]]--; 
            if(mpp[nums[left]]==0) distinct--;
            left++;
            cout<<"Left becomes "<<left<<endl;
        }

        cout<<right-left+1<<" being added in the count "<<endl;
        count+=(right-left+1);
        cout<<"Total Count "<<count<<endl;
    }
    return count;
}

int subarraysWithKDistinct(vector<int>& nums, int k) 
{
    return atMostKDistinct(nums,k)-atMostKDistinct(nums,k-1);
}

int main()
{
    vector<int>nums={1,2,1,2,3};
    int k=2;
    // cout<<atMostKDistinct(nums,k)<<endl;
    atMostKDistinct(nums,k-1) ;
    return 0;
}