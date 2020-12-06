#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int josephus(int n, int k) {
    int res = 0;
    for (int i = 1; i <= n; ++i)
      res = (res + k) % i;
    return res + 1;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    
    string t, s = "";
    while (getline(cin, t)) {
        s += t;
    }
    int k = josephus(s.size(), 1999) - 1;
    
    if (s[k] == '?') cout << "Yes\n";
    else if (s[k] == ' ') cout << "No\n";
    else cout << "No comments\n";
    cout << "\n";
    
    return 0;
}
