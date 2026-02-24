class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {
   Node *front,*rear;
   int totalSize;
  public:
    myQueue() 
    {
        // Initialize your data members
        front =rear=NULL;
        totalSize=0;
    }

    bool isEmpty() 
    {
        // check if the queue is empty
        return totalSize==0;
    }

    void enqueue(int x) 
    {
        // Adds an element x at the rear of the queue
        if(front==NULL)
        {
            front=new Node(x);
            rear=front;
        }
        else
        {
            rear->next=new Node(x);
            rear=rear->next;
        }
        totalSize++;
    }

    void dequeue() 
    {
        // Removes the front element of the queue
        if(front==NULL) return ;
        Node *temp=front;
        front=front->next;
        delete temp;
        totalSize--;
    }

    int getFront() 
    {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(totalSize==0) return -1;
        return front->data;
    }

    int size() 
    {
        // Returns the current size of the queue.
        return totalSize;
    }
};
