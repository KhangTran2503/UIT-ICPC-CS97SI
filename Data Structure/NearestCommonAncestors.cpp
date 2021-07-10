#include <iostream>
#include <vector>
using namespace std;
int n;
vector<vector<int>> g;
vector<int> visited;
vector<int> par;
vector<int> depth;

void get_depth(int u){
	// root
	if (u == 0) return;
	if (visited[u]) return;

	visited[u] = true;
	get_depth(par[u]);
	depth[u] = depth[par[u]] + 1;
}

// O(n)
int lca(int u,int v){
	// depth[u] < depth[v]
	if (depth[u] > depth[v]) swap(u,v);

	while (depth[v] > depth[u]) v = par[v];

	while (u != v){
		u = par[u];
		v = par[v];
	}
	return  u;
}

void solve(){
	cin >> n;
	
	//init
	visited.assign(n + 1,0);
	par.assign(n + 1,0);
	depth.assign(n + 1,0);

	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		par[v] = u;
	}

	int ux, vx;
	cin >> ux >> vx;

	for (int i = 1; i <= n; i++) get_depth(i);

	cout << lca(ux,vx) << '\n';

}


int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;	
}