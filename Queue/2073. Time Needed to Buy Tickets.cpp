// Approach 1:
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) 
    {
        int time=0,n=tickets.size(),num=tickets[k];
        for(int i=0;i<n;i++)
        {
            if(i<=k)
            time+=min(tickets[i],num);
            else 
            time+=min(tickets[i],num-1);
        }
        return time;
    }
};

//Approach 2 :
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) 
    {
        queue<int>q;
        for(int i=0;i<tickets.size();i++) q.push(i);
        int time=0;
        while(tickets[k]!=0  && !q.empty())
        {
            int index=q.front();
            q.pop();
            if(tickets[index]>0) tickets[index]--;
            if(tickets[index]>0)
            q.push(index);
            time++;
        }
        return time;
    }
};