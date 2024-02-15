class Solution {
// Alternate solution in O(n) time!
// make_heap is O(n) time.
// The longest invalid sequence is [1,2,4,8,16,32,...]
// 1+10+100+1000+10000 = 11111... < 100000..., in binary.
// Thus, we have c*n+k*log(n), c in Z+, k <= 30 (2^31 > 10^9) = O(n).
public:
    long long largestPerimeter(vector<int>& nums) {
        vector<int> heap(nums.begin(), nums.end());
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        make_heap(heap.begin(), heap.end());
        while (!heap.empty() && heap.front() >= sum-heap.front()) {
            sum -= heap.front();
            pop_heap(heap.begin(), heap.end());
            heap.pop_back();
        }
        // k must be at least 3.
        return (heap.size() >= 3) ? sum : -1;
    }
};
