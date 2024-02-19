class BoundedBlockingQueue {
private:
    int _capacity;
    queue<int> _queue;
    mutex _mu;
    condition_variable _cv;

public:
    BoundedBlockingQueue(int capacity) {
        _capacity = capacity;
    }
    
    void enqueue(int element) {
        std::unique_lock<mutex> lk(_mu);
        _cv.wait(lk, [this]{ return _queue.size() < _capacity;} );
        _queue.push(element);
        lk.unlock();
        _cv.notify_all();
    }
    
    int dequeue() {
        int el;
        std::unique_lock<mutex> lk(_mu);
        _cv.wait(lk, [this]{ return _queue.size() != 0; });
        el = _queue.front();
        _queue.pop();
        lk.unlock();
        _cv.notify_all();
        return el;
    }
    
    int size() {
        unique_lock<mutex> lk(_mu);
        return _queue.size();
    }
};
