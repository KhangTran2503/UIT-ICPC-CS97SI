#include <iostream>
#include <math.h>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
ll n;


int main(){
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--){
		cin >> n;
		ll ans = 0;
		while (n){
			ans += (n/5);
			n /= 5;
		}
		cout << ans << '\n';
	}
	return 0;
}