class Solution {
  public:
  
    vector<double> getMedian(vector<int> &arr) 
    {
        // code here
        priority_queue<int> maxHeap; // left half
        priority_queue<int, vector<int>, greater<int>> minHeap; // right half
        
        vector<double> ans;

        for (int x : arr) {
            // ️Insert element
            if (maxHeap.empty() || x <= maxHeap.top())
                maxHeap.push(x);
            else
                minHeap.push(x);

            //  Balance heaps
            if (maxHeap.size() > minHeap.size() + 1) 
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else if (minHeap.size() > maxHeap.size()) 
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            //  Find median
            if (maxHeap.size() == minHeap.size()) {
                ans.push_back((maxHeap.top() + minHeap.top()) / 2.0);
            } else {
                ans.push_back(maxHeap.top());
            }
        }

        return ans;
    }
};
