// User function Template for C++

class BrowserHistory {
    stack<string> browserStack, fwdStack;
  public:
    // constructor to initialize object with homepage
    BrowserHistory(string homepage) {
        browserStack.push(homepage);
    }

    // visit current url
    void visit(string url) {
        while(!fwdStack.empty()){
            fwdStack.pop();
        }
        browserStack.push(url);
    }

    // 'steps' move backward in history and return current page
    string back(int steps) {
        while(steps--){
            if(browserStack.size() > 1){
                fwdStack.push(browserStack.top());
                browserStack.pop();
            }else{
                break;
            }
        }
        return browserStack.top();
    }

    // 'steps' move forward and return current page
    string forward(int steps) {
        
        while(steps--){
            if(!fwdStack.empty()){
                browserStack.push(fwdStack.top());
                fwdStack.pop();
            }else{
                break;
            }
        }
        
        return browserStack.top();
    }
};