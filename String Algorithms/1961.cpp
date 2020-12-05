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
    
    int n;
    string s;
    
    int T = 0;
    while(1){
        T++;
        cin >> n;
        if(n == 0)break;
        cin >> s;
        
        vector<int> z = z_function(s);
        vector<int>res(n + 1, n + 7);
        
        for(int i=0;i++<n;)
            for(int j=i;j<n;j+=i)
                if(z[j]>=i)
                    res[j+i]=min(res[j+i], i);
                else break;
        
        cout << "Test case #" << T << "\n";
        //cout << s << '\n';
        for(int i=1;i++<n;)if(res[i] != n + 7)cout<< i << " " << i / res[i] << '\n';
        cout << '\n';
    }

    return 0;
}
