#include <iostream>
using namespace std;

int reverse(int x){
	int rev = 0;
	while (x){
		rev = rev*10 + (x % 10);
		x /= 10;
	}
	return rev;
}

void solve(){
	int a, b;
	cin >> a >> b;
	cout << reverse(reverse(a) + reverse(b)) << '\n';
}


int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}