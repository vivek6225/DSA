//T.C = O(N lon N)
//S.C = O(N)

class MedianFinder {
public:
    
    // Max heap: stores the smaller half of the numbers
    priority_queue<int> leftMaxHeap;

    // Min heap: stores the larger half of the numbers
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;
    
    MedianFinder() {
        // Constructor: initially both heaps are empty
    }
    
    void addNum(int num) {
        // If left heap is empty, push first element there
        if(leftMaxHeap.empty()){
            leftMaxHeap.push(num);
            return;
        }
        
        // Decide which heap to insert the new number into
        if(num > leftMaxHeap.top())
            rightMinHeap.push(num);   // goes to right (larger half)
        else
            leftMaxHeap.push(num);    // goes to left (smaller half)
        
        // Balance the heaps so that size difference is at most 1
        balanceHeaps();
    }
    
    void balanceHeaps() {
        // If right heap has more elements, move one element to left heap
        if(rightMinHeap.size() > leftMaxHeap.size()){
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        } 
        else {
            // If left heap has more than one extra element, move one to right heap
            if(leftMaxHeap.size() > rightMinHeap.size() + 1) {
                rightMinHeap.push(leftMaxHeap.top());
                leftMaxHeap.pop();
            }
        }
    }
    
    double findMedian() {
        // If left heap has more elements, its top is the median (odd count)
        if(leftMaxHeap.size() > rightMinHeap.size()){
            return leftMaxHeap.top();
        }
        else {
            // If both heaps have equal size, median is average of both tops
            double ans = leftMaxHeap.top() + rightMinHeap.top();
            ans /= 2.0;   // divide by 2.0 to get correct double value
            return ans;
        }
    }
};
