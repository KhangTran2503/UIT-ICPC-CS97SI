#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    srand(time(NULL));
    
    int n = 100000, k = 25000, s = 25;
    
    cout << n << " " << k << " " << s << '\n';
    for(int i=0;i<n;++i)cout << i * 7 % s + 1 << '\n';
    for(int i=0;i<k;++i)cout << i * 7 % s + 1 << '\n';
    
    return 0;
}
