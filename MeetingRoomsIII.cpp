class Solution {
public:
    // O(n+m*log(m*n)).
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return (b[0] > a[0]);
        });
        vector<int> freq(n, 0);
        set<int> open_rooms;
        // Pairs sorted by end time, then room number. Perfect!
        min_heap<pair<ll, int>> booked_rooms_end;
        for (int i = 0; i < n; ++i) {
            open_rooms.insert(i);
        }
        // 5*10^5*10^5 > INT_MAX (n=1, each meeting takes 5*10^5 time).
        ll time = 0;
        for (int i = 0; i < meetings.size(); ++i) {
            vector<int>& m = meetings[i];
            time = max(time, 1ll*m[0]);
            int open_room;
            clear_rooms(time, open_rooms, booked_rooms_end);
            if (!open_rooms.empty()) {
                // We have a room open, just book it!
                open_room = *(open_rooms.begin());
            } else {
                // Need to wait for an opening!
                open_room = booked_rooms_end.top().second;
                // The (i+1)th meeting will start at max(smallest booked end time, meetings[i+1][0]).
                time = booked_rooms_end.top().first;
                // Clear open_room and any room with same end time!
                clear_rooms(time, open_rooms, booked_rooms_end);
            }
            // Update the relevant information in both cases.
            open_rooms.erase(open_room);
            ++freq[open_room];
            booked_rooms_end.push(make_pair(time+(m[1]-m[0]), open_room));
        }
        int ans = 0, max_freq = 0;
        for (int i = 0; i < n; ++i) {
            if (freq[i] > max_freq) {
                max_freq = freq[i];
                ans = i;
            }
        }
        return ans;
    }
private:
    template<typename T>
    using min_heap = priority_queue<T, vector<T>, greater<T>>;
    using ll = long long;

    void clear_rooms(ll time, set<int>& open_rooms, min_heap<pair<ll, int>>& booked_rooms_end) {
        while (!booked_rooms_end.empty() && time >= booked_rooms_end.top().first) {
            open_rooms.insert(booked_rooms_end.top().second);
            booked_rooms_end.pop();
        }
    }
};
