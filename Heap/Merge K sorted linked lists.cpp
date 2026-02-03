/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
  
    Node* mergeKLists(vector<Node*>& arr) 
    {
        // code here
        priority_queue<
                        pair<int, Node*>,
                        vector<pair<int, Node*>>,
                        greater<pair<int, Node*>>
                      > pq;
        for(int i=0;i<arr.size();i++)
            if(arr[i]) pq.push(make_pair(arr[i]->data,arr[i]));
        pair<int,Node*>element;
         
        Node *head=NULL ,*tail=NULL;
         
        while(!pq.empty())
        {
            element=pq.top();
            pq.pop();
            if(!head)
            {
                head=element.second;
                tail=element.second;
            }
            else
            {
                tail->next=element.second;
                tail=tail->next;
            }
            
            if(element.second->next)
            pq.push(make_pair(element.second->next->data,element.second->next));
        }
        return head;
    }
};



