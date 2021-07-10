#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int cnt[26];
string s;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 0; i < 4; i++){
		getline(cin,s);
		for (int i = 0; i < s.size(); i++)
			if (s[i] >= 'A' && s[i] <= 'Z') cnt[s[i] - 'A']++;
	}

	int maxcnt = *max_element(cnt,cnt + 26);

	for (int i = 1; i <= maxcnt; i++){
		for (int j = 0; j < 26; j++) 
			if (i <= maxcnt - cnt[j]) cout << "  ";
			else cout << "* ";
		cout << '\n';
	}
	for (int i = 0; i < 26; i++) cout << char('A' + i) << ' ';
	return 0;
}