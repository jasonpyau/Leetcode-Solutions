class FrequencyTracker {
public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        int old_freq = num_to_freq[number];
        num_to_freq[number]++;
        if (old_freq) {
            freq_to_nums[old_freq].erase(number);
        }
        freq_to_nums[old_freq+1].insert(number);
    }
    
    void deleteOne(int number) {
        int old_freq = num_to_freq[number];
        if (old_freq) {
            num_to_freq[number]--;
            freq_to_nums[old_freq].erase(number);
            if (--old_freq) {
                freq_to_nums[old_freq].insert(number);
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        return (freq_to_nums[frequency].size());
    }
private:
    unordered_map<int,int> num_to_freq;
    unordered_map<int,unordered_set<int>> freq_to_nums;
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
