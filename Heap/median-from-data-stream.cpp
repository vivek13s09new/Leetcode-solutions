class MedianFinder {
public:
    priority_queue<double> maxh;
    priority_queue<double, vector<double>, greater<double>> minh;
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        double num1 = num;
        if(maxh.empty() || maxh.top() > num1){
            maxh.push(num1);
        }
        else{
            minh.push(num1);
        }
        if(maxh.size() > minh.size() + 1){
            double temp = maxh.top();
            maxh.pop();
            minh.push(temp);
        }
        else if(minh.size() > maxh.size() + 1){
            double temp = minh.top();
            minh.pop();
            maxh.push(temp);
        }
    }
    
    double findMedian() {
        if(maxh.size() == minh.size()){
            return (maxh.top() + minh.top())/2;
        }
        else if(maxh.size() > minh.size()){
            return maxh.top();
        }
        else{
            return minh.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
