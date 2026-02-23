class twoStacks {
  public:
    int arr[100];   // or 1000 depending on constraint
    int index1, index2;
    twoStacks() 
    {
        index1 = -1;
        index2 = 100;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        // code here
        if(index1+1!=index2)
        {
            index1++;
            arr[index1]=x;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        
        // code here
        if(index1!=index2-1)
        {
            index2--;
            arr[index2]=x;
        }
    }

    // Function to remove an element from top of the stack1.
        
    int pop1() 
    {
        // code here
        if(index1==-1) return -1;
        int element=arr[index1];
        index1--;
        return element;
    }

        
    // Function to remove an element from top of the stack2.
    int pop2() {
        // code here
        if(index2==100) return -1;
        int element=arr[index2];
        index2++;
        return element;
    }
};