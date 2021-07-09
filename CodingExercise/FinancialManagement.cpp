#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	double sum = 0;
	for (int i = 0; i < 12; i++){
		double x;
		cin >> x;
		sum += x;
	}

	cout << '$' << sum/12;

	return 0;
}