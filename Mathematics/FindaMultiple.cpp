#include <iostream>
#include <vector>
using namespace std;
int N;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	vector<int> modpos(N,-1);
	vector<int> a(N + 1);

	modpos[0] = 0;
	int l = 0;
	int r = -1;

	int sum = 0;
	for (int i = 1; i <= N; i++){
		cin >> a[i];

		sum = (sum + a[i]) % N;
		
		if (modpos[sum] >= 0){
			l = modpos[sum];
			r = i;
			break;
		}
		modpos[sum] = i;
	}

	if (r == -1) cout << 0;
	else{
		cout << r - l << '\n';
		for (int i = l + 1; i <= r; i++) cout << a[i] << '\n';
	}
	return 0;
}