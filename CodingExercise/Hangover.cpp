#include <iostream>
using namespace std;

int solve(double x){
	double sum = 0.0;
	int i = 1;
	do{
		i++;
		sum += 1.0/i;
	}
	while (sum < x);
	return i - 1;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

	while (true){
		double x;
		cin >> x;
		if (x == 0.0) break;
		cout << solve(x) << " card(s)\n";
	}
	return 0;
}