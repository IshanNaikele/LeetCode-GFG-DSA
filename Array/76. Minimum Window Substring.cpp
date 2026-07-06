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

class Solution {
public:
    string minWindow(string s, string t) 
    {
        if(s.size()<t.size()) return "";
        int n=s.size(),left=0;
        int minLen=-1,charReqd=t.size();
        int start=-1,end=-1;
        unordered_map<char,int>mpp1,mpp2;
        for(char ch:t) mpp1[ch]++;
        
        for(int right=0;right<n;right++)
        {
            if(mpp1.find(s[right])!=mpp1.end())
            {
                if(mpp1[s[right]]>mpp2[s[right]]) charReqd--;
                mpp2[s[right]]++;
            }
            while(charReqd==0)
            {
                if(start==-1 || (end-start)>(right-left))
                {
                    start=left;
                    end=right;
                }
                if(mpp1.find(s[left])!=mpp1.end())
                {
                    mpp2[s[left]]--;
                    if(mpp2[s[left]]<mpp1[s[left]])
                    charReqd++;
                }
                left++;
            }
        }
        if(start==-1 || end==-1) return "";
        return s.substr(start,end-start+1);
    }
};