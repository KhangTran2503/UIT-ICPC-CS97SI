#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n, m;
vector<string> s;
vector<int> measure;
vector<int> index;

int dis(const string& x){
	int len = x.size();
	if (len == 1) return 0;

	int sumdiff = 0;
	for (int i = 0; i < len - 1; i++)
		for (int j = i + 1; j < len; j++)
			if (x[i] > x[j]) sumdiff++;
	return sumdiff;
}


bool cmp(int u,int v){
	return measure[u] < measure[v];
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n;

	s.resize(n);
	for (int i = 0; i < n; i++) cin >> s[i];

	// O(N*M^2)
	measure.resize(n);
	for (int i = 0; i < n; i++) measure[i] = dis(s[i]);

	//
	index.resize(n);
	for (int i = 0; i < n; i++) index[i] = i;

	sort(index.begin(),index.end(),cmp);

	for (int i = 0; i < n; i++) cout << s[index[i]] << '\n';
	return 0;
}