#include <iostream>
#include <math.h>
using namespace std;
int N;

// u , u + 1, u + 2,.. , v = v*(v + 1)/2 - (u -1)*u/2 = N
//
// => 2N = (v^2 - u^2) + (v + u) = (v + u)(v - u + 1)  
// => 2N  = s2*s1

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	N *= 2;

	int way = 0;
	for (int i = 1; i*i <= N; i++)
		if (N % i == 0){
			// s1 < s2
			int s1 = i;
			int s2 = N/i;

			if ((s1 - 1 + s2) % 2 == 0) way++;
		}

	cout << way;
	return 0;
}