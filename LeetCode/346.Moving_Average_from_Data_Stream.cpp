class MovingAverage {
private:
    int que_max_size;
    queue<int> que;
    int sum;

public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        que_max_size = size;
        sum = 0;
    }
    
    double next(int val) {
        if (que_max_size == 0) {
            return 0;
        }
        if (que.size() == que_max_size) {
            sum -= que.front();
            que.pop();
        }
        que.push(val);
        sum += val;
        
        return double(sum) / que.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */