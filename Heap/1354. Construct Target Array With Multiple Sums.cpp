class Solution {
public:
    bool isPossible(vector<int>& target) 
    {
        priority_queue<int>pq;
        long long sum=0;
         
        for(int i=0;i<target.size();i++)
        {
            sum+=target[i];
            pq.push(target[i]);
        }

        int maxElement ,remainSum ,element;
        while(pq.top()!=1)
        {
            maxElement=pq.top();
            pq.pop();
            remainSum=sum-maxElement;
            if(remainSum<=0 || remainSum>=maxElement) return false;
            element=maxElement%remainSum;
            if(element==0 )
            {
                if(remainSum!=1) return false;
                element = remainSum; 
            }
            sum=remainSum+element;
            pq.push(element);
        }

        return true;
    }
};