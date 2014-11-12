using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'


const long long MX = 601010;

int nodes;
int dfs(vector<vector<int>> &g, vector<int> &v, int node, int col) {
  if (v[node])
    return 0;

  nodes++;
  v[node] = true;
  int ans = (col == 0);
  for (int i = 0; i < g[node].size(); ++i)
    ans += dfs(g, v, g[node][i], col ^ 1);
  return ans;
}

int main() { ___

  int n;
  while (cin >> n) {
    vector<pair<long long, long long>> p(n);
    vector<vector<int>> g(n);
    unordered_map<long long, int> ht;
    for (int i = 0; i < n; ++i) {
      cin >> p[i].first >> p[i].second;
      ht[p[i].first * MX + p[i].second] = i;
    }

    for (int i = 0; i < n; ++i) {
      for (int dx = -5; dx < 6; ++dx) {
        for (int dy = -5; dy < 6; ++dy) {
          if (dx == 0 and dy == 0)
            continue;

          if (dx * dx + dy * dy <= 25) {
            long long x = p[i].first + dx;
            long long y = p[i].second + dy;

            if (ht.count(x * MX + y))
              g[i].push_back(ht[x * MX + y]);
          }
        }
      }
    }

    int ans = 0;
    vector<int> visited(n, 0);
    for (int i = 0; i < n; ++i)
      if (!visited[i]) {
        nodes = 0;
        int tmp = dfs(g, visited, i, 0);
        ans += min(tmp, nodes - tmp);
      }

    cout << ans << endl;
  }
  return 0;
}
