//933 --> Number of Recent Calls


class RecentCounter {
public:
    queue<int>q;

    RecentCounter() {
        
    }
    
    int ping(int t) {
        //1. push the recent request
        q.push(t);

        //2. pop older request which are not in range
        while(!q.empty() && q.front() < (t-3000))
            q.pop();

        //3. queue contain the no. of calls
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */