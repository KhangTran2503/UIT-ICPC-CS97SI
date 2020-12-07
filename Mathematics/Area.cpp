#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <stdlib.h>
using namespace std;
typedef long long ll;
int dx[] = {-1,0,1,-1,0,1,-1,0,1};
int dy[] = {-1,-1,-1,0,0,0,1,1,1};
string s;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--){
		ll S = 0;
		int curx = 0, cury = 0;
		int nxtx = 0, nxty = 0;
		cin >> s;
		for (int i =0; i < (int)s.size(); i++){
			int h = s[i] - '1';
			if (h == 4) break;
			nxtx = curx + dx[h];
			nxty = cury + dy[h];
			//cout << nxtx << ' ' << nxty << '\n';
			S += (ll)((ll)curx*nxty - (ll)nxtx*cury);
			curx = nxtx;
			cury = nxty;
		}
		S = (S >= 0) ? S : -S;
		cout << S/2 << ((S & 1) ? ".5\n" : "\n");
	}
	return 0;
}