#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    string s;

    vector<int> z, res;
    
    while (cin >> s){
        int n = s.size();

        res.clear();
        z = z_function(s);
            
        z[0] = n;
        
        for(int i=0;i<n;++i) if(i + z[i] == n)res.push_back(z[i]);
        
        reverse(res.begin(), res.end());
        for(int i=0;i<int(res.size());++i) cout << res[i] << " \n"[&res[i] == &res.back()];
    }

    return 0;
}
