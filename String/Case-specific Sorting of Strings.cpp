class Solution {
  public:
    string caseSort(string& s) 
    {
        // code here
        vector<int>freq(128,0);
        
        for(int i=0;i<s.size();i++)
        freq[s[i]]++;
        
        string small="",big="";
        
        for(int i=0;i<freq.size();i++)
        {
            char ch=char(i);
            
            if(ch>='A' && ch<='Z')
            {
                while(freq[i])
                {
                    big+=ch;
                    freq[i]--;
                }
            }
            
            if(ch>='a' && ch<='z')
            {
                while(freq[i])
                {
                    small+=ch;
                    freq[i]--;
                }
            }
        }
        
        int index1=0,index2=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            s[i]=big[index1++];
            else
            s[i]=small[index2++];
        }
        
        return s;
        
    }
};