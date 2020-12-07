#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m;

bool solve(){
	cin >> n >> m;
	if (n == -1 && m == -1) return false;
	ll break_point = 0;
	for (ll i = 1; i <= n; i++)
		if (i*(i - 1LL)/2LL >= m){
			break_point = i;
			break;
		}
	
	for (ll i = 1; i <= n - break_point; i++) cout << i << ' ';
	ll miss = break_point*(break_point - 1)/2 - m;
	ll i = n; 
	cout << n - miss << ' ';
	for (i = n; i >= n - miss + 1; i--) cout << i << ' ';
	i--;
	for (; i >= n - break_point + 1; i--) cout << i << ' ';
	cout << '\n';
	
	return true;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (solve()){};
	return 0;
}
