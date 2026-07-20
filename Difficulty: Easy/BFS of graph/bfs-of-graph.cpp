class Solution {
public:
    vector<int> bfs(vector<vector<int>>& adj) {
        int V = adj.size();

        vector<int> ans;
        vector<int> vis(V, 0);
        queue<int> q;

        vis[0] = 1;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        return ans;
    }
};