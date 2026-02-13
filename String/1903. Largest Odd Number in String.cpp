class Solution {
public:
    string largestOddNumber(string num) 
    {
        for(int i=num.length()-1;i>=0;i--)
        {
            int number=num[i]-'0';
            if(number%2==1)
            return num;
            else
            num.pop_back();
        }
        return "";
    }
};