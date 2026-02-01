// writen by mmd (fixed)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define WALL '#'

const ll INF = 1000000000000000000LL;

const int dx[4] = {-1, 1, 0, 0}; // UP , DOWN , LEFT, RIGHT
const int dy[4] = {0, 0, -1, 1};
const char directions[4] = {'U', 'D', 'L', 'R'};

int get_cost(char c);

ll construct_path(int **prev, ll start_i, ll start_j, ll end_i, ll end_j);

ll bfs_min_dist(char **grid, ll **dist, ll n, ll m, ll start_i, ll start_j, ll end_i, ll end_j);

ll dijkstra(char **grid, ll **cost, int **prev, ll n, ll m, ll start_i, ll start_j, ll end_i, ll end_j);

int main()
{
    ll n, m, start_i, start_j, end_i, end_j;
    cin >> n >> m;

    char **grid = new char *[n];
    ll **dist = new ll *[n];
    int **prev = new int *[n]; // prev[i][j] = 0, 1, 2, 3 : UP , DOWN , LEFT, RIGHT

    for (int i = 0; i < n; i++) {
        grid[i] = new char[m];
        dist[i] = new ll[m];
        prev[i] = new int[m];

        for (ll j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
                start_i = i, start_j = j;
            else if (grid[i][j] == 'E')
                end_i = i, end_j = j;
        }
    }

    ll min_dist = bfs_min_dist(grid, dist, n, m, start_i, start_j, end_i, end_j);
    cout << "Shortest path steps: " << min_dist << "\n";

    ll min_risk = dijkstra(grid, dist, prev, n, m, start_i, start_j, end_i, end_j);
    cout << "Damage of the least-risk path: " << min_risk << "\n";

    ll min_risk_dist = construct_path(prev, start_i, start_j, end_i, end_j);
    cout << "Length of the least-risk path: " << min_risk_dist << "\n";
    return 0;
}

int get_cost(char c) {
    if (c == '.') return 1;
    else if (c == '~') return 3;
    else if (c == '^') return 5;
    return 0; // for 'S' and 'E'
}

ll bfs_min_dist(char **grid, ll **dist, ll n, ll m, ll start_i, ll start_j, ll end_i, ll end_j) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dist[i][j] = INF;

    queue<pair<ll, ll>> q;

    dist[start_i][start_j] = 0;
    q.push({start_i, start_j});

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (x == end_i && y == end_j)
            return dist[x][y];

        for (int i = 0; i < 4; i++)
        {
            ll x_new = x + dx[i], y_new = y + dy[i];

            if (x_new < 0 || x_new >= n || y_new < 0 || y_new >= m)
                continue; // index range
            if (dist[x_new][y_new] != INF || grid[x_new][y_new] == WALL)
                continue; // visited or wall

            dist[x_new][y_new] = dist[x][y] + 1;
            q.push({x_new, y_new});
        }
    }
    return -1;
}

ll dijkstra(char **grid, ll **cost, int **prev, ll n, ll m, ll start_i, ll start_j, ll end_i, ll end_j) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cost[i][j] = INF;
            prev[i][j] = -1;
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq; // (cost, (x, y))

    cost[start_i][start_j] = 0;
    pq.push({0, {start_i, start_j}});

    while (!pq.empty())
    {
        auto [d, pos] = pq.top(); 
        pq.pop();
        auto [x, y] = pos;

        for (int i = 0; i < 4; i++)
        {
            ll x_new = x + dx[i], y_new = y + dy[i];

            if (x_new < 0 || x_new >= n || y_new < 0 || y_new >= m) continue; // index range
            if (grid[x_new][y_new] == WALL) continue; // wall

            if (d + get_cost(grid[x_new][y_new]) < cost[x_new][y_new]) {
                cost[x_new][y_new] = d + get_cost(grid[x_new][y_new]);
                prev[x_new][y_new] = i; // store direction
                pq.push({cost[x_new][y_new], {x_new, y_new}});
            }
        }
    }
    return cost[end_i][end_j];
}

ll construct_path(int **prev, ll start_i, ll start_j, ll end_i, ll end_j) {
    string path = "";
    ll x = end_i, y = end_j;

    while (!(x == start_i && y == start_j)) {
        int dir = prev[x][y];
        path += directions[dir];
        x -= dx[dir], y -= dy[dir];
    }
    // reverse(path.begin(), path.end());
    // cout << "Path: " << path << "\n";
    return path.size();
}