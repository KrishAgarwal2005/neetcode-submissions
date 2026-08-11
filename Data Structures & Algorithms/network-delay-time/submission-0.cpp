class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        for(int i=1;i<=n-1;i++){
            for(auto&edge:times){
                int u=edge[0];
                int v=edge[1];
                int w=edge[2];
                if(dist[u]+w<dist[v] && dist[u]!=INT_MAX)
                dist[v]=dist[u]+w;
            }
        }
        int answer=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            answer=max(answer,dist[i]);
        }
        return answer;
    }
};
