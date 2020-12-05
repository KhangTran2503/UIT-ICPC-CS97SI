#include <iostream>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
double X1, Y1, X2, Y2, X3, Y3;

double dis(double u1,double v1,double u2,double v2){
	return sqrt((u1 - u2)*(u1 - u2) + (v1 - v2)*(v1 - v2));
}

// a/sina = 2R

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	while (cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3){
		//cout <<  X1 << ' ' << Y1 << ' ' << X2 << ' ' << Y2 << '\n';
		double AB = dis(X1,Y1,X2,Y2); // c
		double AC = dis(X1,Y1,X3,Y3); // b
		double BC = dis(X2,Y2,X3,Y3); // a
		double cosa = (AB*AB + AC*AC - BC*BC)/(2*AB*AC);
		double sina = sqrt(1 - cosa*cosa);
		double d = BC/sina;
		double p = d*pi;
		cout << fixed << setprecision(2) << p << '\n';
	}
	return 0;
}