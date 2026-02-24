class myQueue {

  public:
    int *arr;
    int size;
    int front=-1,rear=-1;
    myQueue(int n) 
    {
        // Define Data Structures
        arr=new int[n];
        size=n;
        
    }

    bool isEmpty() 
    {
        // check if the queue is empty
        return front==-1;
    }

    bool isFull() 
    {
        // check if the queue is full
        return (rear+1)%size==front;
    }

    void enqueue(int x) 
    {
        // Adds an element x at the rear of the queue.
        if(front==-1)
        {
            front=rear=0;
            arr[front]=x;
        }
        else  
        {
            if((rear+1)%size==front)
            return;
            rear=(rear+1)%size;
            arr[rear]=x;
        }
    }

    void dequeue() 
    {
        // Removes the front element of the queue.
        if(front==-1) 
        return;
        
        if(front==rear)     front=rear=-1;
        else                front=(front+1)%size;
        
    }

    int getFront() 
    {
        // Returns the front element of the queue.
        if(front==-1) return -1;
        return arr[front];
    }

    int getRear() 
    {
        // Return the last element of queue
        if(front==-1) return -1;
        return arr[rear];
    }
};