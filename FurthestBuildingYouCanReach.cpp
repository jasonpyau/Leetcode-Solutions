class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> used_ladders;
        int ans = 0;
        for (int i = 0, diff; i < heights.size()-1; ++i, ++ans) {
            diff = heights[i+1]-heights[i];
            // Need to use ladder/bricks.
            if (diff > 0) {
                // Use ladders greedily.
                if (ladders > 0) {
                    used_ladders.push(diff);
                    --ladders;
                    continue;
                } else if (!used_ladders.empty()) {
                    int smallest_height = used_ladders.top();
                    // Also need to check if replacing a ladder is the best option!
                    if (bricks >= smallest_height && diff > smallest_height) {
                        // Replace smallest height with bricks.
                        bricks -= smallest_height;
                        // Replace the ladder for this height.
                        used_ladders.pop();
                        used_ladders.push(diff);
                        continue;
                    }
                }
                // Can't do anything with ladders, try bricks.
                if (bricks >= diff) {
                    bricks -= diff;
                    continue;
                }
                // Welp, we can't do anything!
                break;
            }
        }
        return ans;
    }
};
