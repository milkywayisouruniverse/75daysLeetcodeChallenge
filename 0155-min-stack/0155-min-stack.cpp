class MinStack {
public:

    stack<pair<int,int>> st;

    MinStack() {}

    void push(int val) {

        pair<int,int> p = {val, val};

        if(!st.empty()){
            if(st.top().second < val)
                p.second = st.top().second;
        }

        st.push(p);
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};