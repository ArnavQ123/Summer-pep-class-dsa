class Solution {
public:
    bool isCyclic(int V, vector<vector<int>> &edges) {

        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int cnt = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;

            for (int neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }
        return cnt != V;
    }
};