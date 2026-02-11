class Solution {
  public:
    int findSubString(string& s) 
    {
        // code here
        int n=s.size();
        int first=0,second=0,minLen=n;
        
        vector<int>smallAlpha(26,0);
        int diff=0;
        while(first<n)
        {
            if(smallAlpha[s[first]-'a']==0)
            diff++;
            
            smallAlpha[s[first]-'a']++;
            first++;
        }
        
        first=0;
        for(int i=0;i<26;i++)
        smallAlpha[i]=0;
        
        while(second<n)
        {
            while(diff!=0  && second<s.size())
            {
                if(smallAlpha[s[second]-'a']==0)
                diff--;
                
                smallAlpha[s[second]-'a']++;
                second++;
            }
            
            minLen=min(minLen,second-first);
            
            
            while(diff!=1   )
            {
                minLen=min(minLen,second-first);
                
                smallAlpha[s[first]-'a']--;
                
                if(smallAlpha[s[first]-'a']==0)
                diff++;
                
                first++;
            }
            
        }
        
        return minLen;
        
    
    }
};                                         