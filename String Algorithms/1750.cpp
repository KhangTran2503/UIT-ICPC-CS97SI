#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s[2];

bool check(const string& s) {
    for (int i = 0; i < (int) s.size(); ++i) {
        if (s[i] != ' ') {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cur = 0;
    int pre = 1;
    int cnt = 0;
    cin >> s[cur];
    cout << s[cur] << "\n";
    while (cin >> s[pre]) {
        cur ^= 1;
        pre ^= 1;
        if (!check(s[cur])) {
            break;
        }    
        int tmp = 0;
        int lim = min(s[cur].size(), s[pre].size());
        for (int i = 0; i < lim && s[cur][i] == s[pre][i]; ++i) {
            ++tmp;
        }
        if (tmp > cnt) {
            cnt++;
        } else {
            cnt = min(cnt, tmp);
        }
        for (int i = 0; i < cnt; ++i) {
            cout << " ";
        }
        cout << s[cur] << "\n";
    }
    return 0;
}