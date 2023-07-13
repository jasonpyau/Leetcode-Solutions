class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(), false);
        vis[0] = true;
        queue<int> q;
        q.push(0);
        int count = 1;
        while (!q.empty()) {
            vector<int>& keys = rooms[q.front()];
            q.pop();
            for (int key : keys) {
                if (!vis[key]) {
                    q.push(key);
                    vis[key] = true;
                    count++;
                }
            }
        }
        return (count == rooms.size());
    }
};
