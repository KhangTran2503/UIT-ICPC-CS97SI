#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    map<string, vector<string>> sav;
    
    string s, t;
    while (cin >> s) {
        t = s;
        sort(t.begin(), t.end());
        sav[t].push_back(s);
    }
    for (map<string, vector<string>>::iterator it = sav.begin(); it != sav.end(); ++it) sort(it->second.begin(), it->second.end());
    
    vector<pair<int, string>> res;
    for (map<string, vector<string>>::iterator it = sav.begin(); it != sav.end(); ++it) res.push_back(make_pair(-(it->second.size()), it->second[0]));
    sort(res.begin(), res.end());
    
    for (int i = 0; i < 5 && i < (int) res.size(); ++i) {
        cout << "Group of size " << -res[i].first << ": ";
        t = res[i].second;
        sort(t.begin(), t.end());
        for (int j = 0; j < (int) sav[t].size(); ++j) if (!j || sav[t][j] != sav[t][j - 1]) cout << sav[t][j] << " ";
        cout << ".\n";
    }

    return 0;
}
