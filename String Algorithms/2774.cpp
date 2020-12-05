#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct SA {
    string s;
    int n, lgn;
    vector<int> suf, lcp, rank;
    vector<vector<int> > st;
    SA(string const& str, bool _lcp = true, bool _st = true) {
        const int alphabet = 128;
        s = str + str;
        n = s.size() >> 1;
        lgn = 17;
        suf.assign(n, 0);
        vector<int> c(n), cnt(max(alphabet, n), 0);
        for (int i = 0; i < n; i++) cnt[s[i]]++;
        for (int i = 1; i < alphabet; i++) cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; i++) suf[--cnt[s[i]]] = i;
        c[suf[0]] = 0;
        int classes = 1;
        for (int i = 1; i < n; i++) {
            if (s[suf[i]] != s[suf[i - 1]]) classes++;
            c[suf[i]] = classes - 1;
        }
        vector<int> pn(n), cn(n);
        for (int h = 1; h < n; h <<= 1) {
            for (int i = 0; i < n; i++) {
                pn[i] = suf[i] - h;
                if (pn[i] < 0) pn[i] += n;
            }
            fill(cnt.begin(), cnt.begin() + classes, 0);
            for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
            for (int i = 1; i < classes; i++) cnt[i] += cnt[i - 1];
            for (int i = n; i--;) suf[--cnt[c[pn[i]]]] = pn[i];
            cn[suf[0]] = 0;
            classes = 1;
            for (int i = 1; i < n; i++) {
                pair<int,int> cur = make_pair(c[suf[i]], c[(suf[i] + h) % n]);
                pair<int,int> prev = make_pair(c[suf[i - 1]], c[(suf[i - 1] + h) % n]);
                if (cur != prev) ++classes;
                cn[suf[i]] = classes - 1;
            }
            c.swap(cn);
        }

        if (_lcp) init_lcp();
    }
    void init_lcp() {
        int k = 0;
        rank.assign(n, 0);
        lcp.assign(n, 0);
        for (int i = 0; i < n; ++i) rank[suf[i]] = i;
        for (int i = 0; i < n; ++i) {
            int j = suf[(rank[i] + 1) % n];
            while (i + k < n && j + k < n && s[i + k] == s[j + k]) ++k;
            lcp[rank[i]] = k;
            if (k) --k;
        }
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    string s, t;
    cin >> s >> t;
    
    string st = s + '0' + t + '1';
    
    SA a(st, true, false);
    
    int n = s.size(), m = t.size();
    int res = 0;
    
    for(int i=1;i<a.n;++i){
        if(a.suf[i-1] < n && a.suf[i] > n && a.suf[i] < n + 1 + m) res = max(res, a.lcp[i-1]);
        if(a.suf[i] < n && a.suf[i-1] > n && a.suf[i-1] < n + 1 + m) res = max(res, a.lcp[i-1]);
    }
    
    cout << res << '\n';

    return 0;
}
