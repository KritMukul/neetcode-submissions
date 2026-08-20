class MinStack {
    stack<long> st;
    long min;
public:

    MinStack() {
        min = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(0);
            min = val;
        }
        else {
            st.push(val-min);
            if(val < min) min = val;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long pop = st.top();
        st.pop();
        if(pop < 0) min = min - pop;
    }
    
    int top() {
        long top = st.top();
        return top > 0 ? top+min : min;
    }
    
    int getMin() {
        return min;
    }
};
