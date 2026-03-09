class Solution {
public:
    int M=1e9 + 7 ;
    int t[201][201][2];
    int solve(int onesLeft,int zerosLeft,bool lastWasOne,int limit)
    {
        if(onesLeft==0 && zerosLeft==0) return 1;
        
        if(t[onesLeft][zerosLeft][lastWasOne]!=-1)
        {
            return t[onesLeft][zerosLeft][lastWasOne];
        }
        int result=0;
        if(lastWasOne)
        {
            //Time to explore 0's
            for(int i=1;i<=min(zerosLeft,limit);i++)
            {
                result=(result + solve(onesLeft,zerosLeft-i,false,limit))%M;
            }
        }
        else
        {
            //Time to explore 1's
            for(int i=1;i<=min(onesLeft,limit);i++)
            {
                result=(result + solve(onesLeft-i,zerosLeft,true,limit))%M;
            }
        }
         
        return t[onesLeft][zerosLeft][lastWasOne] = result;
    }
    int numberOfStableArrays(int zero, int one, int limit) 
    {
        memset(t,-1,sizeof(t));
        int startWithOne = solve(one,zero,false,limit);
        int startWithZero =solve(one,zero,true,limit);

        return (startWithOne + startWithZero)%M;
    }
};