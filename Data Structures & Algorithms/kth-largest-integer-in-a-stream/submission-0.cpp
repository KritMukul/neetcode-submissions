class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int x;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int& it: nums) {
            pq.push(it);
            if(pq.size() > k) pq.pop();
        }
        x = k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > x) pq.pop();
        return pq.top();
    }
};
