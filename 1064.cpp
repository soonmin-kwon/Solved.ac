#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<algorithm>
using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double M1 = 1111111;
    double M2 = 1111111;

    if (x1 != x2) M1 = abs(y2 - y1) / abs(x2 - x1);
    if (x2 != x3) M2 = abs(y3 - y2) / abs(x3 - x2);

    if (M1 == M2) {
        cout << -1 << endl;
        return 0;
    }

    double f = distance(x1, y1, x2, y2);
    double s = distance(x1, y1, x3, y3);
    double t = distance(x2, y2, x3, y3);

    double f1 = 2 * (f + s);
    double s1 = 2 * (f + t);
    double t1 = 2 * (s + t);

    cout << fixed;
    cout.precision(15);

    cout << max(f1, max(s1, t1)) - min(f1, min(s1, t1)) << "\n";

    return 0;
}