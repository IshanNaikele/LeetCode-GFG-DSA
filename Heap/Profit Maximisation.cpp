int Solution::solve(vector<int> &A, int B) 
{
    int profit=0;
    priority_queue<int>pq(A.begin(),A.end());//O(n)
    while(B--)
    {
        int vacant_seats=pq.top();
        profit+=vacant_seats;
        pq.pop();
        pq.push(vacant_seats-1);
    }
    return profit;
}
