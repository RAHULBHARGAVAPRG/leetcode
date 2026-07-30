class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rev(n);

for(int i = 0; i < n; i++) {
    for(auto it : graph[i]) {
        rev[it].push_back(i);
    }
}
vector<int> indeg(n,0);
for(int i=0;i<n;i++){
    for(auto it : rev[i]){
        indeg[it]++;
    }
}
queue <int> q ;
for(int i =0;i<n;i++){
    if(indeg[i]==0){
q.push(i);

    }
}
vector<int> ans ;
while(!q.empty()){
int node = q.front();
q.pop();
ans.push_back(node);
for(auto it : rev[node]){
    indeg[it]--;
    if(indeg[it]==0){
        q.push(it);
    }
}

}
sort(ans.begin(), ans.end());
return ans;
    }
};