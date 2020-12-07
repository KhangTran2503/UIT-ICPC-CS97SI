#include <stdio.h>
#include <math.h>
#include <iostream>
#define eps 1e-9
using namespace std;

typedef struct Point {
    double x, y;
} TPoint;

typedef struct Line {    // line: a*x + b*y + c = 0
    double a, b, c;
} TLine;

int equal(double x, double y) {
    if (fabs(x - y) < eps) {
        return 1;
    }
    return 0;
}


TLine bisector(TPoint p1, TPoint p2) {
    TLine line;
    if (equal(p1.x, p2.x)) {
        line.a = 0.0, line.b = 1.0, line.c = - (p1.y  + p2.y) / 2.0;
    } else if (equal(p1.y, p2.y)) {
        line.a = 1.0, line.b = 0.0, line.c = - (p1.x + p2.x) / 2.0;
    } else {
        double k = - (p2.x - p1.x) / (p2.y - p1.y);
        double cx = (p1.x + p2.x) / 2.0;
        double cy = (p1.y + p2.y) / 2.0;
        double b = cy - k * cx;
        line.a = k, line.b = -1, line.c = b;
    }
    return line;
}

TPoint ps[200];
int n = 0, ans = 1;


int count(TPoint c) {
    int i, ret = 0;
    for (i = 0; i < n; i++) {
        double dx = ps[i].x - c.x;
        double dy = ps[i].y - c.y;
        double d = sqrt(dx*dx + dy*dy);
        if (d > 2.5) continue; // the radius equals 2.5
        ret++;
    }
    return ret;
}

int main() {
    double x, y; int i, j;
    while (cin >> x >> y) {
        ps[n].x = x, ps[n].y = y;
        n++;
    }

    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            double dx = ps[j].x - ps[i].x;
            double dy = ps[j].y - ps[i].y;
            double dd = dx * dx + dy * dy;
            int tmp1, tmp2;
            if (dd > 25.0) continue;
            else if (equal(dd, 25.0)) {
                Point center;
                center.x = (ps[i].x + ps[j].x) / 2.0;
                center.y = (ps[i].y + ps[j].y) / 2.0;
                tmp1 = count(center);
            } else {
                Line line = bisector(ps[i], ps[j]);
                double d = sqrt(6.25 - dd / 4.0);
                double em = sqrt(line.a * line.a + line.b * line.b);
                double ex = line.b / em;
                double ey = -line.a / em;
                double cx = (ps[i].x + ps[j].x) / 2.0;
                double cy = (ps[i].y + ps[j].y) / 2.0;
                Point center;
                center.x = cx + d * ex;
                center.y = cy + d * ey;
                tmp1 = count(center);

                center.x = cx - d * ex;
                center.y = cx - d * ey;
                tmp2 = count(center);

                tmp1 = max(tmp1,tmp2);
            }
            ans = max(ans,tmp1);
        }
    }
    cout << ans;
    return 0;
}