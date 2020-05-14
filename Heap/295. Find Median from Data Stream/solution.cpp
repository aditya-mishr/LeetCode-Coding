class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> lo;//max heap
    priority_queue<int,vector<int>,greater<int>> hi;//min heap
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(lo.empty())
            lo.push(num);
        else
        {
            if(num>lo.top())
                hi.push(num);
            else
                lo.push(num);
            if(lo.size()>hi.size())
            {
                hi.push(lo.top());
                lo.pop();
            }
            if(hi.size()>lo.size())
            {
                lo.push(hi.top());
                hi.pop();
            }
                
        }
        
    }
    
    double findMedian() {
        if(lo.size()==hi.size())
            return (double)(lo.top()+hi.top())/2.0;
        else if(lo.size()>hi.size())
            return lo.top();
        else
            return hi.top();
            
    }
};