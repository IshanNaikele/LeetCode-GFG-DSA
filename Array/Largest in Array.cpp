#include<iostream>
#include<vector>
using namespace std ;

class Solution {
  public:
    int largest(vector<int> &arr) 
    {
        // code here
        int maxElement=INT_MIN;
        for(int num:arr)
        {
            if(num>maxElement) maxElement=num;
        }
        return maxElement;
    }
};

class Solution:
    def largest(self, arr):
        maxElement=float('-inf')
        n=len(arr)
        
        for i in range(0,n):
            if arr[i]>maxElement :
                maxElement=arr[i]
                
                
        return maxElement
        
int main(){

    return 0;
}