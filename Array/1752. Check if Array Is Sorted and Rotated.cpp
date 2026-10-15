#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& arr) 
    {
        int count=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if (arr[i]>arr[(i+1)%n]) count+=1;
            if (count>1 )  return false;
        }
        return true ;
    }
};

// class Solution:
//     def check(self, nums: list[int]) -> bool:
//         count=0
//         n=len(nums)

//         for i in range(0,n):
//             if nums[i] > nums[(i+1)%n] :
//                 count+=1 
//             if count >1 :
//                 return False 

//         return True 
        

int main(){

    return 0;
}