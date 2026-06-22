class Solution {
public:
     
    string reverseWords(string s) 
    {
        int index=0,n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]!=' ')
            {
                if (index != 0) s[index++] = ' ';
                while(i<n && s[i]!=' ')
                {
                    s[index++]=s[i++];
                }
            }
        }
        
       s.resize(index);
       reverse(s.begin(),s.end());
       int start=0;

        for(int i=0;i<=s.length();i++)
        {
                if(i==s.length() || s[i]==' ')
                {
                    reverse(s.begin()+start,s.begin()+i);
                    start=i+1;
                }
        }

        return s;
    }
};