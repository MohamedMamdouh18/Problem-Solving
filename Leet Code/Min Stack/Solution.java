public class MinStack {
    public Pair[] arr;
    public int ptr = 0;

    public MinStack() {
        arr = new Pair[30050];
    }

    public void push(int val) {
        arr[ptr] = new Pair();
        arr[ptr].first = val ;
        if(ptr == 0)
            arr[ptr].second = val;
        else
            arr[ptr].second = Integer.min(val ,arr[ptr-1].second);
        ptr += 1;
    }

    public void pop() {
        ptr -= 1;
    }

    public int top() {
        return arr[ptr-1].first;
    }

    public int getMin() {
        return arr[ptr-1].second;
    }
}

class Pair{
    public int first ;
    public int second;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
