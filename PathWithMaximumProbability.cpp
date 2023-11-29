class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // first -> b, second -> succProb
        vector<vector<pair<int, double>>> graph(n);
        int i = 0;
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back(make_pair(edge[1], succProb[i]));
            graph[edge[1]].push_back(make_pair(edge[0], succProb[i++]));
        }
        vector<double> best_prob(n, 0.0);
        // first -> curr_prob, second -> curr_node
        priority_queue<pair<double, int>> pq;
        pq.push(make_pair(1.0, start_node));
        best_prob[start_node] = 1.0;
        while (!pq.empty()) {
            auto [curr_prob, curr_node] = pq.top();
            pq.pop();
            if (curr_node == end_node) {
                break;
            }
            for (auto [next_node, next_node_prob] : graph[curr_node]) {
                if (next_node_prob*curr_prob > best_prob[next_node]) {
                    best_prob[next_node] = next_node_prob*curr_prob;
                    pq.push(make_pair(best_prob[next_node], next_node));
                }
            }
        }
        return best_prob[end_node];
    }
};
