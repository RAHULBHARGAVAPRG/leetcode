class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
               vector<pair<int,int>> adj[n];
               const int MOD = 1e9 + 7;
        for(auto it: roads){
           int u = it[0];
           int v = it[1];
           int wt= it[2];
           adj[u].push_back({v,wt});
           adj[v].push_back({u, wt});
        } 
priority_queue<
    pair<long long,int>,
    vector<pair<long long,int>>,
    greater<pair<long long,int>>
> pq;
vector<long long> dist(n, LLONG_MAX);
vector<long long> ways(n, 0);
dist[0]=0;
ways[0]=1;
pq.push({0,0});
while(!pq.empty()){
    auto it= pq.top();
    pq.pop();
    long long dis = it.first;
    int node= it.second;
    for(auto it :adj[node]){
        int adjnode = it.first;
        int wt=it.second;
        if(dis+wt<dist[adjnode]){
            dist[adjnode]= dis + wt;
            ways[adjnode] = ways[node];
            pq.push({dis + wt,adjnode});
                    }
                    else if (dis+wt== dist[adjnode]){
                    ways[adjnode] = (ways[adjnode] + ways[node]) % MOD;   
                    }
    }
}
return ways[n-1];
    }
};