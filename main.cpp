#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double S(const double x, const double eps, int &n, double s);
double A(const double x, const int n, double a);

#ifndef UNIT_TEST
int main()
{
    double xp, xk, x, dx, eps, s;
    int n;

    s = 0;
    n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-----------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
         << setw(12) << "Arth(x)" << " |"
         << setw(12) << "S" << " |"
         << setw(7) << "n" << " |" << endl;
    cout << "-----------------------------------------------" << endl;

    x = xp;
    while (x <= xk + dx / 2)
    {
        s = S(x, eps, n, s);

        cout << "|" << setw(7) << setprecision(2) << x << " |"
             << setw(12) << setprecision(5) << atanh(x) << " |"
             << setw(12) << setprecision(5) << s << " |"
             << setw(7) << n << " |" << endl;

        x += dx;
    }
    cout << "-----------------------------------------------" << endl;

    return 0;
}
#endif

double S(const double x, const double eps, int &n, double s)
{
    double a;

    n = 0;
    a = x;
    s = a;
    do
    {
        n++;
        a = A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
    return s;
}

double A(const double x, const int n, double a)
{
    double R;

    R = x * x * (2 * n - 1) / (2 * n + 1);
    a *= R;
    return a;
}
