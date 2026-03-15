class Solution {
public:
    int fib(int n) 
    { 
        if(n<=0) return 0;
        if(n==1) return 1;

        return fib(n-1)+fib(n-2);
    }
};

class Solution {
public:
    int fib(int n) 
    {
        int num1=0,num2=1;
        if(n==0) return num1;
        if(n==1) return num2;
        
        n-=1;
        int ans=0;
        while(n--)
        {
            ans=num1+num2;
            num1=num2;
            num2=ans;
        }
        return ans;
    }
};
