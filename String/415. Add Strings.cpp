class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        int carry=0,i=0,j=0,m=num1.size(),n=num2.size();
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string ans="";
        while(i<m || j<n || carry)
        {
            int sum=carry;
            if(i<m) 
            {
                int num=num1[i++]-'0';
                sum+=num;
            }

            if(j<n)
            {
                int num=num2[j++]-'0';
                sum+=num;
            }

            carry=sum/10;
            char ch=(sum%10+'0');
            ans+=ch;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};