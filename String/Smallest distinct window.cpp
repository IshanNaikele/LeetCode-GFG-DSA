class Solution {
public:
    int findSubString(string& str) {

        vector<int> present(26,0);

        int required = 0;

        for(char ch : str) {
            if(present[ch-'a']==0)
                required++;
            present[ch-'a']++;
        }

        vector<int> freq(26,0);

        int formed = 0;
        int left = 0;
        int ans = INT_MAX;

        for(int right=0; right<str.size(); right++) {

            int idx = str[right]-'a';

            if(freq[idx]==0)
                formed++;

            freq[idx]++;

            while(formed==required) {

                ans = min(ans, right-left+1);

                freq[str[left]-'a']--;

                if(freq[str[left]-'a']==0)
                    formed--;

                left++;
            }
        }

        return ans;
    }
};