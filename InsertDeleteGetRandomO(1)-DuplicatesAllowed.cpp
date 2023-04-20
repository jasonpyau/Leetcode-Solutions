class RandomizedCollection {
public:
    RandomizedCollection() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        unordered_set<int>& indices_set = vals[val];
        bool res = indices_set.empty();
        choose.push_back(val);
        indices_set.insert(choose.size()-1);
        return res;
    }
    
    bool remove(int val) {
        unordered_set<int>& indices_set = vals[val];
        if (indices_set.empty())
            return false;
        // Choose back of choose since for O(1) pop in choose
        int replace_val = choose.back();
        if (replace_val == val) {
            indices_set.erase(choose.size()-1);
        } else {
            int remove_ind = *(indices_set.begin());
            unordered_set<int>& replace_indices_set = vals[replace_val];
            choose[remove_ind] = replace_val;
            indices_set.erase(indices_set.begin());
            replace_indices_set.erase(choose.size()-1);
            replace_indices_set.insert(remove_ind);
        }
        choose.pop_back();
        return true;
    }
   
    int getRandom() {
        return choose[rand()%choose.size()];
    }

private: 
    // Maps a val to a set which holds indices in choose. Allows for O(1) removal for
    // vals in choose
    unordered_map<int, unordered_set<int>> vals;
    // Holds vals so that they can easily be referenced randomly in O(1) time
    vector<int> choose;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
