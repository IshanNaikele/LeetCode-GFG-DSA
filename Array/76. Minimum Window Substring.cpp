class Solution {
public:
    string minWindow(string s, string t) 
    {
        int countChars=t.size();
        int left=0,right=0,n=s.size();
        if(n<countChars) return "";
        vector<int>freq1(256,0);
        for(char ch:t) freq1[ch]++;
        
        vector<int>freq2(256,0);
        int start=-1,end=-1;
        while(right<n)
        {
            char ch=s[right];
            if(freq1[ch]!=0 )
            {
                if(freq1[ch]>freq2[ch])
                countChars--;
                freq2[ch]++; 
            }

            while(countChars==0)
            {
                if(start==-1 || right-left<end-start )
                {
                    start=left;
                    end=right;
                }
                if(freq1[s[left]]!=0){
                    if(freq2[s[left]]==freq1[s[left]])
                    countChars++;
                    freq2[s[left]]--;
                }
                left++;
            }
            right++;
        }
        if(start==-1) return "";
        return s.substr(start,end-start+1);
    }
};