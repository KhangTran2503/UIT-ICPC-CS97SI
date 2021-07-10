#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	double R;
	int n;
	while (cin >> R >> n){
		cout << pow(R,n*1.0) << '\n';
	}
	return 0;
}