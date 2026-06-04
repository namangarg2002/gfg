class myStack {
    queue<int> q1;
    queue<int> q2;

  public:

    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop() {
        if(q1.empty()){
            return;
        }
        else{
            q1.pop();
        }
    }

    int top() {
        if(q1.empty()){
            return -1;
        }
        
        return q1.front();
    }

    int size() {
        return q1.size() + q2.size();
    }
};
