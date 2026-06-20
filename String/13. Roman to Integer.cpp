class Solution {
public:
    int romanToInt(string s) 
    {
        int n=s.size();
        vector<char>symbol={'I','V','X','L','C','D','M'};
        vector<int>value={1,5,10,50,100,500,1000};
        unordered_map<int,int>mpp;

        for(int i=0;i<symbol.size();i++)
            mpp[symbol[i]]=value[i];
        
        int num=mpp[s[0]];
        for(int i=1;i<n;i++)
        {
            char prevCh=s[i-1];
            int prevVal=mpp[prevCh];
            int val=mpp[s[i]];
            
            if(prevVal<val) num+=(val-prevVal-prevVal);
            else            num+=val;
        }
        return num;
    }
};