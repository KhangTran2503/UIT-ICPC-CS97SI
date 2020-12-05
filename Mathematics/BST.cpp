#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--){
		ll n;
		cin >> n;
		ll gap = 1;
		while (gap <= n) gap <<= 1;
		ll lef = 0;
		ll len = gap >> 1;
		for (; len >= 1; len >>= 1){
			while (lef + len <= n) lef += len;
			if (lef == n) break;
		}
		cout << n - len + 1 << ' ' << n + len - 1 << '\n';
		//cout << gap << ' ' << lef << ' ' << len << '\n';
		
	}
	return 0;
}