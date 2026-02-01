// writen by mmd (fixed)
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// Algorithm:
// 1- find all bridges with Tarjan DFS algorithm
// 2- making components ignoring bridges
// 3- creake bridge tree (component_tree) with components(vertexes) and bridges(edges)
// 4- bfs from the component that contain node 1 and the component that contain node n to find the essential bridges
// 5- run multi-source BFS to find the minimum distance of every node from the essential bridges 


// Tarjan DFS
// pars: node, parent,     timer, first visit time,     lowest_time,                   adjacency list,               is_bridge
void dfs(int u, int p, int &timer, vector<int> &t_in, vector<int> &low, vector<vector<pair<int,int>>> &adj, vector<bool> &is_bridge) {
    t_in[u] = low[u] = ++timer;

    for (auto [v, id] : adj[u]) {
        if (v == p) continue; // parent
        if (!t_in[v]) { // not visited
            dfs(v, u, timer, t_in, low, adj, is_bridge);
            low[u] = min(low[u], low[v]);
            if (low[v] > t_in[u])
                is_bridge[id] = true;
        } else { // back edge
            low[u] = min(low[u], t_in[v]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--)
    {
        int n, m, qq, c; cin >> n >> m;

        vector<vector<pair<int,int>>> adj(n+1); // Adjacency List (node, edge_id)
        vector<int> U(m+1), V(m+1);
        vector<bool> is_bridge(m+1, false);

        for (int i = 1; i <= m; i++) {
            cin >> U[i] >> V[i];
            adj[U[i]].push_back({V[i], i});
            adj[V[i]].push_back({U[i], i});
        }

        // 1
        vector<int> t_in(n+1, 0), low(n+1, 0);
        int timer = 0;
        dfs(1, -1, timer, t_in, low, adj, is_bridge); // start from node 1


        // 2
        vector<int> node_component(n+1, -1);
        int component_num = 0;

        for (int i = 1; i <= n; i++) {
            if (node_component[i] != -1) continue; // visited

            queue<int> q;
            node_component[i] = component_num;
            q.push(i);
            while (!q.empty())
            {
                int u = q.front(); q.pop();

                for (auto [v, id] : adj[u]) {
                    if (is_bridge[id]) continue; // ignore
                    if (node_component[v] == -1) { // not visited
                        node_component[v] = component_num;
                        q.push(v);
                    }
                }
            }
            component_num++;
        }


        // 3
        vector<vector<pair<int,int>>> component_tree(component_num); // [][](component, bridge_id)
        for(int i = 1; i <= m; i++) {
            if(is_bridge[i]) {
                int u = node_component[U[i]], v = node_component[V[i]];
                component_tree[u].push_back({v, i});
                component_tree[v].push_back({u, i});
            }
        }


        // 4
        int start_comp = node_component[1], end_comp = node_component[n];
        vector<int> parent_node(component_num, -1), parent_edge(component_num, -1);
        queue<int> q; 
        q.push(start_comp);
        while (!q.empty()) {
            int u = q.front(); q.pop();

            if (u == end_comp) break;

            for (auto [v, id] : component_tree[u]) {
                if (parent_node[v] == -1) {
                    parent_node[v] = u;
                    parent_edge[v] = id;
                    q.push(v);
                }
            }
        }

        vector<int> essential_bridges;
        int back_trace = end_comp;
        while (back_trace != start_comp) {
            essential_bridges.push_back(parent_edge[back_trace]);
            back_trace = parent_node[back_trace];
        }
        
        
        // 5
        vector<int> dist(n+1, INF), closest_bridge(n+1, INF);
        queue<int> multi_q;
        for (int eb_id : essential_bridges) {
            int u = U[eb_id], v = V[eb_id];
            closest_bridge[u] = eb_id, closest_bridge[v] = eb_id; 
            dist[u] = 0, dist[v] = 0;
            multi_q.push(u); multi_q.push(v);
        }

        while (!multi_q.empty()) {
            int u = multi_q.front(); multi_q.pop();
            for (auto [v, id] : adj[u]) {
                if (dist[v] > dist[u] + 1 || (dist[v] == dist[u] + 1 && closest_bridge[v] > closest_bridge[u])) {
                    dist[v] = dist[u] + 1;
                    closest_bridge[v] = closest_bridge[u];
                    multi_q.push(v);
                }
            }
        }
        

        cin >> qq;
        while (qq--) {
            cin >> c;
            cout << ((closest_bridge[c] == INF) ? -1 : closest_bridge[c]) << "\n";
        }
    }
    
    return 0;
}