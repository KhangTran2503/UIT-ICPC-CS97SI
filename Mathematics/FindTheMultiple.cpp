#include <iostream>
#include <queue>
#include <string>
using namespace std;

string bfs(int x){
	if (x == 1) return "1";

	vector<string> dp(x);
	queue<int> q;

	q.push(1);
	dp[1] = "1";
	while (!q.empty()){
		int rem = q.front();
		q.pop();
		if (rem == 0) return dp[rem];
	

		for (int d = 0; d < 2; d++){
			int new_rem = (rem*10 + d) % x;
			if (dp[new_rem].empty()){
				q.push(new_rem);
				dp[new_rem] = dp[rem] + char('0' + d);
			}
		}
	}
	// assert(false);
	return "";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	while (true){
		cin >> n;
		if (n == 0) break;
		cout << bfs(n) << '\n';
	}
	return 0;
}