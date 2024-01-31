class Solution {
public:
    // O(n*log(log(n))).
    long long countPaths(int n, vector<vector<int>>& edges) {
        sieve(n);
        vector<vector<int>> adj(n+1);
        // paths[v].first: Store number of paths you can make with 1 prime from
        // u to v and v's descendents, if u is non-prime.
        // paths[v].second: Store number of paths you can make with 0 primes from
        // u to v and v's descendents, if u is non-prime.
        vector<pair<int, int>> paths(n+1);
        for (vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        // Just pick 1 to be root.
        return solve(1, 0, adj, paths);
    }
private:
    vector<bool> prime;

    // O(n*log(log(n))).
    void sieve(int n) {
        prime = vector<bool>(n+1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; 1ll*i*i <= n; ++i) {
            if (!prime[i]) {
                continue;
            }
            for (int j = 1ll*i*i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    long long solve(int u, int par, vector<vector<int>>& adj, vector<pair<int, int>>& paths) {
        pair<int, int>& path = paths[u];
        long long res = 0;
        for (int v : adj[u]) {
            if (v != par) {
                res += solve(v, u, adj, paths);
                path.first += paths[v].first;
                path.second += paths[v].second;
            }
        }
        // Two cases to consider, if u is prime or not prime.
        if (prime[u]) {
            // Connect u with all the paths with 0 primes.
            res += path.second;
            long long zero_to_zero = 0;
            for (int v : adj[u]) {
                if (v != par) {
                    // Link paths with 0 primes with paths with 0 primes, as u is prime.
                    zero_to_zero += 1ll*(path.second-paths[v].second)*paths[v].second;
                }
            }
            // We double counted each valid path.
            res += zero_to_zero/2;
            // All the paths with 0 primes becomes 1, also add a path ending with u.
            path.first = path.second+1;
            // Double prime.
            path.second = 0;
        } else {
            for (int v : adj[u]) {
                // Link paths with 1 prime with paths with 0 primes.
                if (v != par) {
                    res += 1ll*(path.first-paths[v].first)*paths[v].second;
                }
            }
            // Connect u with all the paths with 1 prime.
            res += path.first;
            // Add a path ending with u.
            path.second += 1;
        }
        return res;
    }
};
