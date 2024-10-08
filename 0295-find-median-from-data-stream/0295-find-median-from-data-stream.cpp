// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
public:
    priority_queue<long> l, r;
    void addNum(int num) {
        l.push(num);
        r.push(-l.top());
        l.pop();
        if (l.size() < r.size()) {
            l.push(-r.top());
            r.pop();
        }
    }
    double findMedian() {
        return l.size() > r.size() ? l.top() : (l.top() - r.top()) / 2.0;
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */