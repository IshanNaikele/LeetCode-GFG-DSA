/* Link list Node

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */
class Solution {
  public:
    Node* deleteK(Node* head, int k) 
    {
        // code here
        if(k==1 || !head) return NULL;
        
        int count=1;
        Node *temp=head;
        while(temp)
        {
            if(count==k-1)
            {
                if(temp->next)
                temp->next=temp->next->next;
                temp=temp->next;
                count=1;
            }
            else
            {
                temp=temp->next;
                count++;
            }
        }
        return head;
    }
};