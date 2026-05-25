class SpecialStack {
  public:
    vector<pair<int, int>> vec;
    SpecialStack() {
        // Define Stack
    }

    void push(int x) {
        pair<int, int> p;
        if(vec.empty()){
            p.first = x;
            p.second = x;
        }else{
            p.first = x;
            int previousMinVal = vec.back().second;
            
            p.second = min(x, previousMinVal);
        }
        vec.push_back(p);
    }

    void pop() {
        vec.pop_back();
    }

    int peek() {
        if(vec.empty()){
            return -1;
        }
        
        return vec.back().first;
    }

    bool isEmpty() {
        return vec.empty();
    }

    int getMin() {
        if(vec.empty()){
            return -1;
        }
        
        return vec.back().second;
    }
};