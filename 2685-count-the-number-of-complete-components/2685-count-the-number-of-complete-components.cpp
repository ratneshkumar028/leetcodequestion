class Solution {
public:
    vector<int> vis;

    void dfs(int node, vector<int> adj[], int &nodes, int &edgesCnt) {
        vis[node] = 1;
        nodes++;
        edgesCnt += adj[node].size();

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                dfs(nei, adj, nodes, edgesCnt);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vis.assign(n, 0);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {   
                int nodes = 0;
                int edgesCnt = 0;

                dfs(i, adj, nodes, edgesCnt);

                int actualEdges = edgesCnt / 2;
                int requiredEdges = nodes * (nodes - 1) / 2;

                if (actualEdges == requiredEdges)
                    ans++;
            }
        }

        return ans;
    }
};