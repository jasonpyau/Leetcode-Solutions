class SnapshotArray {
public:
    SnapshotArray(int length) {
        curr_snap = 0;
        ind_to_snap_vals = vector<vector<pair<int, int>>>(length);
        for (vector<pair<int, int>>& snap_vals : ind_to_snap_vals) {
            snap_vals.push_back(make_pair(curr_snap, 0));
        }
    }
    
    void set(int index, int val) {
        vector<pair<int, int>>& snap_vals = ind_to_snap_vals[index];
        if (snap_vals.back().first == curr_snap) {
            snap_vals.back().second = val;
        } else {
            snap_vals.push_back(make_pair(curr_snap, val));
        }
    }
    
    int snap() {
        return curr_snap++;
    }
    
    int get(int index, int snap_id) {
        vector<pair<int, int>>& snap_vals = ind_to_snap_vals[index];
        int low = 0, mid, high = snap_vals.size()-1;
        int res;
        while (high >= low) {
            mid = (low+high)>>1;
            pair<int, int>& curr = snap_vals[mid];
            if (curr.first == snap_id) {
                res = curr.second;
                break;
            } else if (curr.first < snap_id) {
                low = mid+1;
                res = curr.second;
            } else {
                high = mid-1;
            }
        }
        return res;
    }
private:
    // each ind of vector corresponds to ind in SnapshotArray
    // vector[ind] is list of all snapshots and the snapshot's val for that ind
    vector<vector<pair<int, int>>> ind_to_snap_vals;
    int curr_snap;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
