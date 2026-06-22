class Solution {
public:
    int myAtoi(string s) 
    {
        long long ans=0,n=s.size(),i=0,sign=1;
        while(i<n && s[i]==' ')  i++;
         
        if(s[i]=='-' || s[i]=='+') 
        {
            if(s[i]=='-') sign=-1;
            i++;
        }

        while(i<n && isdigit(s[i]))
        {
            int num=s[i]-'0';

            if(ans>INT_MAX/10 ||(ans==INT_MAX/10) && num>7 ) 
            return sign==1?INT_MAX:INT_MIN;
            ans=ans*10+num;
            i++;
        }

         
        return  ans*sign;
    }
};