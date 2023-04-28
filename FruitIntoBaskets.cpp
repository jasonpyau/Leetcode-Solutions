class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int size = fruits.size();
        int curr_fruits[2];
        int curr_fruits_ind[2];
        int i = 1, last = fruits[0];
        for (; i < size && fruits[i] == last; i++);
        if (i == size)
            return size;
        curr_fruits[0] = fruits[0];
        curr_fruits[1] = fruits[i];
        curr_fruits_ind[0] = 0;
        curr_fruits_ind[1] = i;
        int ans = i;
        last = fruits[i];
        for (int curr = i; i < size; i++) {
            if (fruits[i] != curr_fruits[0] && fruits[i] != curr_fruits[1]) {
                curr_fruits[0] = curr_fruits[1];
                curr_fruits[1] = fruits[i];
                curr_fruits_ind[0] = curr_fruits_ind[1];
                curr_fruits_ind[1] = i;
                curr = i-curr_fruits_ind[0]+1;
                last = fruits[i];
                continue;
            } 
            if (fruits[i] != last) {
                swap(curr_fruits[0], curr_fruits[1]);
                curr_fruits_ind[0] = curr_fruits_ind[1];
                curr_fruits_ind[1] = i;
            }
            ans = max(ans, ++curr);
            last = fruits[i];
        }
        return ans;
    }
};
