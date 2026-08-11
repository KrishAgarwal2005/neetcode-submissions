class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times,
                         int n, int k) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto &edge : times) {

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v,w});
        }

        const int INF = 1e9;

        vector<int> dist(n + 1, INF);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[k] = 0;

        pq.push({0,k});

        while(!pq.empty()) {

            auto [d,node] = pq.top();
            pq.pop();

            // Ignore outdated entry
            if(d > dist[node])
                continue;

            for(auto [neighbor, weight] : adj[node]) {

                int newDist = d + weight;

                if(newDist < dist[neighbor]) {

                    dist[neighbor] = newDist;

                    pq.push({
                        newDist,
                        neighbor
                    });
                }
            }
        }

        int answer = 0;

        for(int i = 1; i <= n; i++) {

            if(dist[i] == INF)
                return -1;

            answer = max(answer, dist[i]);
        }

        return answer;
    }
};
