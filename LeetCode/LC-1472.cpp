//1472. Design Browser History

class BrowserHistory {
    
public:
    stack<string>browserStack, forwardStack;
    BrowserHistory(string homepage) {
        browserStack.push(homepage);
    }
    
    void visit(string url) {
        browserStack.push(url);
        //clear the forward stack
        while(!forwardStack.empty())
            forwardStack.pop();
    }
    
    string back(int steps) {
        while(steps--){
            if(browserStack.size() > 1){
                forwardStack.push(browserStack.top());

                browserStack.pop();
            }
            else
                break;
        }
        return browserStack.top();
    }
    
    string forward(int steps) {
        while(steps--){
            if(!forwardStack.empty()){
                browserStack.push(forwardStack.top());

                forwardStack.pop();
            }
            else
                break;
        }

        return browserStack.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */