#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int> > max_heap;
    priority_queue<int, vector<int>, greater<int> > min_heap;
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (max_heap.size() == min_heap.size())
            max_heap.push(num);
        else min_heap.push(num);
        while (max_heap.size() && min_heap.size() && max_heap.top() > min_heap.top()) {
            int t1 = max_heap.top(); max_heap.pop();
            int t2 = min_heap.top(); min_heap.pop();
            max_heap.push(t2);
            min_heap.push(t1);
        }
    }
    
    double findMedian() {
        if (max_heap.size() == min_heap.size()) {
            int t1 = max_heap.top();
            int t2 = min_heap.top();
            return (1.0 * (t1 + t2)) / 2;
        }
        else {
            int t1 = max_heap.top();
            return 1.0 * t1;
        }

    }
};

int main() {
    MedianFinder m;
    m.addNum(1);
    m.addNum(2);
    printf("%.2lf\n", m.findMedian());
    m.addNum(3);
    printf("%.2lf\n", m.findMedian());
    return 0;
}
