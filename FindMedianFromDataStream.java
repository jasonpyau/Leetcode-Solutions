class MedianFinder {

    private PriorityQueue<Integer> left, right;

    public MedianFinder() {
        left = new PriorityQueue<>(Comparator.reverseOrder());
        right = new PriorityQueue<>();
    }
    
    public void addNum(int num) {
        if (left.size() == 0) {
            left.offer(num);
            return;
        }
        // Insert.
        if (left.peek() < num) {
            right.offer(num);
        } else {
            left.offer(num);
        }
        // Swap, if needed.
        if ((left.size()+right.size())%2 == 0) {
            if (left.size() > right.size()) {
                right.offer(left.poll());
            } else if (right.size() > left.size()) {
                left.offer(right.poll());
            }
        }
    }
    
    public double findMedian() {
        if (left.size() > right.size()) {
            return left.peek();
        } else if (right.size() > left.size()) {
            return right.peek();
        }
        return (left.peek()+right.peek())/2.0;
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
