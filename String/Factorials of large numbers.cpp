// User function template for C++

class Solution {
  public:
    vector<int> factorial(int n) 
    {
        // code here
         vector<int>ans(1,1);
        
        while(n>1)
        {
            int size=ans.size(),carry=0,res;
            for(int i=0;i<size;i++)
            {
                res=(ans[i]*n)+carry;
                ans[i]=res%10;
                carry=res/10;
            }
            
            while(carry)
            {
                ans.push_back(carry%10);
                carry=carry/10;
            }
            n--;
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};