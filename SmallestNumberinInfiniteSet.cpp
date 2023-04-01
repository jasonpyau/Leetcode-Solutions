class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        smallest = 1;
        addbacks.clear();
    }
    
    int popSmallest() {
        if (addbacks.empty())
            return smallest++;
        int ans, first = *(addbacks.begin());
        if (first <= smallest) {
            ans = first;
            addbacks.erase(addbacks.begin());
        }
        else {
            ans = smallest++;
        }
        return ans;
    }
    
    void addBack(int num) {
        if (num < smallest)
            addbacks.insert(num);
    }
private:
    int smallest;
    set<int> addbacks;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
