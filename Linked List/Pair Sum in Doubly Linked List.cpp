//Approach 1:Using Hashmap 
// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) 
    {
        // code here
        unordered_set<int>mpp;
        vector<pair<int,int>>ans;
        
        Node *temp=head;
        while(temp)
        {
            int compliment=target-temp->data;
            if(mpp.find(compliment)!=mpp.end())
            {
                if(temp->data<=compliment)
                ans.push_back({temp->data,compliment});
                else
                ans.push_back({compliment,temp->data});
            }
            mpp.insert(temp->data);
            temp=temp->next;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//Approach 2 :Same as Two Sum Using left & right pointer 
// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) 
    {
        // code here
        vector<pair<int,int>> ans;
        if(!head) return ans;

        Node* left = head;
        Node* right = head;

         
        while(right->next)
            right = right->next;

        
        while(left && right && left != right && right->next != left)
        {
            int sum = left->data + right->data;

            if(sum == target)
            {
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if(sum < target)
            {
                left = left->next;
            }
            else
            {
                right = right->prev;
            }
        }
        return ans;
    }
};