class myQueue {
    stack<int> s1, s2;
  public:
    myQueue() {
        // Initialize your data members
    }

    void enqueue(int x) {
        s1.push(x);
    }

    void dequeue() {
        if(s1.empty() && s2.empty()){
            return;
        }
        if(!s2.empty()){
            s2.pop();
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
    }

    int front() {
        int frontElement = -1;
        if(s1.empty() && s2.empty()){
            return frontElement;
        }
        else if(!s2.empty()){
            frontElement = s2.top();
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            frontElement = s2.top();
        }
        
        return frontElement;
    }

    int size() {
        return s1.size() + s2.size();
    }
};
