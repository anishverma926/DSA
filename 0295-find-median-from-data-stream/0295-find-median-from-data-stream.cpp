class MedianFinder {
public:
    priority_queue<int> p1; // max Heap
    priority_queue<int, vector<int>, greater<int>> p2; // min Heap

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(p1.empty()){
            p1.push(num);
        }
        if(num > p1.top()){
            p2.push(num);
        }
        // we want that more element should be in max heap
        if(p2.size() > p1.size()){
            p1.push(p2.top());
        }
    }
    
    double findMedian() {
        int n = p1.size();
        int m = p2.size();

        int totalSize = (n + m);

        if(totalSize % 2){
            return p1.top();
        }
        else{
            return (p1.top() + p2.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */