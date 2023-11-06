class SeatManager {
public:
    SeatManager(int n) {
        vector<int> temp(n);
        for (int i = 0; i < n; ++i) {
            temp[i] = i+1;
        }
        pq = priority_queue<int, vector<int>, greater<int>>(temp.begin(), temp.end());
    }
    
    int reserve() {
        int res = pq.top();
        pq.pop();
        return res;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
