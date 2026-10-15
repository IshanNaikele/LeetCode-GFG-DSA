#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int thirdSmallest(vector<int>&nums){
    int first=INT_MAX,second=INT_MAX,third=INT_MAX;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if (nums[i] < first ){
            third=second;
            second=first;
            first=nums[i];
        }
        else if (first < nums[i] && second > nums[i] ){
            third=second;
            second=nums[i];
        }
        else if(nums[i] < third && second < nums[i] ){
            third=nums[i];
        }
    }

    if (third==INT_MAX) return -1;
    return third;
}

// def thirdSmallest(nums):
//   first=float('inf')
//   second=float('inf')
//   third=float('inf')

//   n=len(nums)

//   for i in range(0,n):
//     if nums[i] < first :
//       third=second
//       second=first
//       first=nums[i] 
//     elif nums[i] > first and second > nums[i] :
//       third=second
//       second=nums[i] 
//     elif second < nums[i] and third > nums[i] :
//       third=nums[i]

//   return third 

// nums=[1,2,4,5,7,8,3,2,1,0]
// print(thirdSmallest(nums))
      
int main(){
    vector<int>nums={5,3,6,4,5,2,1,7,9,4};
    cout<<thirdSmallest(nums);
    return 0;
}
