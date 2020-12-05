#include <iostream>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <bitset>
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int Maxn = int(1e6) + 5;
vector<int> prime;
bitset<Maxn> is_prime;

void init(){
	for (int i = 2; i < Maxn; i++)
		if (!is_prime.test(i)){
			if (i > 2) prime.push_back(i);
			if (i <= 1000) for (int j = i*i; j < Maxn; j += i) is_prime.set(j);
		}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	init();
	while (1){
		int n;
		cin >> n;
		if (n == 0) break;
		if (n > 4){
			bool found = false;
			for (int i = 0; i < (int)prime.size(); i++){
				int x = prime[i];
				int y = n - x;
				if ((y & 1) && !is_prime.test(y)){
					cout << n << " = " << x << " + " << y << '\n';
					found = true;
					break;
				}
			}
			if (!found) cout << "Goldbach's conjecture is wrong.\n";
		}
		else cout << "Goldbach's conjecture is wrong.\n";
	}
	return 0;
}