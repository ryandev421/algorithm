class Solution {
public:
    vector<vector<int>> list;
    int* discoveredDepth;
    vector<vector<int>> res;

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        discoveredDepth = new int[n]{0,};
        list.resize(n);

        for (int i = 0; i < connections.size(); i++) {
            int s = connections[i][0];
            int e = connections[i][1];
            list[s].push_back(e);
            list[e].push_back(s);
        }
        getCriticalConnections(0, -1, 1);
        return res;
    }

    int getCriticalConnections(int node, int parent, int depth) {
        discoveredDepth[node] = depth;
        int discoveredMinDepth = depth;

        for (int i = 0; i < list[node].size(); i++) {
            int e = list[node][i];
            if (e == parent) continue;
            if (discoveredDepth[e] == 0) {
                int childMinDepth = getCriticalConnections(e, node, depth + 1);
                discoveredMinDepth = min(discoveredMinDepth, childMinDepth);
                if (depth < childMinDepth) {
                    vector<int> criticalConnection;
                    criticalConnection.push_back(node);
                    criticalConnection.push_back(e);
                    res.push_back(criticalConnection);
                }
            } else {
                discoveredMinDepth = min(discoveredMinDepth, discoveredDepth[e]);
            }
        }
        return discoveredMinDepth;
    }
};