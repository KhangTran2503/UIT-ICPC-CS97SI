#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 7;
const int M = 1e9 + 7;
const int P = 3137;
vector<int>fp(N), p2(N);

int fpow(int b, int n){
    int res = 1;
    while (n) {
        if (n & 1) res = 1LL * res * b % M;
        b = 1LL * b * b % M;
        n >>= 1;
    }
    return res;
}
int gcdex(int x){
    return fpow(x, M - 2);
}
void init(){
    for(int i=0;i<N;++i){
        fp[i] = fpow(P, i);
        p2[i] = i * i;
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    init();
    
    int n, k, s;
    cin >> n >> k >> s;
    vector<int> cow(n), pat(k);
    for(int i=0;i<n;++i) cin>>cow[i];
    for(int i=0;i<k;++i) cin>>pat[i];
    
    
    int h4sh = 0;
    for(int i=0;i<k;++i)h4sh = (1LL * p2[pat[i]] * fp[i] % M + h4sh) % M;
    
    vector<vector<int>> pos(30), has(30);
    
    for(int i=0;i<30;++i){
        pos[i].push_back(-1);
        has[i].push_back(0);
    }
    
    for(int i=0;i<n;++i){
        pos[cow[i]].push_back(i);
        has[cow[i]].push_back(has[cow[i]].back());
        has[cow[i]].back() = (has[cow[i]].back() + fp[i]) % M;
    }
    
    for(int i=0;i<30;++i){
        pos[i].push_back(n);
        has[i].push_back(pos[i].back());
    }
    
    vector<int>res;
    for(int i=0;i+k<=n;++i){
        int hval = 0, cur = 0;
        for(int j=0;j<30;++j){
            int l = lower_bound(pos[j].begin(), pos[j].end(), i) - pos[j].begin();
            int r = lower_bound(pos[j].begin(), pos[j].end(), i + k) - pos[j].begin();

            if (pos[j][l] >= i + k)continue;
            int t = pat[pos[j][l] - i];
            if (t < cur){
                hval = M;
                break;
            }
            cur = t;
            hval = (1LL * (has[j][r - 1] + M - has[j][l - 1]) % M * gcdex(fp[i]) % M * p2[t] % M + hval) % M;
        }
        
        if (h4sh == hval) res.push_back(i);
    }
    
    cout << res.size() << '\n';
    for(int i=0;i<(int)res.size();++i)cout<<res[i]+1<<'\n';
    
    return 0;
}
