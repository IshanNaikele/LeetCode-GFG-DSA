/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) 
    {
        // code here
        if(!head_ref ) return  ;
        Node *temp=*head_ref;
        while(temp && temp->data==x)   temp=temp->next;
        *head_ref=temp;
        while(temp->next)
        {
            if(temp->next->data==x)
            {
                Node *fut=temp->next;
                temp->next=fut->next;
                if(fut->next)
                fut->next->prev=temp;
                
            }
            else
            temp=temp->next;
        }
        
    }
};