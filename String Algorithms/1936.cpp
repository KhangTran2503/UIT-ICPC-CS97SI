#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    string s, t;
    while (cin >> s >> t) {
        int n = s.size(), m = t.size(), i = 0, j = 0;
        for(; i < n && j < m; ++j) if (s[i] == t[j]) i++;
        cout << (i == n ? "Yes" : "No") << '\n';
    }

    return 0;
}
