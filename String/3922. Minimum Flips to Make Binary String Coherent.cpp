class Solution {
public:
    int minFlips(string s) 
    {
        int n=s.size(),ones=0;
        if(n<3) return 0;
        bool firstPlace=false,lastPlace=false;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='1') ones++;
            if(i==0 && s[i]=='1')   firstPlace=true;
            if(i==n-1 && s[i]=='1') lastPlace=true;
        }
        int exactAtLast=ones;
        if(firstPlace) exactAtLast--;
        if(lastPlace)  exactAtLast--;
        return min({ones,n-ones,abs(ones-1),exactAtLast});
    }
};