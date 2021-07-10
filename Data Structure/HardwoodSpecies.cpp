#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;
string s;
map<string,int> cnt;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int total_cnt = 0;
	while (getline(cin,s)){
		total_cnt++;
		cnt[s]++;
	} 

	for (map<string,int>::iterator it = cnt.begin(); it != cnt.end(); ++it)
		cout << it->first << ' ' << fixed << setprecision(4) << 100.0*((double)(it->second)/total_cnt) << '\n'; 
	return 0;
}