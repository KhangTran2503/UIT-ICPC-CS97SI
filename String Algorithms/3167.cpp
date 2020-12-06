#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int N = 1e5 + 7;
const int M = 1e9 + 7;
const int P = 3137;
const int K = 26;
int fp[N], gx[N], p2[N], cow[N], pat[N], res[N], pos[K];
int h4s[30][N];

int fpow(int b, int n) {
    int r = 1;
    while (n > 0) {
        if (n % 2 == 1) r = 1LL * r * b % M;
        b = 1LL * b * b % M;
        n /= 2;
    }
    return r;
}
int gcdex(int x) { return fpow(x, M - 2); }
void init() {
    fp[0] = 1;
    gx[0] = 1;
    for (int i = 1; i < N; ++i) {
        p2[i] = 1LL * i * i % M;
        fp[i] = 1LL * fp[i - 1] * P % M;
        gx[i] = gcdex(fp[i]);
    }
}
void to_string(string &a, int t){
    if (t == 0) return;
    to_string(a, t / 10);
    a += char(t % 10 + 48);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    init();

    int n, k, s;
    cin >> n >> k >> s;
    for (int i = 0; i < n; ++i) cin >> cow[i];
    for (int i = 0; i < k; ++i) cin >> pat[i];

    int h4sh = 0;
    for (int i = 0; i < k; ++i)
        h4sh = (1LL * p2[pat[i]] * fp[i] % M + h4sh) % M;

    fill(pos, pos + K, -1);
    for (int i = 0; i < k; ++i) pos[pat[i]] = i;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < K; ++j) {
            if (j == cow[i])
                h4s[j][i + 1] = (h4s[j][i] + fp[i]) % M;
            else
                h4s[j][i + 1] = h4s[j][i];
        }
    }

    int res_siz = 0, t, hval, cur;
    for (int i = 0; i + k <= n; ++i) {
        hval = 0, cur = 0;
        for (int j = 0; j < K; ++j) {
            t = pos[j];
            if (t == -1) continue;
            if (cow[i + t] <= cur) {
                hval = M;
                break;
            }
            cur = cow[i + t];

            hval = (1LL * (h4s[cur][i + k] + M - h4s[cur][i]) * gx[i] % M * p2[j] + hval) % M;
        }

        if (h4sh == hval) res[res_siz++] = i;
    }

    
    string ans = "";
    to_string(ans, res_siz);
    ans += "\n";
    for (int i = 0; i < res_siz; ++i) {
        to_string(ans, res[i] + 1);
        ans += "\n";
    }
    cout << ans;
    

    /*
    cout << res_siz << '\n';
    for (int i = 0; i < res_siz; ++i) cout << res[i] + 1 << '\n';
    */

    return 0;
}
