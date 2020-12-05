#include <iostream>
#include <math.h>
#include <algorithm>
#include <iomanip>
using namespace std;
const double pi = acos(-1.0);

double R, n;

void solve(int t){
	cin >> R >> n;
	double sina = sin(pi/n);
	double r = (R*sina)/(1 + sina);
	cout << "Scenario #" << t << ":\n";
	cout << fixed << setprecision(3) << r << '\n';
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) solve(i);
	return 0;
}