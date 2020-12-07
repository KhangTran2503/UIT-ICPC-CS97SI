#include <iostream>
#include <vector>
#include <set>
#include <bitset>
using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const int bas = 101063;

int p[N], invp[N], table[N][26];
int n, k, s, a[N], b[N];
bitset<26> ss;
vector<int> sub;
int target;
vector<int> ans;

long long power(long long a, long long b) {
    long long ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void init() {
    p[0] = 1;
    for (int i = 1; i < N; ++i) {
        p[i] = 1LL * p[i - 1] * bas % mod;
    }
    invp[N - 1] = power(p[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; --i) {
        invp[i] = 1LL * invp[i + 1] * bas % mod;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    init();
    cin >> n >> k >> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= s; ++j) {
            if (j == a[i]) {
                table[i][j] = p[i];
            } else {
                table[i][j] = 0;
            }
        }
        if (i) {
            for (int j = 1; j <= s; ++j) {
                table[i][j] = (table[i][j] + table[i - 1][j]) % mod;
            }
        }
    }    
    for (int i = 0; i < k; ++i) {
        cin >> b[i];
        ss[b[i]] = true;
    }
    for (int it = 1; it <= s; ++it) {
        if (ss[it] == false) {
            continue;
        }
        int tmp = 0;
        for (int j = 0; j < k; ++j) {
            if (b[j] == it) {
                tmp = (tmp + p[j]) % mod;
            }
        }
        sub.push_back(tmp);
    }
    target = 0;
    for (int i = 0; i < k; ++i) {
        target = (target + p[i]) % mod;
    }
    for (int i = 0; i < n - k + 1; ++i) {
        int j = i + k - 1;
        int cur = 1;
        int cnt = 0;
        int tmp = 0;
        for (int t = 0; t < (int) sub.size(); ++t) {
            while (cur <= s) {
                long long h = (i == 0 ? table[j][cur] : 1LL * (table[j][cur] - table[i - 1][cur] + mod) * invp[i] % mod);
                ++cur;
                if (h == sub[t]) {
                    ++cnt;
                    tmp = (tmp + h) % mod;
                    break;
                }
            }
        }
        if (cnt == (int) sub.size() && tmp == target) {
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < (int) ans.size(); ++i) {
        cout << ans[i] << "\n";
    }
    return 0;
}
