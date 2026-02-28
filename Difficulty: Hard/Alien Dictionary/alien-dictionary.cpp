class Solution {
public:
    string findOrder(vector<string> &dict) {
        
        unordered_set<char> st;
        for (auto &word : dict) {
            for (char c : word) {
                st.insert(c);
            }
        }

        // Map each character to an index
        unordered_map<char, int> mp;
        int idx = 0;
        for (char c : st) {
            mp[c] = idx++;
        }

        int K = st.size();
        vector<vector<int>> adj(K);
        vector<int> indegree(K, 0);

        int N = dict.size();

        // Build graph
        for (int i = 0; i < N - 1; i++) {
            string w1 = dict[i];
            string w2 = dict[i + 1];

            int len = min(w1.size(), w2.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    int u = mp[w1[j]];
                    int v = mp[w2[j]];
                    adj[u].push_back(v);
                    indegree[v]++;
                    found = true;
                    break;
                }
            }

            // Invalid case: prefix issue
            if (!found && w1.size() > w2.size()) {
                return "";
            }
        }

        // Kahn's Topological Sort
        queue<int> q;
        for (int i = 0; i < K; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        string ans = "";
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // find corresponding character
            for (auto &p : mp) {
                if (p.second == u) {
                    ans += p.first;
                    break;
                }
            }

            for (auto v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return ans.size() == K ? ans : "";
    }
};